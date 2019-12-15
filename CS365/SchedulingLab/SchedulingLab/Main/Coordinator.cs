using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public class Coordinator
    {
        private JobQueue[] _jobQueues = new JobQueue[7];
        private int _clock;
        private int _ioCompleteChance = 4;
        private int _ioRequestChance = 10;
        private string _jobInputFileName = "scheduling_data.txt";
        private static DateTimeOffset dto = new DateTimeOffset();
        private static long _randSeed = dto.ToUnixTimeSeconds();
        private Random _random = new Random((int)(_randSeed % (int.MaxValue - 1)));
        private IScheduler _scheduler;
        private SchedulerType _schedulerType = SchedulerType.NonAggressive;
        private int _seed = 1;
        private bool IoComplete() => _random.Next() % _ioCompleteChance == 0 ? true : false;
        private bool IoRequest() => _random.Next() % _ioRequestChance == 0 ? true : false;

        private void ParseCommandLineArguments(string[] args)
        {
            if (args.Contains("-A"))
            {
                _schedulerType = SchedulerType.Aggresive;
            }
            else if (args.Contains("-S"))
            {
                _schedulerType = SchedulerType.ShortestJobFirst;
            }
            else
            {
                _schedulerType = SchedulerType.NonAggressive;
            }
            if (args.Contains("-s"))
            {
                _seed = Convert.ToInt32(args[Array.IndexOf(args, "-s") + 1]);
            }
            if (args.Contains("-r"))
            {
                _ioRequestChance = Convert.ToInt32(args[Array.IndexOf(args, "-r") + 1]);
            }
            if (args.Contains("-c"))
            {
                _ioCompleteChance = Convert.ToInt32(args[Array.IndexOf(args, "-c") + 1]);
            }
            for (var i = 0; i < _jobQueues.Length; i++)
            {
                var s = $"-{i}";
                if (args.Contains(s))
                {
                    _jobQueues[i].TimeSlice = Convert.ToInt32(args[Array.IndexOf(args, s) + 1]);
                }
            }
        }

        private void PrintJobStatistics(IJob job)
        {
            int id = job.Id;
            int run = job.TotalTimeInReadyToRunState();
            int IO = job.TotalTimeInIOState();
            int total = job.TotalTimeInSystem();
            string jobId = $"| {id}{ConsoleFormatter.WhiteSpaceFill($"{id}", 12)} ";
            string jobRun = $"| {run}{ConsoleFormatter.WhiteSpaceFill($"{run}", 12)} ";
            string jobIO = $"| {IO}{ConsoleFormatter.WhiteSpaceFill($"{IO}", 12)} ";
            string jobTotal = $"| {total}{ConsoleFormatter.WhiteSpaceFill($"{total}", 12)} |";
            Console.WriteLine($"{jobId}{jobRun}{jobIO}{jobTotal}");
        }
        private void PrintHeader()
        {
            // Width of each column is 14, including the 1 space of buffer on either side.
            Console.WriteLine("+--------------+--------------+--------------+--------------+");
            Console.WriteLine("| Job number   | Total time   | Total time   | Total time   |");
            Console.WriteLine("|              | in ready to  | in sleeping  | in system    |");
            Console.WriteLine("|              | run state    | on I/O state |              |");
            Console.WriteLine("+--------------+--------------+--------------+--------------+");
        }

        private JobQueue[] Setup(SchedulerType type)
        {
            var data = File.ReadAllLines($"../../../../{_jobInputFileName}");
            for (var i = 0; i < data.Length; i++)
            {
                var temp = data[i].Split(':');
                IJob job;
                if (type == SchedulerType.ShortestJobFirst)
                {
                    job = new ShortestJob();
                    job.Id = Convert.ToInt32(temp[0]);
                    job.ArrivalTime = Convert.ToInt32(temp[1]);
                    job.ServiceTime = Convert.ToInt32(temp[2]);
                    job.Priority = Convert.ToInt32(temp[3]);
                    job.JobState = JobState.Ready;
                    _jobQueues[0].Enqueue(job);
                }
                else
                {
                    job = new PriorityJob();
                    job.Id = Convert.ToInt32(temp[0]);
                    job.ArrivalTime = Convert.ToInt32(temp[1]);
                    job.ServiceTime = Convert.ToInt32(temp[2]);
                    job.Priority = Convert.ToInt32(temp[3]);
                    job.JobState = JobState.Ready;
                    _jobQueues[job.Priority].Enqueue(job);
                }
            }
            return _jobQueues;
        }

        public void Run(string[] args)
        {
            for (var i = 0; i < _jobQueues.Length; i++)
            {
                _jobQueues[i] = new JobQueue();
                _jobQueues[i].TimeSlice = Convert.ToInt32(Math.Pow(2, i));
            }
            ParseCommandLineArguments(args);
            JobQueue[] jobQueues = Setup(_schedulerType);
            Queue<IJob> IOQueue = new Queue<IJob>();
            _scheduler = SchedulerFactory.GetScheduler(jobQueues, _schedulerType);
            _clock = 0;
            PrintHeader();
            while(_scheduler.SysetmHasJobsToRun())
            {
                var currentJob = _scheduler.TakeNext();
                // Main loop.
                while(true)
                {
                    currentJob.JobState = JobState.Ready;
                    for (var i = 0; i < IOQueue.Count; i++)
                    {
                        if (IoComplete())
                        {
                            _scheduler.Schedule(IOQueue.Dequeue());
                        }
                    }
                    if (currentJob.QuantaRemaining == 1)
                    {
                        currentJob.JobState = JobState.Exited;
                    }
                    else if (jobQueues[currentJob.Priority].PeekNext().Priority < currentJob.Priority)
                    {
                        currentJob.JobState = JobState.Preempted;
                    }
                    else if (currentJob.QuantaRemaining != 1)
                    {
                        if (IoRequest())
                        {
                            currentJob.JobState = JobState.Sleeping;
                        }
                        else if (currentJob.QuantaRemaining > jobQueues[currentJob.Priority].TimeSlice)
                        {
                            currentJob.JobState = JobState.Swapped;
                        }
                    }
                    _clock++;
                    currentJob.UpdateTimes(_clock);
                    currentJob.QuantaRemaining++;
                    PrintJobStatistics(currentJob);
                    if (currentJob.JobState == JobState.Swapped)
                    {
                        _scheduler.Reschedule(currentJob);
                        break;
                    }
                }
            }
            ConsoleFormatter.PrintColumnedLine(4, 14);
        }
    }
}

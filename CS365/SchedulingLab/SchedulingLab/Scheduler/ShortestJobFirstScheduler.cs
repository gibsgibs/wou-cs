using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    class ShortestJobFirstScheduler : IScheduler
    {
        public SchedulerType SchedulerType { get; set; } = SchedulerType.ShortestJobFirst;
        public IJobQueue[] JobQueues { get; set; }

        public IJob PeekNext() => JobQueues[0].PeekNext();

        public void Reschedule(IJob job)
        {
            job.Priority = job.Priority == 0 ? 0 : job.Priority - 1;
            job.JobState = JobState.Ready;
            Schedule(job);
        }

        public void Schedule(IJob job)
        {
            JobQueues[0].Enqueue(job);
        }

        public bool SysetmHasJobsToRun() => !JobQueues[0].IsEmpty();

        public IJob TakeNext() => JobQueues[0].Dequeue();
    }
}

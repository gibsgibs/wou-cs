using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public abstract class PreemptiveScheduler : IScheduler
    {
        public SchedulerType SchedulerType { get; set; }
        public IJobQueue[] JobQueues { get; set; }

        public IJob PeekNext() => JobQueues.Where(jq => !jq.IsEmpty()).FirstOrDefault().PeekNext();

        public abstract void Reschedule(IJob job);

        public void Schedule(IJob job)
        {
            JobQueues[job.Priority].Enqueue(job);
        }

        public bool SysetmHasJobsToRun() => JobQueues.Any(jq => !jq.IsEmpty());

        public IJob TakeNext() => JobQueues.Where(jq => !jq.IsEmpty()).FirstOrDefault().Dequeue();
    }
}

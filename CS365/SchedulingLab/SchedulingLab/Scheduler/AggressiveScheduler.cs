using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public class AggressiveScheduler : PreemptiveScheduler
    {
        public new SchedulerType SchedulerType { get; set; } = SchedulerType.Aggresive;
        // Should fix this method later because it is not quite right.
        public override void Reschedule(IJob job)
        {
            job.Priority = job.Priority == 0 ? 0 : job.Priority - 1;
            job.JobState = JobState.Ready;
            Schedule(job);
        }
    }
}

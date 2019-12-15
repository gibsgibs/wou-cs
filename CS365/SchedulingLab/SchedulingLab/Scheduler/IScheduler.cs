using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public interface IScheduler
    {
        SchedulerType SchedulerType { get; set; }
        IJobQueue[] JobQueues { get; set; }
        IJob PeekNext();
        void Reschedule(IJob job);
        void Schedule(IJob job);
        bool SysetmHasJobsToRun();
        IJob TakeNext();
    }
}

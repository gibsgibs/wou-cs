using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    static class SchedulerFactory
    {
        public static IScheduler GetScheduler(JobQueue[] jobQueues, SchedulerType type)
        {
            IScheduler scheduler;
            if (type == SchedulerType.ShortestJobFirst)
            {
                scheduler = new ShortestJobFirstScheduler();
                scheduler.JobQueues = jobQueues;
            }
            else if (type == SchedulerType.NonAggressive)
            {
                scheduler = new NonAggressiveScheduler();
                scheduler.JobQueues = jobQueues;
            }
            else
            {
                scheduler = new AggressiveScheduler();
                scheduler.JobQueues = jobQueues;
            }
            return scheduler;
        }
    }
}

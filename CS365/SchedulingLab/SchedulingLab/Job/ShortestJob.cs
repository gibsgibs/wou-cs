using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    class ShortestJob : IJob
    {
        public int TypeOfJob { get; set; } = 1;
        public int LastUpdatedTime { get; set; } = 0;
        public int TimeInReady { get; set; } = 0;
        public int TimeInIO { get; set; } = 0;
        public int TimeElsewhere { get; set; } = 0;
        public int ArrivalTime { get; set; }
        public int Id { get; set; }
        public bool IsIoComplete { get; set; }
        public JobState JobState { get; set; }
        public int Priority { get; set; }
        public int QuantaRemaining { get; set; }
        public int ServiceTime { get; set; }

        public int CompareTo(IJob other) => ServiceTime < other.ServiceTime ? -1 : ServiceTime == other.ServiceTime ? 0 : 1;

        public void UpdateTimes(int clock)
        {
            if (LastUpdatedTime < clock)
            {
                LastUpdatedTime = clock;
                switch(JobState)
                {
                    case JobState.Ready:
                        TimeInReady++;
                        break;
                    case JobState.IO:
                        TimeInIO++;
                        break;
                    default:
                        TimeElsewhere++;
                        break;
                }
            }
        }

        public int TotalTimeInReadyToRunState() => TimeInReady;

        public int TotalTimeInIOState() => TimeInIO;

        public int TotalTimeInSystem() => TimeInReady + TimeInIO + TimeElsewhere;
    }
}
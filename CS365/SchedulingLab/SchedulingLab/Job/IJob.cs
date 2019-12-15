using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public interface IJob : IComparable<IJob>
    {
        int TypeOfJob { get; set; }
        int LastUpdatedTime { get; set; }
        int TimeInReady { get; set; }
        int TimeInIO { get; set; }
        int TimeElsewhere { get; set; }
        int ArrivalTime { get; set; }
        int Id { get; set; }
        bool IsIoComplete { get; set; }
        JobState JobState { get; set; }
        int Priority { get; set; }
        int QuantaRemaining { get; set; }
        int ServiceTime { get; set; }
        void UpdateTimes(int clock);
        int TotalTimeInReadyToRunState();
        int TotalTimeInIOState();
        int TotalTimeInSystem();
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public interface IJobQueue
    {
        int Id { get; set; }
        IJob Dequeue();
        void Enqueue(IJob job);
        bool IsEmpty();
        IJob PeekNext();
    }
}

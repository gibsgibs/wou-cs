using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public class JobQueue : IJobQueue
    {
        private PriorityQueue _queue = new PriorityQueue();

        public int Id { get; set; }
        public int TimeSlice { get; set; }

        public IJob Dequeue() => !_queue.IsEmpty() ? _queue.Dequeue() : null;

        public void Enqueue(IJob job) => _queue.Enqueue(job);

        public bool IsEmpty() => _queue.IsEmpty();

        public IJob PeekNext() => _queue.PeekNext();
    }
}
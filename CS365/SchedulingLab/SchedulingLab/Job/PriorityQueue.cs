using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    public class PriorityQueue : IJobQueue
    {
        public int Id { get; set; }
        
        private IList<IJob> _data = new List<IJob>();

        public IJob Dequeue()
        {
            if (_data.Count < 1) throw new InvalidOperationException("Queue is empty");
            var result = _data[0];
            _data.RemoveAt(0);
            return result;
        }

        public void Enqueue(IJob job)
        {
            _data.Add(job);
            if (job.TypeOfJob == 0) _data = _data.OrderBy(pj => pj.Priority).ToList();
            else _data = _data.OrderBy(sjf => sjf.ServiceTime).ToList();
        }

        public bool IsEmpty() => _data.Count == 0;

        public IJob PeekNext()
        {
            if (_data.Count < 1) throw new InvalidOperationException("Queue is empty");
            IJob result = _data[0];
            return result;
        }
    }
}

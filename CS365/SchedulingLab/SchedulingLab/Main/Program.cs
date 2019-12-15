using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchedulingLab
{
    class Program
    {
        static void Main(string[] args)
        {
            Coordinator coordinator = new Coordinator();
            coordinator.Run(args);
            Console.Read();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;
using System.Collections.Concurrent;


namespace lab04
{
    class FoodCart
    {
        // Fields.
        private double _totalWaitingTime = 0;
        private int _lengthOfSimulation;
        private int _meanInterArrivalTime;
        private int _meanServiceTime;
        private static int _totalNumberOfCustomers = 0;
        private static int _numberOfcustomersAtCart = 0;
        private RandomInt _randomInt = new RandomInt();
        private Stopwatch _startTime = new Stopwatch();
        private static Semaphore _workers;
        private static BlockingCollection<Thread> _customers = new BlockingCollection<Thread>();
        private static Mutex _mutex = new Mutex();

        // Methods.
        public FoodCart(int numberOfWorkers, int meanInterArrivalTime, int meanServiceTime, int lengthOfSimulation)
        {
            _lengthOfSimulation = lengthOfSimulation;
            _meanInterArrivalTime = meanInterArrivalTime;
            _meanServiceTime = meanServiceTime;
            _workers = new Semaphore(numberOfWorkers, numberOfWorkers);
        }

        private int ArrivalTime()
        {
            return _randomInt.Get(_meanInterArrivalTime / 10) * 1000;
        }

        // Pretty sure this one is correctly implemented.
        public void CreateCustomerProcesses()
        {
            while((int)_startTime.Elapsed.TotalSeconds * 10 < _lengthOfSimulation)
            {
                Thread.Sleep(ArrivalTime());
                if((int)_startTime.Elapsed.TotalSeconds * 10 < _lengthOfSimulation)
                {
                    var thread = new Thread(CustomerProcess);
                    thread.Start();
                    _customers.Add(thread);
                    _mutex.WaitOne();
                    _totalNumberOfCustomers++;
                    _mutex.ReleaseMutex();
                }
            }
        }

        public void CustomerProcess()
        {
            _mutex.WaitOne();
            _numberOfcustomersAtCart++;
            _mutex.ReleaseMutex();
            var currentCustomer = _totalNumberOfCustomers;
            var arrivalTime = (int)_startTime.Elapsed.TotalSeconds;
            Console.WriteLine($"Customer {currentCustomer} arrived at {arrivalTime}.");
            _workers.WaitOne();
            var serviceTime = (int)_startTime.Elapsed.TotalSeconds;
            Console.WriteLine($"Customer {currentCustomer} is starting to be served at {serviceTime}.");
            _totalWaitingTime += serviceTime;
            Thread.Sleep(_randomInt.Get(_meanServiceTime / 10) * 1000);
            Console.WriteLine($"Customer {currentCustomer} is leaving at {(int)_startTime.Elapsed.TotalSeconds}.");
            _workers.Release();
            _mutex.WaitOne();
            _numberOfcustomersAtCart--;
            _mutex.ReleaseMutex();
        }
        
        public void Run()
        {
            // Don't walk.
            _startTime.Start();
            CreateCustomerProcesses();
            _startTime.Stop();
            while (_numberOfcustomersAtCart != 0) { }
            Console.WriteLine($"Average waiting time was {_totalWaitingTime / _totalNumberOfCustomers} for {_totalNumberOfCustomers} customers.");
        }
    }
}
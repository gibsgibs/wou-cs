using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab04
{
    class RandomInt
    {
        private readonly Random Random = new Random();

        public int Get(int mean)
        { 
            var randomNumber = (int)(0.5 - mean * Math.Log(Random.NextDouble()));
            if (randomNumber == 0)
            {
                randomNumber = 1;
            }
            else if(randomNumber > (5 * mean))
            {
                randomNumber = 5 * mean;
            }
            
            return randomNumber;
        }
    }
}
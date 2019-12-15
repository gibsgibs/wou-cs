using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab04
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                throw new Exception("\n~ There must be 4 arguments used ~\n");
            }
            else
            {
                bool arg1IsValid = int.TryParse(args[0], out int arg1);
                bool arg2IsValid = int.TryParse(args[1], out int arg2);
                bool arg3IsValid = int.TryParse(args[2], out int arg3);
                bool arg4IsValid = int.TryParse(args[3], out int arg4);
                if (arg1IsValid && arg2IsValid && arg3IsValid && arg4IsValid)
                {
                    if (arg2 % 10 == 0 && arg3 % 10 == 0 && arg4 % 10 == 0)
                    {
                        FoodCart foodCart = new FoodCart(arg1, arg2, arg3, arg4);
                        foodCart.Run();
                    }
                    else
                    {
                        throw new Exception("\n~ Arguments 2, 3 and 4 must be multiples of 10 ~\n");
                    }
                }
                else
                {
                    throw new Exception("\n~ All arguments must be integer numbers ~\n");
                }
            }
        }
    }
}
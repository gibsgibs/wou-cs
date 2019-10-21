///Gabriel Brehm
///CS361
///Lab01
///Colaborators: Jacob Malmstadt

using System;
using System.IO;

namespace cs361_lab01
{
    class Program
    {
        static void Main(string[] args)
        {
            ///The code beneath this comment determines the time to sort a list of the given size. 
            ///The time is then written to the appropriate cell in the excel file based on the startRow, and is written to the console.
            ///It is pretty ugly, mostly becuase I could not run all 60 sorts at one time due to memory shortage. 
            ///I had to run the code 6 sorts at a time, changing the size and startRow each time.
            
            //-----------------------------------------------------------------------------------------------------------------------------------------------
            
            long[] listOfTimes_ms = new long[3];

            long[] listOfTimes_qs = new long[3];

            bool sorted_ms = false;

            bool sorted_qs = false;

            int size = 1000;
           
            int startRow = 1;

            int[] listOfInts = new int[size];

            string[] listOfSTrings = new string[size];

            listOfSTrings = GenFunctions.ReadFile(@"C:\Users\Gabriel\Desktop\WOU\05-2019_springTerm\CS361\labs\lab01\lab1_data_" + size.ToString() + ".txt");

            ExcelClass excel = new ExcelClass(@"C:\Users\Gabriel\Desktop\WOU\05-2019_springTerm\CS361\labs\lab01\lab1_excel.xlsx", 1);

            for (int i = 0; i < 3; i++)
            {
                listOfInts = GenFunctions.ConvertToInts(listOfSTrings);

                long temp_ms = Sort.TimeMergeSort(listOfInts);

                sorted_ms = GenFunctions.IsSorted(listOfInts);

                listOfInts = GenFunctions.ConvertToInts(listOfSTrings);

                long temp_qs = Sort.TimeQuicksort(listOfInts);

                sorted_qs = GenFunctions.IsSorted(listOfInts);

                excel.WriteCell(i + startRow, 1, temp_ms.ToString());

                excel.WriteCell(i + startRow, 2, temp_qs.ToString());

                listOfTimes_ms[i] = temp_ms;

                listOfTimes_qs[i] = temp_qs;
            }
            excel.SaveExcel();

            excel.CloseExcel();
            Console.WriteLine("---------------------------------");
            Console.WriteLine("Merge-sort Times: size = " + size);
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine(listOfTimes_ms[i]);
            }
            Console.WriteLine("Is sorted status: " + sorted_ms);
            Console.WriteLine("---------------------------------");
            Console.WriteLine("Quicksort Times: size = " + size);
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine(listOfTimes_qs[i]);
            }
            Console.WriteLine("Is sorted status: " + sorted_qs);
            Console.WriteLine("---------------------------------");
            
            //-----------------------------------------------------------------------------------------------------------------------------------------------

            ///The code beneth this comment demonstrates that all the methods function as they should.
            ///The result of this code can be see in the screen dump sections of the lab report.

            //-----------------------------------------------------------------------------------------------------------------------------------------------
            /*
            string[] listOfSTrings = GenFunctions.ReadFile(@"C:\Users\Gabriel\Desktop\WOU\05-2019_springTerm\CS361\labs\lab01\lab1_data.txt");

            int[] listOfInts_ms = GenFunctions.ConvertToInts(listOfSTrings);

            int[] listOfInts_qs = listOfInts_ms;

            long sortTime_ms = Sort.TimeMergeSort(listOfInts_ms);

            long sortTime_qs = Sort.TimeQuicksort(listOfInts_qs);

            bool sortedStatus_ms = GenFunctions.isSorted(listOfInts_ms);

            bool sortedStatus_qs = GenFunctions.isSorted(listOfInts_qs);

            long sum_ms = GenFunctions.SumOfInts(listOfInts_ms);

            long sum_qs = GenFunctions.SumOfInts(listOfInts_qs);

            Console.WriteLine("Merge-Sort");

            Console.WriteLine("Time to run mehtod on " + listOfInts_ms.Length + " integers: " + sortTime_ms + "ns.");

            Console.WriteLine("Sum of all integers in list: " + sum_ms);

            if(sortedStatus_ms == true)
            {
                Console.WriteLine("Succesfully sorted the list.");
            }
            Console.WriteLine("");

            Console.WriteLine("Quicksort");

            Console.WriteLine("Time to run mehtod on " + listOfInts_qs.Length + " integers: " + sortTime_qs + "ns.");

            Console.WriteLine("Sum of all integers in list: " + sum_qs);

            if (sortedStatus_qs == true)
            {
                Console.WriteLine("Succesfully sorted the list.");
            }
            Console.WriteLine("");

            Console.WriteLine("First 100 integers in each sorted list:");

            Console.WriteLine("");

            Console.WriteLine("Merge-Sort \tQuicksort");

            Console.WriteLine("---------------------------------------");

            for(int i = 0; i < 100; i++)
            {
                Console.WriteLine(listOfInts_ms[i] + "\t\t" + listOfInts_qs[i]);
            }
            */
            //-----------------------------------------------------------------------------------------------------------------------------------------------
            Console.Read();
        }
    }
}

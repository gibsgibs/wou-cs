using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab02
{
    class Program
    {
        static void Main(string[] args)
        {
            //GenFunctions.GenerateAllFiles();

            int startRow = 1;

            int size = 1000;

            ExcelClass excel = new ExcelClass(@"C:\Users\Gabriel\Desktop\WOU\05-2019_springTerm\CS361\labs\lab02\lab2_excel.xlsx", 1);

            for (int i = 0; i < 5; i++)
            {
                string pathToFile = @"C:\Users\Gabriel\Desktop\WOU\05-2019_springTerm\CS361\labs\lab02\lab2_data_" + size + ".txt";

                string[] arrayOfStrings = GenFunctions.ReadFile(pathToFile);

                int[] arrayOfInts = GenFunctions.ConvertToInts(arrayOfStrings);

                int[] arrayOfInts_rs = arrayOfInts;

                int[] arrayOfInts_bs = arrayOfInts;

                long[] times_rs = new long[3];

                long[] times_bs = new long[3];

                long[] topTenTimes = new long[3];

                int[] tenLargest = new int[10];

                bool result_rs = false;

                bool result_bs = false;

                for (int j = 0; j < 3; j++)
                {
                    times_rs[j] = Sort.TimeRadixSort(arrayOfInts_rs);

                    times_bs[j] = Sort.TimeBucketSort(arrayOfInts_bs);

                    result_rs = GenFunctions.IsSorted(arrayOfInts_rs);

                    result_bs = GenFunctions.IsSorted(arrayOfInts_bs);

                    topTenTimes[j] = GenFunctions.TimeTenLargest(arrayOfInts_rs, tenLargest);

                    arrayOfInts = GenFunctions.ConvertToInts(arrayOfStrings);

                    arrayOfInts_rs = arrayOfInts;

                    arrayOfInts_bs = arrayOfInts;

                    excel.WriteCell(j + startRow, 1, times_rs[j].ToString());

                    excel.WriteCell(j + startRow, 2, times_bs[j].ToString());

                    excel.WriteCell(j + startRow, 3, topTenTimes[j].ToString());
                }
                GenFunctions.PrintResults("Radix", arrayOfInts_rs, result_rs, times_rs);

                GenFunctions.PrintResults("Bucket", arrayOfInts_bs, result_bs, times_bs);

                GenFunctions.PrintTenLargest(tenLargest, topTenTimes, arrayOfInts.Length);

                startRow += 3;

                size *= 10;
            }
            excel.SaveExcel();

            excel.CloseExcel();

            Console.Read();
        }
    }
}

///Gabriel Brehm
///CS361
///Lab01
///Colaborators: Jacob Malmstadt

using System;
using System.IO;
using System.Diagnostics;

namespace cs361_lab01
{

    public class GenFunctions
    {
        /// <summary>
        /// Returns the middle index of a list.
        /// </summary>
        /// <param name="startIndex">
        /// The first index of the list as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        /// <returns>
        /// The middle index of the list as an int.
        /// </returns>
        public static int getMiddleIndex(int startIndex, int endIndex)
        {
            double temp = (startIndex + endIndex) / 2;

            int middleIndex = Convert.ToInt32(Math.Floor(temp));

            return middleIndex;
        }


        /// <summary>
        /// Given the path and name of a file, this function opens that file and stores the contents line by line in an array of strings.
        /// Note: This method only works when the format of the file is string representations of numbers with one on each line.
        /// </summary>
        /// <param name="pathToFile">
        /// The path to the file and the name of the file as a string.
        /// </param>
        /// <returns>
        /// The list of strings.
        /// </returns>
        public static string[] ReadFile(string pathToFile)
        {
            string[] listOfStrings = File.ReadAllLines(pathToFile);

            return listOfStrings;
        }

        /// <summary>
        /// Given the list of strings, it makes a list of the integer equivilents.
        /// </summary>
        /// <param name="listOfStrings">
        /// The list of strings.
        /// </param>
        /// <returns>
        /// The list of ints.
        /// </returns>
        public static int[] ConvertToInts(string[] listOfStrings)
        {
            int[] listOfInts = new int[listOfStrings.Length];

            for (int i = 0; i < listOfStrings.Length; i++)
            {
                listOfInts[i] = int.Parse(listOfStrings[i]);
            }
            return listOfInts;
        }

        /// <summary>
        /// Given a list of ints, it makes a list of string equivilents.
        /// </summary>
        /// <param name="listOfInts">
        /// The given list of ints.
        /// </param>
        /// <returns>
        /// The list of strings.
        /// </returns>
        public static string[] ConvertToStrings(int[] listOfInts)
        {
            string[] listOfStrings = new string[listOfInts.Length];

            for (int i = 0; i < listOfInts.Length; i++)
            {
                listOfStrings[i] = listOfInts[i].ToString();
            }
            return listOfStrings;
        }

        /// <summary>
        /// Sums the integers in an array of integers.
        /// </summary>
        /// <param name="listOfInts">
        /// The array of ints.
        /// </param>
        /// <returns>
        /// The sum as a long.
        /// </returns>
        public static long SumOfInts(int[] listOfInts)
        {
            long sum = 0;

            for (int i = 0; i < listOfInts.Length; i++)
            {
                sum = sum + listOfInts[i];
            }
            return sum;
        }

        /// <summary>
        /// Gets the first half of a given list.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index in the list as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index in the list as an int.
        /// </param>
        /// <returns>
        /// The first half of the list.
        /// </returns>
        public static int[] getFirstHalf(int[] list, int startIndex, int endIndex)
        {
            int middleIndex = getMiddleIndex(startIndex, endIndex);

            int[] result = new int[middleIndex];

            for (int i = 0; i < middleIndex; i++)
            {
                result[i] = list[i];
            }
            return result;
        }

        /// <summary>
        /// Gets the seconcd half of a given list.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index in the list as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        /// <returns>
        /// The second half of the list.
        /// </returns>
        public static int[] getSecondHalf(int[] list, int startIndex, int endIndex)
        {
            int middleIndex = getMiddleIndex(startIndex, endIndex);

            int[] result = new int[endIndex - middleIndex];

            int j = 0;

            for (int i = middleIndex; i < endIndex; i++)
            {
                result[j] = list[i];

                j++;
            }
            return result;
        }

        /// <summary>
        /// Checks if the given list is sorted. 
        /// </summary>
        /// <param name="list">
        /// The given list.
        /// </param>
        /// <returns>
        /// True if it is sorted, false otherwise.
        /// </returns>
        public static bool IsSorted(int[] list)
        {
            if (list.Length == 1)
            {
                return true;
            }
            else if (IsSorted(getFirstHalf(list, 0, list.Length)) == true)
            {
                if (IsSorted(getSecondHalf(list, 0, list.Length)) == true)
                {
                    if (getSecondHalf(list, 0, list.Length)[0] >= getFirstHalf(list, 0, list.Length)[getMiddleIndex(0, list.Length) - 1])
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// A method for getting the current time in nanoseconds.
        /// Assistance with with method from https://stackoverflow.com/questions/1551742/what-is-the-equivalent-to-system-nanotime-in-net.
        /// </summary>
        /// <returns>
        /// Current time in nanoseconds as a long.
        /// </returns>
        public static long NanoTime()
        {
            long nano = 10000L * Stopwatch.GetTimestamp();

            nano = nano / TimeSpan.TicksPerMillisecond;

            nano = nano * 100L;

            return nano;
        }

        /// <summary>
        /// Creates a new list of random ints on the heap.
        /// </summary>
        /// <param name="size">
        /// The given size of the list as an int.
        /// </param>
        /// <returns>
        /// The list of random ints.
        /// </returns>
        public static int[] RandomListOfInts(int size)
        {
            Random random = new Random();

            int[] randomList = new int[size];

            for (int i = 0; i < size; i++)
            {
                randomList[i] = random.Next(1, int.MaxValue);
            }

            return randomList;
        }
        /// <summary>
        /// Fills the files in the directory with random numbers raning form 1 to int.MaxValue. 
        /// </summary>
        public static void GenerateAllFiles()
        {
            int i = 1000;

            int j = 0;

            while (i < 50000001)
            {
                string filePath = @"C:\Users\Gabriel\Desktop\WOU\05-2019_springTerm\CS361\labs\lab01\lab1_data_" + i.ToString() + ".txt";

                int[] randomList = new int[i];

                randomList = RandomListOfInts(i);

                File.WriteAllLines(filePath, ConvertToStrings(randomList));

                if (j % 2 == 0)
                {
                    i *= 5;

                    j++;
                }
                else
                {
                    i *= 2;
                    j++;
                }
            }
        }

    }
}

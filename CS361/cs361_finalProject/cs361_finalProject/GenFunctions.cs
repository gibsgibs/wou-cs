///Gabriel Brehm
///CS361
///Final Project
///Colaborators: Jacob Malmstadt

using System;
using System.IO;
using System.Diagnostics;
using System.Linq;

namespace cs361_finalProject
{
    public class GenFunctions
    {
        /// <summary>
        /// Returns the middle index of a array.
        /// </summary>
        /// <param name="startIndex">
        /// The first index of the array as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        /// <returns>
        /// The middle index of the array as an int.
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
        /// The array of strings.
        /// </returns>
        public static string[] ReadFile(string pathToFile)
        {
            string[] arrayOfStrings = File.ReadAllLines(pathToFile);

            return arrayOfStrings;
        }

        /// <summary>
        /// Given the array of strings, it makes a array of the integer equivilents.
        /// </summary>
        /// <param name="arrayOfStrings">
        /// The array of strings.
        /// </param>
        /// <returns>
        /// The array of ints.
        /// </returns>
        public static int[] ConvertToInts(string[] arrayOfStrings)
        {
            int[] arrayOfInts = new int[arrayOfStrings.Length];

            for(int i = 0; i < arrayOfStrings.Length; i++)
            {
                arrayOfInts[i] = int.Parse(arrayOfStrings[i]);
            }
            return arrayOfInts;
        }

        /// <summary>
        /// Given a array of ints, it makes a array of string equivilents.
        /// </summary>
        /// <param name="arrayOfInts">
        /// The given array of ints.
        /// </param>
        /// <returns>
        /// The array of strings.
        /// </returns>
        public static string[] ConvertToStrings(int[] arrayOfInts)
        {
            string[] arrayOfStrings = new string[arrayOfInts.Length];

            for(int i = 0; i < arrayOfInts.Length; i++)
            {
                arrayOfStrings[i] = arrayOfInts[i].ToString();
            }
            return arrayOfStrings;
        }

        /// <summary>
        /// Sums the integers in an array of integers.
        /// </summary>
        /// <param name="arrayOfInts">
        /// The array of ints.
        /// </param>
        /// <returns>
        /// The sum as a long.
        /// </returns>
        public static long SumOfInts(int[] arrayOfInts)
        {
            long sum = 0;

            for(int i = 0; i < arrayOfInts.Length; i++)
            {
                sum = sum + arrayOfInts[i];
            }
            return sum;
        }

        /// <summary>
        /// Gets the first half of a given array.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index in the array as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index in the array as an int.
        /// </param>
        /// <returns>
        /// The first half of the array.
        /// </returns>
        public static int[] getFirstHalf(int[] array, int startIndex, int endIndex)
        {
            int middleIndex = getMiddleIndex(startIndex, endIndex);

            int[] result = new int[middleIndex];

            for(int i = 0; i < middleIndex; i++)
            {
                result[i] = array[i];
            }
            return result;
        }

        /// <summary>
        /// Gets the seconcd half of a given array.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index in the array as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        /// <returns>
        /// The second half of the array.
        /// </returns>
        public static int[] getSecondHalf(int[] array, int startIndex, int endIndex)
        {
            int middleIndex = getMiddleIndex(startIndex, endIndex);

            int[] result = new int[endIndex - middleIndex];

            int j = 0;

            for(int i = middleIndex; i < endIndex; i++)
            {
                result[j] = array[i];

                j++;
            }
            return result;
        }

        /// <summary>
        /// Checks if the given array is sorted. 
        /// </summary>
        /// <param name="array">
        /// The given array.
        /// </param>
        /// <returns>
        /// True if it is sorted, false otherwise.
        /// </returns>
        public static bool IsSorted(int[] array)
        {
            if(array.Length == 1)
            {
                return true;
            }
            else if(IsSorted(getFirstHalf(array, 0, array.Length)) == true)
            {
                if(IsSorted(getSecondHalf(array, 0, array.Length)) == true)
                {
                    if(getSecondHalf(array, 0, array.Length)[0] >= getFirstHalf(array, 0, array.Length)[getMiddleIndex(0, array.Length) - 1])
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
        /// Creates a new array of random ints on the heap.
        /// </summary>
        /// <param name="size">
        /// The given size of the array as an int.
        /// </param>
        /// <returns>
        /// The array of random ints.
        /// </returns>
        public static int[] RandomarrayOfInts(int size)
        {
            Random random = new Random();

            int[] randomarray = new int[size];

            for(int i = 0; i < size; i++)
            {
                randomarray[i] = random.Next(1, int.MaxValue) % size;
            }

            return randomarray;
        }
        /// <summary>
        /// Fills the files in the directory with random numbers raning form 1 to int.MaxValue. 
        /// </summary>
        public static void GenerateAllFiles()
        {
            int i = 1000;

            while (i < 10000000)
            {
                string filePath = @"C:\Users\Gabriel\Desktop\WOU\05-2019_springTerm\CS361\labs\lab02\lab2_data_" + i.ToString() + ".txt";

                int[] randomarray = new int[i];

                randomarray = RandomarrayOfInts(i);

                File.WriteAllLines(filePath, ConvertToStrings(randomarray));

                i *= 10;
            }
        }

        /// <summary>
        /// Replaces the maximum value in an array with 0.
        /// </summary>
        /// <param name="array">
        /// The given array.
        /// </param>
        public static void RemoveMax(int[] array)
        {
            int max = array.Max();

            for(int i = 0; i < array.Length; i++)
            {
                if(array[i] == max)
                {
                    array[i] = 0;
                    break;
                }
            }


        }

        /// <summary>
        /// Finds the ten largest values in the given array and stores them in the other given array. 
        /// </summary>
        /// <param name="arrayA">
        /// the given array
        /// </param>
        /// <param name="arrayB">
        /// The array that holds the ten values 
        /// </param>
        /// <param name="index">
        /// the index used to control when the recussive call breaks
        /// </param>
        public static void FindTenLargest(int[] arrayA, int[] arrayB, int index)
        {
            if(index < 10)
            {
                arrayB[index] = arrayA.Max();

                RemoveMax(arrayA);

                FindTenLargest(arrayA, arrayB, index + 1);
            }
        }

        /// <summary>
        /// times how long it takes to find the ten largest values.
        /// </summary>
        /// <param name="array">
        /// the array of numbers
        /// </param>
        /// <param name="tenLargest">
        /// the ten largest values 
        /// </param>
        /// <returns>
        /// the time elapsed
        /// </returns>
        public static long TimeTenLargest(int[] array, int[] tenLargest)
        {
            long startTime = GenFunctions.NanoTime();

            FindTenLargest(array, tenLargest, 0);

            long endTime = GenFunctions.NanoTime();

            long timeElapsed = endTime - startTime;

            return timeElapsed;
        }

        /// <summary>
        /// Fancy console output for the ten largest values in the array.
        /// </summary>
        /// <param name="tenLargest">
        /// The ten largest values.
        /// </param>
        /// <param name="searchTimes">
        /// The time it took to find each of the ten largest values.
        /// </param>
        /// <param name="size">
        /// The size of the array.
        /// </param>
        public static void PrintTenLargest(int[] tenLargest, long[] searchTimes, int size)
        {
            string line2 = "|of size n = " + size.ToString() + ":";

            Console.WriteLine("+-------------------------------+");

            Console.WriteLine("|Top ten largest values in array |");

            Console.WriteLine(line2 + WhiteSpaceFill(line2));

            for(int i = 0; i < 10; i++)
            {
                string line_n = "|" + tenLargest[i].ToString();

                Console.WriteLine(line_n + WhiteSpaceFill(line_n));
            }

            Console.WriteLine("|Time to search:                |");

            string line13 = "|Trial_1: " + searchTimes[0].ToString() + "ns";

            string line14 = "|Trial_2: " + searchTimes[1].ToString() + "ns";

            string line15 = "|Trial_3: " + searchTimes[2].ToString() + "ns";

            Console.WriteLine(line13 + WhiteSpaceFill(line13));

            Console.WriteLine(line14 + WhiteSpaceFill(line14));

            Console.WriteLine(line15 + WhiteSpaceFill(line15));

            Console.WriteLine("+-------------------------------+");
        }

        /// <summary>
        /// Takes in a string and returns a new string of whitespace such that the two strings are 35 chars long.
        /// </summary>
        /// <param name="input">
        /// The given string.
        /// </param>
        /// <returns>
        /// The whitesapce string.
        /// </returns>
        public static string WhiteSpaceFill(string input)
        {
            string whiteSpace = "";
            for(int i = 0; i < 32 - input.Length; i++)
            {
                whiteSpace += " ";
            }
            return whiteSpace + "|";
        }

        /// <summary>
        /// Fancy console output for results of using a sorting algorithm on an array.
        /// </summary>
        /// <param name="name">
        /// The name of the sort.
        /// </param>
        /// <param name="array">
        /// The array to be sorted
        /// </param>
        /// <param name="result">
        /// The result of the IsSorted fnction.
        /// </param>
        /// <param name="sortTimes">
        /// Th array of times to sort.
        /// </param>
        public static void PrintResults(string name, int[] array, bool result, long[] sortTimes)
        {
            string line2 = "|" + name + " Sort: Size n = " + array.Length.ToString();

            string line3 = "|Trial_1: " + sortTimes[0].ToString() + "ns";

            string line4 = "|Trial_2: " + sortTimes[1].ToString() + "ns";

            string line5 = "|Trial_3: " + sortTimes[2].ToString() + "ns";

            string line6 = "|Sorted Status: " + result;

            Console.WriteLine("+-------------------------------+");

            Console.WriteLine(line2 + WhiteSpaceFill(line2));

            Console.WriteLine(line3 + WhiteSpaceFill(line3));

            Console.WriteLine(line4 + WhiteSpaceFill(line4));

            Console.WriteLine(line5 + WhiteSpaceFill(line5));

            Console.WriteLine(line6 + WhiteSpaceFill(line6));

            Console.WriteLine("+-------------------------------+");
        }

        /// <summary>
        /// Prints out a line of dashes with a plus symbol at either end of the desired width.
        /// </summary>
        /// <param name="width">
        /// The width of the line.
        /// </param>
        public static void PrintLine(int width)
        {
            Console.Write("+");

            for(int i = 0; i < width + 2; i++)
            {
                Console.Write("-");
            }
            Console.WriteLine("+");
        }

        /// <summary>
        /// Counts the number of unique entries in an array.
        /// </summary>
        /// <param name="arrayOfStrings">
        /// The given array.
        /// </param>
        /// <returns>
        /// The number of unique entires.
        /// </returns>
        public static int CountUnique(string[] arrayOfStrings)
        {
            int count = 1;

            for(int i = 1; i < arrayOfStrings.Length; i++)
            {
                if(arrayOfStrings[i - 1] != arrayOfStrings[i] && arrayOfStrings[i] != null)
                {
                    count++;
                }
            }
            return count;
        }

        /// <summary>
        /// Finds the longest length string in a 2D array of strings.
        /// </summary>
        /// <param name="arrayOfStrings">
        /// The given array of strings.
        /// </param>
        /// <returns>
        /// The length of the longest string.
        /// </returns>
        public static int LongestString(string[,] arrayOfStrings)
        {
            string longest = " ";

            for(int i = 0; i < arrayOfStrings.GetLength(0); i++)
            {
                for(int j = 0; j < arrayOfStrings.GetLength(1); j++)
                {
                    if(arrayOfStrings[i, j] == null)
                    {
                        longest = " ";
                    }
                    else
                    {
                        if(arrayOfStrings[i, j].Length > longest.Length)
                        {
                            longest = arrayOfStrings[i, j];
                        }
                    }
                }

            }
            return longest.Length;
        }

        /// <summary>
        /// Finds the longest string within a 2D array and a 1D array.
        /// </summary>
        /// <param name="array_2D">
        /// The 2D array of strings.
        /// </param>
        /// <param name="array_1D">
        /// The 1D array of strings.
        /// </param>
        /// <returns>
        /// The length of the longest string in both arrays.
        /// </returns>
        public static int LongestString(string[,] array_2D, string[] array_1D)
        {
            string longest = " ";

            for(int i = 0; i < array_2D.GetLength(0); i++)
            {
                for(int j = 0; j < array_2D.GetLength(1); j++)
                {
                    if(array_2D[i, j] != null)
                    {
                        if(array_2D[i, j].Length > longest.Length)
                        {
                            longest = array_2D[i, j];
                        }
                    }
                }
            }
            for(int i = 0; i < array_1D.Length; i++)
            {
                if(array_1D[i] != null)
                {
                    if(array_1D[i].Length > longest.Length)
                    {
                        longest = array_1D[i];
                    }
                }
            }
            return longest.Length;
        }

        /// <summary>
        /// An overloaded version of the above TextBox function that takes in a single string.
        /// </summary>
        /// <param name="text">
        /// The given string.
        /// </param>
        public static void TextBox(string text)
        {
            int width = text.Length;

            PrintLine(width);

            Console.WriteLine("| " + text + WhiteSpaceFill(text, width) + " |");

            PrintLine(width);
        }

        /// <summary>
        /// Prints out a line of dashes with a plus symbol at either end of the desired width.
        /// </summary>
        /// <param name="width">
        /// The width of the line.
        /// </param>
        public static void PrintLine(int numOfCells, int width)
        {
            Console.Write("+");
            for(int i = 0; i < numOfCells; i++)
            {
                for(int j = 0; j < width - 1; j++)
                {
                    Console.Write("-");
                }
                Console.Write("+");
            }
            Console.WriteLine("");
        }

        public static void PrintBoldLine(int numOfCells, int width)
        {
            Console.Write("+");
            for(int i = 0; i < numOfCells; i++)
            {
                for(int j = 0; j < width - 1; j++)
                {
                    Console.Write("=");
                }
                Console.Write("+");
            }
            Console.WriteLine("");
        }

        /// <summary>
        /// Back fills a string with padding such that the string is the same lenght as the others in the array.
        /// </summary>
        /// <param name="input">
        /// The string that needs padding.
        /// </param>
        /// <param name="width">
        /// The total length of the string and the padding.
        /// </param>
        /// <returns>
        /// The string of padding.
        /// </returns>
        public static string WhiteSpaceFill(string input, int width)
        {
            string whiteSpace = "";

            for(int i = 0; i < width - input.Length - 1; i++)
            {
                whiteSpace += " ";
            }
            return whiteSpace;
        }

        /// <summary>
        /// Prints out a table given a 2D array of integers.
        /// </summary>
        /// <param name="label">
        /// The lable for the table.
        /// </param>
        /// <param name="data">
        /// The 2D array of integers.
        /// </param>
        public static void PrintTable(string label, string[,] data)
        {
            Console.WriteLine(label);

            int cellWidth = LongestString(data) + 3;

            PrintLine(data.GetLength(0) - 1, cellWidth);

            for(int i = 1; i < data.GetLength(0); i++)
            {
                Console.Write("|");

                for(int j = 1; j < data.GetLength(1); j++)
                {
                    if(data[i, j] == null)
                    {
                        Console.Write(" " + "" + WhiteSpaceFill("", cellWidth - 2) + " |");
                    }
                    else
                    {
                        Console.Write(" " + data[i, j].ToString() + WhiteSpaceFill(data[i, j].ToString(), cellWidth - 2) + " |");
                    }
                }
                Console.WriteLine("");

                PrintLine(data.GetLength(0) - 1, cellWidth);
            }
            Console.WriteLine("");
        }

        /// <summary>
        /// Prints an EVEN MORE AWESOME table with columns and a bold line.
        /// </summary>
        /// <param name="label">
        /// The table lable.
        /// </param>
        /// <param name="columnNames">
        /// The string array of column names.
        /// </param>
        /// <param name="data">
        /// The data to populate the table.
        /// </param>
        public static void PrintTable(string label, string[] columnNames, string[,] data)
        {
            Console.WriteLine("[" + label + "]");

            int cellWidth = LongestString(data, columnNames) + 3;

            PrintLine(data.GetLength(1), cellWidth);

            Console.Write("|");

            for(int i = 0; i < columnNames.Length; i++)
            {
                if(columnNames[i] != null)
                {
                    Console.Write(" " + columnNames[i].ToString() + WhiteSpaceFill(columnNames[i].ToString(), cellWidth - 2) + " |");
                }
                else
                {
                    Console.Write(" " + "" + WhiteSpaceFill("", cellWidth - 2) + " |");
                }
            }
            Console.WriteLine("");

            PrintBoldLine(data.GetLength(1), cellWidth);

            for(int i = 0; i < data.GetLength(0); i++)
            {
                Console.Write("|");

                for(int j = 0; j < data.GetLength(1); j++)
                {
                    if(data[i, j] != null)
                    {
                        Console.Write(" " + data[i, j].ToString() + WhiteSpaceFill(data[i, j].ToString(), cellWidth - 2) + " |");
                    }
                    else
                    {
                        Console.Write(" " + "" + WhiteSpaceFill("", cellWidth - 2) + " |");
                    }
                }
                Console.WriteLine("");

                PrintLine(data.GetLength(1), cellWidth);
            }
            Console.WriteLine("");
        }

        /// <summary>
        /// Generic method to convert an array of anything into an array of strings.
        /// </summary>
        /// <typeparam name="T">
        /// Whatever you want it to be.
        /// </typeparam>
        /// <param name="array">
        /// The given array of type T items. 
        /// </param>
        /// <returns>
        /// The array of strings.
        /// </returns>
        public static string[] ToStringArray<T>(T[] array)
        {
            string[] stringArray = new string[array.Length];

            for(int i = 0; i < stringArray.Length; i++)
            {
                if(array[i] != null)
                {
                    stringArray[i] = array[i].ToString();
                }
                else
                {
                    stringArray[i] = "";
                }
            }
            return stringArray;
        }

        /// <summary>
        /// Generic method to convert a 2D array of anything into a 2D array of strings.
        /// </summary>
        /// <typeparam name="T">
        /// Whatever you want it to be.
        /// </typeparam>
        /// <param name="array">
        /// The given 2D array of type T items.
        /// </param>
        /// <returns>
        /// The 2D array of strings.
        /// </returns>
        public static string[,] To2DStringArray<T>(T[,] array)
        {
            string[,] stringArray = new string[array.GetLength(0), array.GetLength(1)];

            for(int i = 0; i < stringArray.GetLength(0); i++)
            {
                for(int j = 0; j < stringArray.GetLength(1); j++)
                {
                    if(array[i, j] != null)
                    {
                        stringArray[i, j] = array[i, j].ToString();
                    }
                    else
                    {
                        stringArray[i, j] = "";
                    }
                }
            }
            return stringArray;
        }
    }     
}

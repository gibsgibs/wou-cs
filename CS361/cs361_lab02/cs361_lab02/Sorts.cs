///Gabriel Brehm
///CS361
///Lab01
///Colaborators: Jacob Malmstadt

using System;
using System.Collections.Generic;
using System.Linq;


namespace cs361_lab02
{
    public class Sort
    {
        /// <summary>
        /// Creats two arrays of the first and second half of the given array, which are each assumed to be sorted, and merges them together.
        /// Assistence with this method from http://csharpexamples.com/c-merge-sort-algorithm-implementation/, and from our textbook.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the array as an int.
        /// </param>
        /// <param name="middleIndex">
        /// The middle index of the array as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        public static void Merge(int[] array, int startIndex, int middleIndex, int endIndex)
        {
            int leftHalfLength = middleIndex - startIndex + 1;      //calculate the length of the left half array

            int rightHalfLength = endIndex - middleIndex;           //calculate the length of the right half array

            int[] leftarray = new int[leftHalfLength + 1];           //makes a new array on the heap that is 1 larger then the left half

            int[] rightarray = new int[rightHalfLength + 1];         //makes a new array on the heap that is 1 larger than the right half

            for (int i = 0; i < leftHalfLength; i++)
            {
                leftarray[i] = array[startIndex + i];                 //copies the left half of the given array into the leftarray
            }

            for (int i = 0; i < rightHalfLength; i++)
            {
                rightarray[i] = array[middleIndex + 1 + i];           //copies the right hald of the given array into the rightarray
            }

            leftarray[leftHalfLength] = Int32.MaxValue;              //the sentinal value for the leftarray

            rightarray[rightHalfLength] = Int32.MaxValue;            //the sentinal value for the rightarray

            int leftIndex = 0;

            int rightIndex = 0;

            for (int k = startIndex; k < endIndex + 1; k++)
            {
                if (leftarray[leftIndex] <= rightarray[rightIndex])    //sets array of k equal to the smaller of two values: rightarray of rightIndex and leftarray of leftIndex.
                {
                    array[k] = leftarray[leftIndex];

                    leftIndex++;
                }
                else
                {
                    array[k] = rightarray[rightIndex];

                    rightIndex++;
                }
            }
        }

        /// <summary>
        /// This method used the Merge Sort technique to sort a given array of numbers. That is, it seperates the array recursivly into smaller and smaller size arrays until each array is length 1. 
        /// It then recombines the arrays in order, thus sorting the array. This method is assisted by the Merge Method defined above.
        /// Assistance with this method from our textbook.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the array as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        public static void MergeSort(int[] array, int startIndex, int endIndex)
        {
            if (startIndex < endIndex)
            {
                int middleIndex = GenFunctions.getMiddleIndex(startIndex, endIndex);

                MergeSort(array, startIndex, middleIndex);

                MergeSort(array, middleIndex + 1, endIndex);

                Merge(array, startIndex, middleIndex, endIndex);

            }
        }

        /// <summary>
        /// Partitions the given array into two groups: one less than or equal to the last value, and one greater than it. Then it places that last value in between the two sets.
        /// Finally, it returns the index of that value plus one.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        /// <returns>
        /// The index of the pivot value as an int.
        ///  </returns>
        public static int Partition(int[] array, int startIndex, int endIndex)
        {

            int pivot = array[endIndex];                 //sets the pivot to the last value in the array

            int i = startIndex - 1;                     //sets the i index to the start index minus 1

            for (int j = startIndex; j < endIndex; j++)
            {
                if (array[j] <= pivot)                    //if the jth value is less than or equal to the pivot, switch the jth value and the ith value
                {
                    i++;

                    int temp1 = array[j];

                    array[j] = array[i];

                    array[i] = temp1;
                }
            }                                           //after the loop, put the pivot value between the two partitions
            int temp2 = array[endIndex];

            array[endIndex] = array[i + 1];

            array[i + 1] = temp2;

            return i + 1;
        }

        /// <summary>
        /// This method generates a random number between startIndex and endIndex.
        /// It then swaps the value at that index with the value at the endIndex. Then Partition is called.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        /// <returns>
        /// The index of the pivot value as an int.
        ///  </returns>
        public static int RandomPartition(int[] array, int startIndex, int endIndex)
        {
            Random rand = new Random();

            int randomIndex = rand.Next(startIndex, endIndex);

            int temp = array[endIndex];

            array[endIndex] = array[randomIndex];

            array[randomIndex] = temp;

            return Partition(array, startIndex, endIndex);
        }

        /// <summary>
        /// This method gets the average of the values at the startIndex, endIndex, and middleIndex, mods it by the size of the array we are looking at.
        /// The value at that index is swaped with the value at the endInex, and then Partition is called.
        /// NOTE: This method, for whatever reason, does not work. I tried for hours to fix it, but to no avail.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        /// <returns>
        /// The index of the pivot value as an int.
        ///  </returns>
        public static int AveragePartition(int[] array, int startIndex, int endIndex)
        {
            int pivotIndex = (array[startIndex] / 3) + (array[endIndex] / 3) + (array[GenFunctions.getMiddleIndex(startIndex, endIndex)] / 3);

            pivotIndex = pivotIndex % (endIndex - startIndex);

            int temp = array[endIndex];

            array[endIndex] = array[pivotIndex];

            array[pivotIndex] = temp;

            return Partition(array, startIndex, endIndex);
        }
        /// <summary>
        /// Uses the Quicksort method to sort the given array of numbers. That is, it partitions the array, and then recursivly uses Quicksort on each partition.
        /// This method is assisted by the Partition method defined above.
        /// Assistance with this method from our textbook.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the array as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the array as an int.
        /// </param>
        public static void Quicksort(int[] array, int startIndex, int endIndex)
        {
            if (startIndex < endIndex)
            {
                int middlleIndex = Partition(array, startIndex, endIndex);

                Quicksort(array, startIndex, middlleIndex - 1);

                Quicksort(array, middlleIndex + 1, endIndex);
            }
        }

        /// <summary>
        /// Times how long it taks to use Merge Sort on a given array of numbers.
        /// </summary>
        /// <param name="array">
        /// The given array of ints.
        /// </param>
        /// <returns>
        /// The time it took to sort as a long.
        /// </returns>
        public static long TimeMergeSort(int[] array)
        {
            long startTime = GenFunctions.NanoTime();

            MergeSort(array, 0, array.Length - 1);

            long endTime = GenFunctions.NanoTime();

            long timeElapsed = endTime - startTime;

            return timeElapsed;
        }

        /// <summary>
        /// Times how long it takes to use Quicksort on a given array of numbers.
        /// </summary>
        /// <param name="array">
        /// The array of numbers as an int.
        /// </param>
        /// <returns>
        /// The time it took to sort as a long.
        /// </returns>
        public static long TimeQuicksort(int[] array)
        {
            long startTime = GenFunctions.NanoTime();

            Quicksort(array, 0, array.Length - 1);

            long endTime = GenFunctions.NanoTime();

            long timeElapsed = endTime - startTime;

            return timeElapsed;
        }

        /// <summary>
        /// Uses counting sort based on the nth digit given.
        /// </summary>
        /// <param name="arrayA">
        /// The given array of numbers to be sorted. 
        /// </param>
        /// <param name="digit">
        /// The nth digit.
        /// </param>
        public static void CountingSort(int[] arrayA, int digit)
        {
            int[] arrayB = new int[arrayA.Length];                        //Create a new array of the same length as the given array.

            int[] arrayC = new int[10];                                  //Create a new array of length 10, for each numeric character.

            for (int i = 0; i < 10; i++)
            {
                arrayC[i] = 0;
            }
            for (int i = 0; i < arrayA.Length; i++)
            {
                arrayC[(arrayA[i] / digit) % 10]++;                       //Counts the number of occurences of each value in arrayA
            }
            for (int i = 1; i < 10; i++)
            {
                arrayC[i] += arrayC[i - 1];                               //Sets each value to the sum of all values smaller than it.
            }
            for (int i = arrayA.Length - 1; i >= 0; i--)
            {
                arrayB[arrayC[(arrayA[i] / digit) % 10] - 1] = arrayA[i];   //Sets arrayA to arrayB of arrayC of the nth digit of arrayA

                arrayC[(arrayA[i] / digit) % 10]--;                       //Reduces the number at the same index in arrayC
            }
            for (int i = 0; i < arrayA.Length; i++)
            {
                arrayA[i] = arrayB[i];                                    //Copies arrayB into arrayA
            }
        }

        /// <summary>
        /// Performs Insertion sort, except it does it based on a single digit in the number, which is based on the mod parapeter.
        /// </summary>
        /// <param name="array">
        /// The given array of integers.
        /// </param>
        /// <param name="mod">
        /// The mod number used to determine which digit is being compared.
        /// </param>
        public static void InsertionSort(int[] array, long mod)
        {
            try
            {
                for (int i = 0; i < array.Length; i++)
                {
                    int indexValue = array[i];

                    int j = i;
                    {
                        while (j > 0 && (array[j - 1] % mod) / (mod / 10) > (indexValue % mod) / (mod / 10))     //checks if j > 0 and if the given digit of 
                        {                                                                                       //array[j-1] > the same place digit of indexValue
                            {
                                array[j] = array[j - 1];

                                j--;
                            }
                        }
                        array[j] = indexValue;
                    }
                }
            }
            catch
            {
                Console.WriteLine("Error: Potenial division by zero!");
            }
        }

        /// <summary>
        /// Performs Radix sort on the given array of integers, using counting sort as an intermediary step.
        /// </summary>
        /// <param name="array"></param>
        public static void RadixSort(int[] array)
        {
            for (int i = 1; array.Max() / i > 0; i *= 10)
            {
                CountingSort(array, i);
            }
        }
        
        /// <summary>
        /// Uses the bucket sort algorithm to sort the given array of integers.
        /// </summary>
        /// <param name="arrayA">
        /// The given array of integers
        /// </param>        
        public static void BucketSort(int[] arrayA)
        {
            int min = arrayA.Min();

            List<int>[] arrayB = new List<int>[arrayA.Max() - min + 1]; //new array of arrays on the h

            int n = arrayA.Length;

            for(int i = 0; i < arrayB.Length; i++)
            {
                arrayB[i] = new List<int>();         //intitialize each eleemnt to a linked array
            }
            for(int i = 0; i < n; i++)
            {
                arrayB[arrayA[i] - min].Add(arrayA[i]); //add elements from arrayA to buckets in the array
            }
            for(int i = 0; i < arrayB.Length; i++)
            {
                arrayB[i].Sort();            //sort each bucker
            }
            int k = 0;
            
            for (int i = 0; i < arrayB.Length; i++)
            {
                for(int j = 0; j < arrayB[i].Count(); j++)       //concatinate all the arrays together back into the array
                { 
                    arrayA[k] = arrayB[i][j];
                    k++;
                }
            }
        }

        /// <summary>
        /// Times radix sort with the given array
        /// </summary>
        /// <param name="array">
        /// the given array
        /// </param>
        /// <returns>
        /// the time elapsed
        /// </returns>
        public static long TimeRadixSort(int[] array)
        {
            long startTime = GenFunctions.NanoTime();

            RadixSort(array);

            long endTime = GenFunctions.NanoTime();

            long timeElapsed = endTime - startTime;

            return timeElapsed;
        }

        /// <summary>
        /// times bucket sort with the given array
        /// </summary>
        /// <param name="array">
        /// the given array
        /// </param>
        /// <returns>
        /// the time elapsed 
        /// </returns>
        public static long TimeBucketSort(int[] array)
        {
            long startTime = GenFunctions.NanoTime();

            BucketSort(array);

            long endTime = GenFunctions.NanoTime();

            long timeElapsed = endTime - startTime;

            return timeElapsed;
        }
    }
}


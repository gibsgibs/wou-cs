///Gabriel Brehm
///CS361
///Lab01
///Colaborators: Jacob Malmstadt

using System;

namespace cs361_lab01
{
    public class Sort
    {
        /// <summary>
        /// Creats two lists of the first and second half of the given list, which are each assumed to be sorted, and merges them together.
        /// Assistence with this method from http://csharpexamples.com/c-merge-sort-algorithm-implementation/, and from our textbook.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the list as an int.
        /// </param>
        /// <param name="middleIndex">
        /// The middle index of the list as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        public static void Merge(int[] list, int startIndex, int middleIndex, int endIndex)
        {
            int leftHalfLength = middleIndex - startIndex + 1;      //calculate the length of the left half list

            int rightHalfLength = endIndex - middleIndex;           //calculate the length of the right half list

            int[] leftList = new int[leftHalfLength + 1];           //makes a new list on the heap that is 1 larger then the left half

            int[] rightList = new int[rightHalfLength + 1];         //makes a new list on the heap that is 1 larger than the right half

            for(int i = 0; i < leftHalfLength; i++)
            {
                leftList[i] = list[startIndex + i];                 //copies the left half of the given list into the leftList
            }

            for(int i = 0; i < rightHalfLength; i++)
            {
                rightList[i] = list[middleIndex + 1 + i];           //copies the right hald of the given list into the rightList
            }

            leftList[leftHalfLength] = Int32.MaxValue;              //the sentinal value for the leftList

            rightList[rightHalfLength] = Int32.MaxValue;            //the sentinal value for the rightList

            int leftIndex = 0;                                      

            int rightIndex = 0;

            for(int k = startIndex; k < endIndex + 1; k++)
            {
                if(leftList[leftIndex] <= rightList[rightIndex])    //sets list of k equal to the smaller of two values: rightList of rightIndex and leftList of leftIndex.
                {
                    list[k] = leftList[leftIndex];

                    leftIndex++;
                }
                else 
                {
                    list[k] = rightList[rightIndex];

                    rightIndex++;
                }
            }
        }

        /// <summary>
        /// This method used the Merge Sort technique to sort a given list of numbers. That is, it seperates the list recursivly into smaller and smaller size lists until each list is length 1. 
        /// It then recombines the lists in order, thus sorting the list. This method is assisted by the Merge Method defined above.
        /// Assistance with this method from our textbook.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the list as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        public static void MergeSort(int[] list, int startIndex, int endIndex)
        {
            if (startIndex < endIndex)
            {
                int middleIndex = GenFunctions.getMiddleIndex(startIndex, endIndex);

                MergeSort(list, startIndex, middleIndex);

                MergeSort(list, middleIndex + 1, endIndex);

                Merge(list, startIndex, middleIndex, endIndex);

            }            
        }

        /// <summary>
        /// Partitions the given array into two groups: one less than or equal to the last value, and one greater than it. Then it places that last value in between the two sets.
        /// Finally, it returns the index of that value plus one.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        /// <returns>
        /// The index of the pivot value as an int.
        ///  </returns>
        public static int Partition(int[] list, int startIndex, int endIndex)
        {

            int pivot = list[endIndex];                 //sets the pivot to the last value in the list

            int i = startIndex - 1;                     //sets the i index to the start index minus 1

            for (int j = startIndex; j < endIndex; j++)
            {
                if (list[j] <= pivot)                    //if the jth value is less than or equal to the pivot, switch the jth value and the ith value
                {
                    i++;

                    int temp1 = list[j];

                    list[j] = list[i];

                    list[i] = temp1;
                }
            }                                           //after the loop, put the pivot value between the two partitions
            int temp2 = list[endIndex];

            list[endIndex] = list[i + 1];

            list[i + 1] = temp2;

            return i + 1;
        }

        /// <summary>
        /// This method generates a random number between startIndex and endIndex.
        /// It then swaps the value at that index with the value at the endIndex. Then Partition is called.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        /// <returns>
        /// The index of the pivot value as an int.
        ///  </returns>
        public static int RandomPartition(int[] list, int startIndex, int endIndex)
        {
            Random rand = new Random();

            int randomIndex = rand.Next(startIndex, endIndex);

            int temp = list[endIndex];

            list[endIndex] = list[randomIndex];

            list[randomIndex] = temp;

            return Partition(list, startIndex, endIndex);
        }
        
        /// <summary>
        /// This method gets the average of the values at the startIndex, endIndex, and middleIndex, mods it by the size of the list we are looking at.
        /// The value at that index is swaped with the value at the endInex, and then Partition is called.
        /// NOTE: This method, for whatever reason, does not work. I tried for hours to fix it, but to no avail.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        /// <returns>
        /// The index of the pivot value as an int.
        ///  </returns>
        public static int AveragePartition(int[] list, int startIndex, int endIndex)
        {
            int pivotIndex = (list[startIndex] / 3) + (list[endIndex] / 3) + (list[GenFunctions.getMiddleIndex(startIndex, endIndex)] / 3);

            pivotIndex = pivotIndex % (endIndex - startIndex);

            int temp = list[endIndex];

            list[endIndex] = list[pivotIndex];

            list[pivotIndex] = temp;

            return Partition(list, startIndex, endIndex);
        }
        /// <summary>
        /// Uses the Quicksort method to sort the given list of numbers. That is, it partitions the list, and then recursivly uses Quicksort on each partition.
        /// This method is assisted by the Partition method defined above.
        /// Assistance with this method from our textbook.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <param name="startIndex">
        /// The first index of the list as an int.
        /// </param>
        /// <param name="endIndex">
        /// The last index of the list as an int.
        /// </param>
        public static void Quicksort(int[] list, int startIndex, int endIndex)
        {
            if(startIndex < endIndex)
            {
                int middlleIndex = Partition(list, startIndex, endIndex);

                Quicksort(list, startIndex, middlleIndex - 1);

                Quicksort(list, middlleIndex + 1, endIndex);
            }
        }

        /// <summary>
        /// Times how long it taks to use Merge Sort on a given list of numbers.
        /// </summary>
        /// <param name="list">
        /// The given list of ints.
        /// </param>
        /// <returns>
        /// The time it took to sort as a long.
        /// </returns>
        public static long TimeMergeSort(int[] list)
        {
            long startTime = GenFunctions.NanoTime();

            MergeSort(list, 0, list.Length - 1);

            long endTime = GenFunctions.NanoTime();

            long timeElapsed = endTime - startTime;

            return timeElapsed;
        }

        /// <summary>
        /// Times how long it takes to use Quicksort on a given list of numbers.
        /// </summary>
        /// <param name="list">
        /// The list of numbers as an int.
        /// </param>
        /// <returns>
        /// The time it took to sort as a long.
        /// </returns>
        public static long TimeQuicksort(int[] list)
        {
            long startTime = GenFunctions.NanoTime();

            Quicksort(list, 0, list.Length - 1);

            long endTime = GenFunctions.NanoTime();

            long timeElapsed = endTime - startTime;

            return timeElapsed;
        }
    }
}


/**
  * @brief Search & Sort Big Oh Complexity Lab
  * @author Gabriel Brehm, Gibs
  */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <chrono>
#include <iostream>
using namespace std;

/**
 * @brief printArray - This function prints out the given
 *                     array of the given size.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void printArray(long* theArray, const long& theSize);
/**
 * @brief populateArray - This function populates the given
 *                        array of the given size with random
 *                        vlaues ranging from 0 to 99999.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void populateArray(long* theArray, const long& theSize);
/**
 * @brief bubbleSort - This function compares the element of
 *                     the given array of the given size to each
 *                     other and swaps so the larger element is closer
 *                     to the end of the array. Larger elements "bubble"
 *                     to the "top."
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void bubbleSort(long* theArray, const long& theSize);
/**
 * @brief selectionSort - This function goes through the elements of the
 *                        given array of the given size and selects the
 *                        next smallest and swaps them.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void selectionSort(long* theArray, const long& theSize);
/**
 * @brief insertionSort - This function considers the first element of the
 *                        given array of the given size to be sorted, and then
 *                        goes through and inserts the remaining elements into
 *                        the sorted array.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void insertionSort(long* theArray, const long& theSize);
/**
 * @brief linearSearch - This function goes though the given array of the
 *                       given size and compares each elment to the target value,
 *                       which it generates randomly.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 * @return bool - Returns a true if the target value was found, and returns false
 *                if the item was not found.
 */
bool linearSearch(long* theArray, const long& theSize);
/**
 * @brief binarySearch - This fucntion goes through the given array of the given
 *                       size by starting in the middle, determining if the element
 *                       at that index is equal to, less than, or grater than the
 *                       target value, which it generates randomly. If the targetValue
 *                       is equal to the element, it ends. Otherwise, it looks
 *                       at the remaining part of the array that could contain the
 *                       target value (the second half if the target value was
 *                       greater than the element, or the first half if the target
 *                       value was less than the element). It repeats this proccess
 *                       untill it finds the target value, or it searches the
 *                       entire array.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 * @return bool - Returns a true if the target value was found, and returns false
 *                if the item was not found.
 */
bool binarySearch(long* theArray, const long& theSize);
/**
 * @brief printBubbleSort - This function starts a timer, uses the bubbleSort function
 *                          on the given array of the given size, ends the timer, and prints
 *                          out the elapsed time in nanoseconds.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void printBubbleSort(long* theArray, const long& theSize);
/**
 * @brief printSelectionSort - This function starts a timer, uses the selectionSort function
 *                             on the given array of the given size, ends the timer, and prints
 *                             out the elapsed time in nanoseconds.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void printSelectionSort(long* theArray, const long& theSize);
/**
 * @brief printInsertionSort - This function starts a timer, uses the insertionSort function
 *                             on the given array of the given size, ends the timer, and prints
 *                             out the elapsed time in nanoseconds.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void printInsertionSort(long* theArray, const long& theSize);
/**
 * @brief printLinearSearch - This function starts a timer, uses the linearSearch function
 *                            on the given array of the given size, ends the timer, and prints
 *                            out the elapsed time in nanoseconds, and it prints out if it
 *                            found the target value.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void printLinearSearch(long* theArray, const long& theSize);
/**
 * @brief printBinarySearch - This function starts a timer, uses the binarySearch function
 *                            on the given array of the given size, ends the timer, and prints
 *                            out the elapsed time in nanoseconds, and it prints out if it
 *                            found the target value.
 * @param theArray - The given array.
 * @param theSize - The size of the given array.
 */
void printBinarySearch(long* theArray, const long& theSize);

#endif // FUNCTIONS_H

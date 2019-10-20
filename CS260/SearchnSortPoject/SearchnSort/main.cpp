/**
  * @brief Search & Sort Big Oh Lab
  * @author Gabriel Brehm, Gibs
  */

#include "Functions.h"

int main()
{
    srand(time(0));

    long size = 100;
    //creating the array on the heap so we can use a variable size
    long* array = new long[size];

    //preforming each of the sorts/searches in turn
//    printBubbleSort(array, size);
//    printSelectionSort(array, size);
//    printInsertionSort(array, size);
//    printLinearSearch(array, size);
//    printBinarySearch(array, size);

    delete [] array;

    long* list = new long;
    selectionSort(list, 7);

    return 0;
}

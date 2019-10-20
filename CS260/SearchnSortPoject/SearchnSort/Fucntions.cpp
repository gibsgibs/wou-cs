/**
  * @brief Search & Sort Big Oh Complexity Lab
  * @author Gabriel Brehm, Gibs
  */

#include "Functions.h"

void printArray(long* theArray, const long& theSize)
{
    cout << "-----------------------------------------------------------------------------"
         << endl;
    for(int i = 0; i < theSize; i++)
    {
        cout << theArray[i]
             << "\t";
    }
    cout << "-----------------------------------------------------------------------------"
         << endl;
}

void populateArray(long* theArray, const long& theSize)
{
    for(int i = 0; i < theSize; i++)
    {
        theArray[i] = ((rand() * (RAND_MAX + 1)) + rand()) % 100000;
    }
}

void bubbleSort(long* theArray, const long& theSize)
{
    long long comparisons = 0;
    for(int i = theSize - 1; i >= 0; i--)
    {
        int swaps = 0;
        for(int j = 1; j <= i; j++)
        {
            comparisons++;
            if(theArray[j - 1] > theArray[j])
            {
                int temp = theArray[j - 1];
                theArray[j - 1] = theArray[j];
                theArray[j] = temp;
                swaps++;
            }
        }
        if(swaps == 0 && i != 0)
        {
            cout << "Sort Complete - Early exit:\n"
                 << "Comparisons made: "
                 << comparisons
                 << ".\n";
            return;
        }
        else if(i == 0)
        {
            cout << "Sort Complete:\n"
                 << "Comparisons made: "
                 << comparisons
                 << ".\n";
        }
    }
}

void selectionSort(long* theArray, const long& theSize)
{
    long long comparisons = 0;
    for(int i = 0; i < theSize - 1; i++)
    {
        int minnimum = i;
        for(int j = i + 1; j < theSize; j++)
        {
            comparisons++;
            if(theArray[j] < theArray[minnimum])
            {
                minnimum = j;
            }
        }
        int temp = theArray[i];
        theArray[i] = theArray[minnimum];
        theArray[minnimum] = temp;
    }
    cout << "Sort Complete:\n"
         << "Comparisons made: "
         << comparisons
         << ".\n";
}

void insertionSort(long* theArray, const long& theSize)
{
    long long comparisons = 0;
    for(int i = 1; i < theSize; i++)
    {
        int index = theArray[i];
        int j = i;
        while(j > 0 && theArray[j - 1] > index)
        {
            theArray[j] = theArray[j - 1];
            j--;
            comparisons++;
        }
        comparisons++;
        theArray[j] = index;
    }
    cout << "Sort Complete:\n"
         << "Comparisons made: "
         << comparisons
         << ".\n";
}

bool linearSearch(long *theArray, const long &theSize)
{
    long long comparisons = 0;

    bool result = false;
    long targetValue = ((rand() * (RAND_MAX + 1)) + rand()) % 100000;

    int i = 0;
    while(result == false && i < theSize)
    {
        comparisons++;
        if(theArray[i] == targetValue)
        {
            result = true;
        }
        i++;
    }
    cout << "Search Complete:\n"
         << comparisons
         << " comparisons made.\n";
    if(result == true)
    {
        return true;
    }
    else
        return false;
}

bool binarySearch(long *theArray, const long &theSize)
{
    long long comparisons = 0;

    bool result = false;
    long targetValue = ((rand() * (RAND_MAX + 1)) + rand()) % 100000;

    int i = 0;
    long low = 0;
    long high = theSize - 1;
    while(result == false && i < theSize && low <= high)
    {

        long mid = (high + low) / 2;
        if(theArray[mid] == targetValue)
        {
            result = true;
        }
        else if(theArray[mid] > targetValue)
        {
            high = mid - 1;
        }
        else if(theArray[mid] < targetValue)
        {
            low = mid + 1;
        }
        comparisons++;
        i++;
    }
    cout << "Search Complete:\n"
         << comparisons
         << " comparisons made.\n";
    if(result == true)
    {
        return true;
    }
    else
        return false;

}

void printBubbleSort(long *theArray, const long &theSize)
{
    cout << "BUBBLE SORT:\n";
    populateArray(theArray, theSize);
    auto startTime = chrono::high_resolution_clock::now();
    bubbleSort(theArray, theSize);
    auto endTime = chrono::high_resolution_clock::now();
    cout << "Time Elapsed: "
         << chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count()
         << " nanoseconds.\n";
}

void printSelectionSort(long *theArray, const long &theSize)
{
    cout << "\nSELECTION SORT:\n";
    populateArray(theArray, theSize);
    auto startTime = chrono::high_resolution_clock::now();
    selectionSort(theArray, theSize);
    auto endTime = chrono::high_resolution_clock::now();

    cout << "Time Elapsed: "
         << chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count()
         << " nanoseconds.\n";
}

void printInsertionSort(long* theArray, const long& theSize)
{
    cout << "\nINSERTION SORT:\n";
    populateArray(theArray, theSize);
    auto startTime = chrono::high_resolution_clock::now();
    insertionSort(theArray, theSize);
    auto endTime = chrono::high_resolution_clock::now();
    cout << "Time Elapsed: "
         << chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count()
         << " nanoseconds.\n";
}

void printLinearSearch(long *theArray, const long &theSize)
{
    cout << "\nLINEAR SEARCH:\n";
    auto startTime = chrono::high_resolution_clock::now();
    bool resultL = linearSearch(theArray, theSize);
    auto endTime = chrono::high_resolution_clock::now();
    if(resultL == true)
        cout << "Target found.\n";
    else
        cout << "Target not found.\n";
    cout << "Time Elapsed: "
         << chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count()
         << " nanoseconds.\n\n";
}

void printBinarySearch(long *theArray, const long &theSize)
{
    cout << "BINARY SEARCH:\n";
    auto startTime = chrono::high_resolution_clock::now();
    bool resultB = binarySearch(theArray, theSize);
    auto endTime = chrono::high_resolution_clock::now();
    if(resultB == true)
        cout << "Target found.\n";
    else
        cout << "Target not found.\n";
    cout << "Time Elapsed: "
         << chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count()
         << " nanoseconds.\n\n";
}

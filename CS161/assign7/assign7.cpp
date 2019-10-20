/**
  * @brief Assignment 7
  * @authors Gabriel Brehm, Kat R., Jose A.
  */

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @brief getData - read elevation data into the array from the console
 * @param heights
 * @param size
 */
void getData(int heights[], int size)
{
    for(int i = 0; i < size; i++)
        cin >> heights[i];
}
/**
 * @brief getHighestPointBetween - return the highest elevation between the two mile markers(inclusive)
 * @param heights
 * @param startMile
 * @param endMile
 * @return highestPoint
 */
int getHighestPointBetween(const int heights[], int startMile, int endMile)
{
    int highestPoint = 0;
    for(int i = startMile; i <= endMile; i++)
    {
        if(heights[i] > highestPoint)
            highestPoint = heights[i];
    }
    return highestPoint;
}
/**
 * @brief getAverage - retrun the average elevation
 * @param heights
 * @param size
 * @return avergeElevation
 */
double getAverage(const int heights[], int size)
{
    double averageElevation = 0;

    for(int i = static_cast<int>(averageElevation); i < size; i++)
    {
        averageElevation += heights[i];
    }
    averageElevation = averageElevation / size;

    return averageElevation;
}
/**
 * @brief getNumPeaks - return the number of peaks in the hike
 * @param heights
 * @param size
 * @return numberPeaks
 */
int getNumPeaks(const int heights[], int size)
{
    int numberPeaks = 0;

    for(int i = numberPeaks; i < size - 1; i++)
        if(heights[i] > heights[i - 1] &&
                heights[i] > heights[i + 1])
        {
            numberPeaks++;
        }
    return numberPeaks;
}
/**
 * @brief getNumSteepSegments - return the number of segments that end with a change of more than 1000 feet
 * @param heights
 * @param size
 * @return numberSteepSegments
 */
int getNumSteepSegments(const int heights[], int size)
{
    int numberSteepSegments = 0;

    for(int i = numberSteepSegments; i < size; i++)
    {
        if((heights[i] - heights[i + 1]) >= 1000)
            numberSteepSegments++;
    }
    return numberSteepSegments;
}
/**
 * @brief getTotalChange - return the total elevation change over the range from startMile to endMile (inclusive).
 * @param heights
 * @param startMile
 * @param endMile
 * @return totalChange
 */
int getTotalChange(const int heights[], int startMile, int endMile)
{
    int totalChange = 0;

    for(int i = startMile; i < endMile; i++)
    {
        int difference = heights[i + 1] - heights[i];
        if(difference < 0)
            difference = -1 * difference;
        totalChange += difference;
    }
    return totalChange;
}

int main() //Use these numbers as a test: 1200 3000 3450 2800 2900 1550 1750 1110 1200
{
    const int HIKE_LENGTH = 9;
    int elevations[HIKE_LENGTH];

    getData(elevations, HIKE_LENGTH);

    cout << fixed << setprecision(2)
         << "Highest points: " << endl
         << "\tFirst half: "
         << getHighestPointBetween(elevations, 0, (HIKE_LENGTH / 2)) << endl
         << "\tSecond half: "
         << getHighestPointBetween(elevations, (HIKE_LENGTH / 2) + 1, HIKE_LENGTH) << endl
         << "\tOverall: "
         << getHighestPointBetween(elevations, 0, HIKE_LENGTH) << endl
         << "Average elevation: "
         << getAverage(elevations, HIKE_LENGTH) << endl
         << "Peaks: "
         << getNumPeaks(elevations, HIKE_LENGTH) << endl
         << "Difficult segments: "
         << getNumSteepSegments(elevations, HIKE_LENGTH) << endl
         << "Elevation change: "
         << getTotalChange(elevations, 0, HIKE_LENGTH - 1) << endl;
    return 0;
}

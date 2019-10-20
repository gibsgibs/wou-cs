
#include <iostream>
#include "RadiationCheck.h"

using namespace std;

int main()
{
    cout << "@ = a person," << endl
         << "# = a wall," << endl
         << "X = the contaminant, and" << endl
         << "~ = contaminated area." << endl << endl;

    char grid[GRID_SIZE][GRID_SIZE];
    populateGrid(grid);
    int x = -1;
    int y = -1;
    int count = 1;
    int* counter = &count;
    cout << "Enter the location of the contaminant (x y): ";
    cin >> x >> y;
    inputContaminant(grid, x, y);
    inputWalls(grid);
    contaminate(grid, x, y, *counter);
    printGrid(grid);
    if(saftyCheck(grid) == true)
    {
        cout << "Safe! Contaminated area: "
             << count
             << endl;
    }
    else
    {
        cout << "Unsafe!"
             << endl;
    }
}
/*
5 5
2 2
3 2
4 2
2 3
4 3
5 3
2 4
5 4
6 4
2 5
6 5
2 6
3 6
4 6
5 6
0 0
  */

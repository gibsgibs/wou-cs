#include "RadiationCheck.h"

void populateGrid(char theGrid[GRID_SIZE][GRID_SIZE])
{
    for(int col = 0; col < GRID_SIZE; col++)
    {
        for(int row = 0; row < GRID_SIZE; row++)
        {
            theGrid[col][row] = ' ';
        }
    }
    theGrid[0][0] = '@';
}

void printGrid(char theGrid[GRID_SIZE][GRID_SIZE])
{
    cout << "  0 1 2 3 4 5 6 7 8 9"
         << endl;
    for(int col = 0; col < GRID_SIZE; col++)
    {
        cout << col << " ";
        for(int row = 0; row < GRID_SIZE; row++)
        {
            cout << theGrid[col][row] << " ";
        }
        cout << endl;
    }
}

void inputContaminant(char theGrid[GRID_SIZE][GRID_SIZE], int xLoc, int yLoc)
{
    if(theGrid[xLoc][yLoc] == ' ')
    {
        theGrid[xLoc][yLoc] = 'X';
    }
    else
    {
        cout << "There's a person there..."
             << endl;
    }
}

void inputWalls(char theGrid[GRID_SIZE][GRID_SIZE])
{
    cout << "Enter location of wall (x y)"
         << endl
         << "Note: input of (0 0) will terminate:"
         << endl;
    int xLoc = -1, yLoc = -1;
    cin >> xLoc >> yLoc;
    while(xLoc != 0 && yLoc != 0)
    {
        cin >> xLoc >> yLoc;
        if(theGrid[yLoc][xLoc] == ' ')
        {
            theGrid[yLoc][xLoc] = '#';
        }
        else if(xLoc != 0 && yLoc != 0)
        {
            cout << "Error: space occupied!"
                 << endl;
        }
    }
}

void contaminate(char theGrid[GRID_SIZE][GRID_SIZE],
                 int startRow, int startCol, int &theCount)
{
    if(startRow < 0 || startCol < 0 ||
       startRow > GRID_SIZE || startCol > GRID_SIZE)
    {
        return;
    }
    if(theGrid[startRow][startCol] != 'X' && theGrid[startRow][startCol] != '@'
                                          && theGrid[startRow][startCol] != ' ')
    {
        return;
    }
    if(theGrid[startRow][startCol] == ' ')
    {
       theGrid[startRow][startCol] = '~';
       theCount++;
    }

    contaminate(theGrid, startRow, startCol - 1, theCount);
    contaminate(theGrid, startRow, startCol + 1, theCount);
    contaminate(theGrid, startRow - 1, startCol, theCount);
    contaminate(theGrid, startRow + 1, startCol, theCount);
    contaminate(theGrid, startRow - 1, startCol - 1, theCount);
    contaminate(theGrid, startRow + 1, startCol + 1, theCount);
    contaminate(theGrid, startRow - 1, startCol + 1, theCount);
    contaminate(theGrid, startRow + 1, startCol - 1, theCount);
}

bool saftyCheck(char theGrid[GRID_SIZE][GRID_SIZE])
{
    bool result = true;
    for(int i = 0; i < GRID_SIZE; i++)
    {
        if(theGrid[9][i] == '~' || theGrid[i][9] == '~')
        {
            result = false;
        }
        else
        {
            for(int j = 0; j < GRID_SIZE; j++)
            {
                for(int k = 0; k < GRID_SIZE; k++)
                {
                    if(theGrid[j][k] == '@')
                    {
                        result = true;
                    }
                }
            }
        }
    }
    return result;
}

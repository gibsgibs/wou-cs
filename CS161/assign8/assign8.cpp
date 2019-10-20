/**
  * @brief Assignment 8
  * @authors Jacob Malmstadt and Gabe Brehm
  */

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;


/**
 * @brief setKeytoPuzzle, put the key array items, into the puzzle
 * @param key, input the key array
 * @param puzzle, input the puzzle array
 */
void setKeytoPuzzle(char key[NUM_ROWS][NUM_COLS], char puzzle[NUM_ROWS][NUM_COLS])
{
    for (int i = 0; i < NUM_ROWS; i++)
     {
        for (int j = 0; j < NUM_COLS; j++)
        {
            puzzle[i][j] = key[i][j];

        }
    }
}

/**
 * @brief makeKeyArray, take in a random 10by10 array fill it with spaces
 * @param matrix, take in the random array
 */
void makeKeyArray(char matrix[NUM_ROWS][NUM_COLS])
{
    for (int i = 0; i < NUM_ROWS; i++)
     {
        for (int j = 0; j < NUM_COLS; j++)
        {
            matrix[i][j] = '_';

        }
    }
}

/**
 * @brief makePuzzleArray, take in a random 10by10 array fill it with spaces
 * @param matrix, take in the random array
 */
void makePuzzleArray(char matrix[NUM_ROWS][NUM_COLS])
{
    for (int i = 0; i < NUM_ROWS; i++)
     {
        for (int j = 0; j < NUM_COLS; j++)
        {
            matrix[i][j] = '_';

        }
    }
}

/**
 * @brief getRandomUpperChar - generate a random uppercase letter
 * @return ch - random uppercase character
 */
char getRandomUpperChar()
    {
        const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char ch = chars[rand() % 26];
        return ch;
    }

/**
 * @brief makeIntoPuzzle - add the random uppercase letters into the puzzle to hide the hidden words
 * @param matrix
 */
void makeIntoPuzzle(char matrix[NUM_ROWS][NUM_COLS])
{
    for (int i = 0; i < NUM_ROWS; i++)
     {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (matrix[i][j] == '_')
            {
                matrix[i][j] = getRandomUpperChar();
            }
        }
     }
}

/**
 * @brief addHorizontalWord - add a horizontal word from the inputed row and column
 * @param matrix
 */
void addHorizontalWord(char matrix[NUM_ROWS][NUM_COLS])
{
    int row = 0;
    int column = 0;
    string word;
    cout << "Enter Row: ";
    cin >> row;
    cout << "Enter Column: ";
    cin >> column;
    cout << "Enter Word: ";
    cin >> word;
    int length = word.length();
    if (word.length() + column < NUM_COLS)
        for (int i = 0; i < length; i++)
        {
            matrix[row-1][column-1] = word[i];
            column++;
        }
    else
        cout << "Error, does not fit";
}

/**
 * @brief addVerticalWord - add a vertical word from the inputed row and column
 * @param matrix
 */
void addVerticalWord(char matrix[NUM_ROWS][NUM_COLS])
{
    int row = 0;
    int column = 0;
    string word;
    cout << "Enter Row: ";
    cin >> row;
    cout << "Enter Column: ";
    cin >> column;
    cout << "Enter Word: ";
    cin >> word;
    int length = word.length();
    if (word.length() + row < NUM_ROWS)
        for (int i = 0; i < length; i++)
        {
            matrix[row-1][column-1] = word[i];
            row++;
        }
    else
        cout << "Error, does not fit";
}

/**
 * @brief horizontalWordCheck - checking if the horizontal word would fit into the word search
 * @param matrix
 */
void horizontalWordCheck(char matrix[NUM_ROWS][NUM_COLS])
{
    int row = 0;
    int column = 0;
    string word;
    cout << "Enter Row: ";
    cin >> row;
    cout << "Enter Column: ";
    cin >> column;
    cout << "Enter Word: ";
    cin >> word;
    int length = word.length();
    string answer = " ";
    if (length + column - 1 <= NUM_COLS)
    {    //needs to fit for input as in all letters already on the word search need to match up if input overlaps
        for (int i = 0; i < length; i++)
        {
            if (matrix[row-1][column-1] == ' ' || matrix[row-1][column-1] == word.at(i))
            {
                answer = "Fits";
            }
            else
            {
                answer = "Does not fit";
                i = length;
            }
            column++;
        }
        cout << answer << endl;
    }
    else
        cout << "Does not fit" << endl;
}


/**
 * @brief spacesCount - count how many spaces there are in the puzzle
 * @param matrix
 */
void spacesCount(char matrix[NUM_ROWS][NUM_COLS])
{
    int spaces = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
       for (int j = 0; j < NUM_COLS; j++)
       {
           if (matrix[i][j] == '_')
               spaces++;
       }
    }
    cout << "Spaces: " << spaces << endl;
}



int main()
{
    //Initialize a word search with all spaces
    char key[NUM_ROWS][NUM_COLS];
    char puzzle[NUM_ROWS][NUM_COLS];
    makeKeyArray(key);
    makePuzzleArray(puzzle);


    int input = 0;

    while (input != 8)
    {
        setKeytoPuzzle(key, puzzle);
        makeIntoPuzzle(puzzle);
        //Menu
        cout << "\n1: Print key\n2: Print puzzle\n3: Add horizontal word\n"
                "4: Add vertical word\n5: Check horizontal fit\n"
                "6: Space count\n8: Quit\n" << "Enter input: ";
        cin >> input;
        cout << endl;

        if (input == 1) //Option 1
        {
            for (int i = 0; i < NUM_ROWS; i++)
            {
               for (int j = 0; j < NUM_COLS; j++)
                   cout << key[i][j] << " ";
               cout << endl;
            }
        }
        if (input == 2) //Option 2
        {
            for (int i = 0; i < NUM_ROWS; i++)
            {
               for (int j = 0; j < NUM_COLS; j++)
                   cout << puzzle[i][j] << " ";
               cout << endl;
            }
        }
        if (input == 3) //Option 3
        {
            addHorizontalWord(key);
        }
        if (input == 4) //Option 4
        {
            addVerticalWord(key);
        }
        if (input == 5) //Option 5
        {
            horizontalWordCheck(key);
        }
        if (input == 6) //Option 6
        {
            spacesCount(key);
        }
        if (input == 8) //Option 8
        {
            exit(0);
        }
    }


    return 0;
}

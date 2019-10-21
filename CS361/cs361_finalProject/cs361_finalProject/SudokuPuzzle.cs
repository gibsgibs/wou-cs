///CS361
///Final Project
///Colaborators: Jacob Malmstadt

using System;
using System.Linq;
using System.Collections.Generic;

namespace cs361_finalProject
{
    class SudokuPuzzle : PuzzleDatabase
    { 
        private string[,] solution; 

        private readonly string[,] puzzle;

        /// <summary>
        /// Constructor.
        /// </summary>
        public SudokuPuzzle()
        {
            Random random = new Random();

            int index = random.Next(puzzles.Count);

            puzzle = puzzles[index];

            solution = Solver();

        }

        /// <summary>
        /// Determines if the given width is valid for a Sudoku puzzle.
        /// </summary>
        /// <param name="width">
        /// The given width of the puzzle.
        /// </param>
        /// <returns>
        /// True if the width is valid, false otherwise.
        /// </returns>
        private bool IsValidWidth(int width)
        {
            double widthAsDouble = Convert.ToDouble(width);

            int wholePortion = (int)Math.Truncate(Math.Sqrt(widthAsDouble));
            if(Math.Sqrt(widthAsDouble) - wholePortion == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// Creates an array containing the integes from 1 to width inclusive, in a random order.
        /// </summary>
        /// <param name="width">
        /// The given width of the puzzle.
        /// </param>
        /// <returns>
        /// The array of randomly ordered integers.
        /// </returns>
        private int[] RandNumbers(int width)
        {
            int[] result = new int[width];

            Random random = new Random();

            for(int i = 0; i < result.Length; i++)
            {
                int rand = random.Next(1, width + 1);

                while (result.Contains(rand))
                {
                    rand = random.Next(1, width + 1);
                }
                result[i] = rand;
            }
            return result;
        }

        /// <summary>
        /// Determines if the given value can be placed in the given coordinates of the given puzzle grid.
        /// </summary>
        /// <param name="grid">
        /// The given puzzle grid.
        /// </param>
        /// <param name="i">
        /// The row of the puzzle grid.
        /// </param>
        /// <param name="j">
        /// The column of the puzzle grid.
        /// </param>
        /// <param name="value">
        /// The given value.
        /// </param>
        /// <returns>
        /// Returns true if the value is valid, and false otherwise.
        /// </returns>
        private bool IsValidValue(string[,] grid, int i, int j, int value)
        {
            int width = puzzle.GetLength(0) - 1;

            for (int k = 1; k < grid.GetLength(0); k++)
            {
                if(value == 0)
                {
                    return false;
                }
                if(grid[i, k] == value.ToString() || grid[k, j] == value.ToString())
                {
                    return false;
                }
                int subSquareSize = (int)Math.Sqrt(width);

                int m = (i - 1) / subSquareSize;

                int n = (j - 1) / subSquareSize;

                for(int p = (m * subSquareSize + 1); p <= (m * subSquareSize + subSquareSize); p++)
                {
                    for(int q = (n * subSquareSize + 1); q <= (n * subSquareSize + subSquareSize); q++)
                    {
                        if(grid[p, q] == value.ToString())
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        /// <summary>
        /// Clears the given row of the given puzzle grid.
        /// </summary>
        /// <param name="grid">
        /// The given puzzle grid.
        /// </param>
        /// <param name="i">
        /// The given row.
        /// </param>
        /// <returns>
        /// The grid with a cleared row.
        /// </returns>
        private string[,] ClearRow(string[,] grid, int i)
        {
            for(int j = 0; j < grid.GetLength(1); j++)
            {
                grid[i, j] = puzzle[i, j];
            }
            return grid;
        }
        
        /// <summary>
        /// My version of a sudoku puzzle solver. It is not very fast.
        /// </summary>
        /// <returns>
        /// Returns the solved sudoku puzzle.
        /// </returns>
        public string[,] Solver()
        {
            int width = puzzle.GetLength(0) - 1;

            string[,] result = new string[width + 1, width + 1];

            for (int i = 1; i < puzzle.GetLength(0); i++)
            {
                for (int j = 1; j < puzzle.GetLength(1); j++)
                {
                    result[i, j] = puzzle[i, j];
                }
            }

            string tempi = null;

            string tempj = null;

            int lineCount = 1;

            for (int i = 1; i < result.GetLength(0); i++)
            {
                int counter = 0;

                for (int j = 1; j < result.GetLength(1); j++)
                {
                    int[] numbers = RandNumbers(width);

                    for(int k = 0; k < numbers.Length; k++)
                    {
                        if (IsValidValue(result, i, j, numbers[k]) && result[i, j] == null)
                        {
                            result[i, j] = numbers[k].ToString();

                        }
                    }
                    if (result[i, j] == null)
                    {
                        result = ClearRow(result, i);
                        
                        if (tempi != i.ToString() && tempj != j.ToString())
                        {
                            if (lineCount % 8 == 0)
                            {
                                Console.WriteLine("[" + i + ", " + j + "] ");
                            }
                            else
                            {
                                Console.Write("[" + i + ", " + j + "] ");
                            }
                            tempi = i.ToString();

                            tempj = j.ToString();

                            lineCount++;
                        }
                        counter++;

                        j = 0;
                    }
                    numbers = RandNumbers(width);

                    if (counter >= Math.Pow(2, width))
                    {
                        for (int p = 1; p < puzzle.GetLength(0); p++)
                        {
                            for (int q = 1; q < puzzle.GetLength(1); q++)
                            {
                                result[p, q] = puzzle[p, q];
                            }
                        }
                        i = 0;

                        j = 0;

                        break;
                    }
                }
            }
            Console.WriteLine();

            return result;
        }

        /// <summary>
        /// An approximation algorithm for solving a Sudoku puzzle. It is based on the following psudocode:
        /// 1.Enumerate all empty cells in typewriter order (left to right, top to bottom)
        /// 2.Our “current cell” is the first cell in the enumeration.
        /// 3.Enter a 1 into the current cell. If this violates the Sudoku condition, try entering a 2, then a 3, and so forth, until
        /// a. the entry does not violate the Sudoku condition, or until
        /// b.you have reached 9 and still violate the Sudoku condition.
        /// 4.In case a: if the current cell was the last enumerated one, then the puzzle is solved.If not, then go back to step 2 with the “current cell” being the next cell. 
        /// In case b: if the current cell is the first cell in the enumeration, then the Sudoku puzzle does not have a solution. If not, then erase the 9 from the corrent cell, call the previous cell in the enumeration the new “current cell”, and continue with step 3.
        /// Source: http://pi.math.cornell.edu/~mec/Summer2009/meerkamp/Site/Solving_any_Sudoku_I.html.
        /// </summary>
        /// <returns>
        /// The solved Sudoku puzzle.
        /// </returns>
        public string[,] SimpleSolver()
        {
            int width = puzzle.GetLength(0) - 1;

            string[,] result = new string[width + 1, width + 1];

            for (int i = 1; i < puzzle.GetLength(0); i++)
            {
                for (int j = 1; j < puzzle.GetLength(1); j++)
                {
                    result[i, j] = puzzle[i, j];
                }
            }
            Stack<Backtracker> backtrackers = new Stack<Backtracker>();

            string temp1 = null;

            string temp2 = null;

            int counter = 0;

            for (int i = 1; i < result.GetLength(0); i++)
            {
                for (int j = 1; j < result.GetLength(1); j++)
                {
                    
                    if (result[i, j] == null)
                    {
                        int[] numbers = RandNumbers(width);

                        for (int k = 0; k < numbers.Length; k++)
                        {
                            if (IsValidValue(result, i, j, numbers[k]) && numbers[k].ToString() != temp1 && numbers[k].ToString() != temp2)
                            {
                                result[i, j] = numbers[k].ToString();

                                temp2 = null;

                                temp1 = null;

                                Backtracker backtracker = new Backtracker(i, j, numbers[k].ToString());

                                backtrackers.Push(backtracker);

                                break;
                            }
                        }
                        if(result[i, j] == null)
                        {
                            if (counter == 1)
                            {
                                Backtracker backtracker1 = backtrackers.Pop();

                                result[backtracker1.GetRow(), backtracker1.GetColumn()] = null;

                                i = backtracker1.GetRow();

                                Console.WriteLine("[" + i + ", " + j + "]");

                                j = backtracker1.GetColumn() - 1;

                                temp2 = backtracker1.GetValue();

                                counter--;

                                continue;
                            }
                            Backtracker backtracker2 = backtrackers.Pop();

                            result[backtracker2.GetRow(), backtracker2.GetColumn()] = null;

                            i = backtracker2.GetRow();

                            Console.WriteLine("[" + i + ", " + j + "]");
                            
                            j = backtracker2.GetColumn() - 1;

                            temp1 = backtracker2.GetValue();

                            counter++;
                        }
                        numbers = RandNumbers(width);
                    }
                }
            }
            return result;
        }

        /// <summary>
        /// Prints out the solution to the puzzle.
        /// </summary>
        public void PrintSolution()
        {
            int width = puzzle.GetLength(0) - 1;

            if (IsValidWidth(width) == true && solution != null)
            {
                string label = "[SOLUTION: " + width.ToString() + "x" + width.ToString() + " Sudoku Puzzle]";
                GenFunctions.PrintTable(label, solution);
            }
        }

        /// <summary>
        /// Prints out the puzzle.
        /// </summary>
        public void PrintPuzzle()
        {
            int width = puzzle.GetLength(0) - 1;

            if (IsValidWidth(width) == true && puzzle != null)
            {
                string label = "[" + width.ToString() + "x" + width.ToString() + " Sudoku Puzzle]";
                GenFunctions.PrintTable(label, puzzle);
            }
        }
    }
}
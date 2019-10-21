///CS361
///Final Project
///Colaborators: Jacob Malmstadt

using System;

namespace cs361_finalProject
{
    class Program
    {
        static void Main(string[] args)
        {
            SudokuPuzzle myPuzzle1 = new SudokuPuzzle();

            myPuzzle1.PrintPuzzle();

            myPuzzle1.PrintSolution();
       
            GenFunctions.TextBox("Press ENTER to EXIT");

            Console.Read();
        }
    }
}

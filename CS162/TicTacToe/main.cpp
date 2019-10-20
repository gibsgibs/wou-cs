/**
  * @file main.cpp
  * @author Andrew Scholer
  * @brief Main function for a console based tic-tac-toe game.
  *         Do NOT modify this file. You need to write TicTacToe.h/TicTacToe.cpp
  *         to work with this file as is.
  */
#include <iostream>
#include <iomanip>
#include <string>

#include "TicTacToe.h"

using namespace std;

int main()
{
    cout << "Tic Tac Toe v0.1" << endl << endl;

    //create a TicTacToe object
    TicTacToe theGame;

    //keep playing until someone wins or no more moves
    while(!theGame.isDone()) {
        //show current state
        theGame.print();

        //ask who the current player is
        char playerName = theGame.getCurrentPlayer();

        //get their move
        cout << playerName << "'s turn. Enter row (1-3) and column (1-3): " << endl;
        int row, col;
        cin >> row >> col;

        //only make the move if it is valid...
        if(theGame.isValidMove(row, col)) {
            theGame.makeMove(row, col);
            //makeMove should change turn to next player
        } else {
            cout << "Invalid move." << endl;
            //will redo this player's turn next time through loop
        }
    }

    char winner = theGame.getWinner();

    cout << winner << " wins!"<< endl;

    return 0;
}

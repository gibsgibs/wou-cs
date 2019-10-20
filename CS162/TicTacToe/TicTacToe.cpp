/**
  * @file TicTacToe.cpp
  * @author Gabriel Brehm, Nick Harvey
  */
#include <iostream>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe()
{
    currentPlayer = 'X';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }
}
void TicTacToe::print()
{
    cout << "  0 1 2";
    for(int i = 0; i < 3; i++)
    {
        cout << endl
             << i
             << " ";
        for(int j = 0; j < 3 ; j++)
        {
            cout << board[i][j]
                 << " ";
        }
    }
    cout << endl;
}
char TicTacToe::getCurrentPlayer()
{
    return currentPlayer;
}
bool TicTacToe::isDone()
{
    bool isTrue;
    if((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '_')
            || (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] != '_')
            || (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][1] != '_')
            || (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] != '_')
            || (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != '_')
            || (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != '_')
            || (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '_')
            || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '_'))
    {
        isTrue = true;
    }
    else if(board[0][0] != '_' && board[0][1] != '_' && board[0][2] != '_' &&
           board[1][0] != '_' && board[1][1] != '_' && board[1][2] != '_' &&
           board[2][0] != '_' && board[2][1] != '_' && board[2][2] != '_')
    {
        isTrue = true;
    }
    else
        isTrue = false;
        return isTrue;
}
char TicTacToe::getWinner()
{
    if((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 'X')
            || (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] == 'X')
            || (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][1] == 'X')
            || (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] == 'X')
            || (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] == 'X')
            || (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] == 'X')
            || (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'X')
            || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'X'))
    {
        currentPlayer = 'X';
    }
    else if((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 'O')
            || (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] == 'O')
            || (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][1] == 'O')
            || (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] == 'O')
            || (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] == 'O')
            || (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] == 'O')
            || (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'O')
            || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'O'))
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'n';
    }
    return currentPlayer;
}

bool TicTacToe::isValidMove(int row, int col)
{
    if(board[row][col] == '_')
    {
        return true;
    }
    else
    {
        return false;
    }
}    
void TicTacToe::makeMove(int row, int col)
{
    if(getCurrentPlayer() == 'X')
    {
        board[row][col] = 'X';
        currentPlayer = 'O';
    }
    else
    {
        board[row][col] = 'O';
        currentPlayer = 'X';
    }
}

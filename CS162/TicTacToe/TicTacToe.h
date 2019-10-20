/**
  * @file TicTacToe.h
  * @author Gabriel Brehm, Nick Harvey
  */

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
private:
    char currentPlayer;
    char board[3][3];
public:
    TicTacToe();
    /**
     * @brief print - prints the current state of the board
     */
    void print();
    /**
     * @brief getCurrentPlayer - this function returns who's turn it is ('X''s or 'O''s)
     * @return the current player
     */
    char getCurrentPlayer();
    /**
     * @brief isDone - checks whether or not the game is done
     *  either by someone winning or by the board being full
     * @return true or false
     */
    bool isDone();
    /**
     * @brief getWinner - determines who won the game
     * @return the char 'X', 'O', or 'n' (for no one)
     */
    char getWinner();
    /**
     * @brief isValidMove checks the rows and columns to see
     * if the desired move is valid
     * @param row is how many rows the array has
     * @param col is how many columns the array has
     * @return true or false
     */
    bool isValidMove(int row, int col);
    /**
     * @brief makeMove places the indicated value at the given location.
     * Also changes the current player
     * @param row is the row of the given location
     * @param col is the column of the given location
     */
    void makeMove(int row, int col);
};

#endif // TICTACTOE_H

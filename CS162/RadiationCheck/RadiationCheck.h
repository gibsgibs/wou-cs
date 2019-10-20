/**
  * @title - assign8 CS162
  * @authors - Gabe Brehm, Jacob Malmstadt
  */

#ifndef TENBYTENGRID_H
#define TENBYTENGRID_H

#include <iostream>
#include <cmath>
using namespace std;

int const GRID_SIZE = 10;
/**
 * @brief populateGrid - populates the grid with blank spaces, and then puts a person at (0, 0)
 * @param theGrid - the grid that is passed in
 */
void populateGrid(char theGrid[GRID_SIZE][GRID_SIZE]);
/**
 * @brief printGrid - prints out the grid
 * @param theGrid - the grid that is passed in
 */
void printGrid(char theGrid[GRID_SIZE][GRID_SIZE]);
/**
 * @brief inputContaminant - takes in a user input for the location of the contaminant
 * @param theGrid - the grid that is passed in
 * @param xLoc - the x value of the contaminant
 * @param yLoc - the y value of the contaminant
 */
void inputContaminant(char theGrid[GRID_SIZE][GRID_SIZE], int xLoc, int yLoc);
/**
 * @brief inputWalls - takes in user input for the locations of the walls, and terminates upon input of (0, 0)
 * @param theGrid - the grid that is passed in
 */
void inputWalls(char theGrid[GRID_SIZE][GRID_SIZE]);
/**
 * @brief contaminate - a resursive function that contaminates the grid, based on location of the contaminant, and the walls
 * @param theGrid - the grid that is passed in
 * @param startRow - the x value of the contaminant
 * @param startCol - the y value of the contaminant
 * @param theCount - the address of a pointer to a variable
 */
void contaminate(char theGrid[GRID_SIZE][GRID_SIZE], int startRow, int startCol, int &theCount);
/**
 * @brief saftyCheck
 * @param theGrid - the grid that is passed in
 * @return - the result; true or false
 */
bool saftyCheck(char theGrid[GRID_SIZE][GRID_SIZE]);

#endif // TENBYTENGRID_H

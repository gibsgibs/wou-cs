/**
  * @brief Assignment 1 Problem 1
  * @author Gabriel Brehm
  */

#include <iostream>
using namespace std;

int main()
{
//declaring all of my variables

    int inches = 0;

    int feet = 0;

    int yards = 0;

    int miles = 0;

//asking for imput from user

    cout << "Enter the number of inches: ";

// conversions

    cin >> inches;

    {miles = inches / 63360;

        inches = inches % 63360;}

    {yards = inches / 36;

        inches = inches % 36;}

    {feet = inches / 12;

        inches = inches % 12;}

//outputting amounts of each measurment

                cout << miles << " mile(s)" << endl;

                cout << yards << " yard(s)"<< endl;

                cout << feet << " foot/feet" <<endl;

                cout << inches << " inch(es)" << endl;

    return 0;
}

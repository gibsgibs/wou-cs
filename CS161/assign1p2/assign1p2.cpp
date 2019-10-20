/**
  * @brief Assignment 1 Problem 2
  * @author Gabriel Brehm
  */

#include <iostream>
#include <cmath>
using namespace std;

int main()

{
//declaring my variables

    double windSpeed = 0;

    double degreesF = 0;

    double windChill = 0;

//prompting the user for imput

        cout << "Enter the temperature in Fahrenheit: ";

//taking in data from the user and stroing it in variables

        cin >> degreesF;

        cout << "Enter the wind speed in MPH: ";

        cin >> windSpeed;

//calculating windchill

      windChill = 35.74 + 0.6215 * degreesF
                - 35.75 * pow(windSpeed, 0.16)
                + 0.4275 * degreesF * pow(windSpeed, 0.16);

//outputting answer

            cout << "The wind chill index is " << windChill << endl;
    return 0;
}

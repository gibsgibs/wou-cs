/**
  * @brief Assignment 3
  * @author Gabriel Brehm and Kat Reynoso
  */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
//declaring variables and assigning user imput to them
    double sidea, sideb, angleA, angleB, angleC;
    cout << "Enter a: ";
    cin  >> sidea;
    cout << "Enter b: ";
    cin  >> sideb;
    cout << "Enter A: ";
    cin  >> angleA;
//creating a double constant of PI for ease of calculating, and changing the value of angleA to radians from degrees
    const double PI = 3.14159;
    angleA = angleA * (PI/180);

    if(angleA < PI/2 && sidea <= sideb){

        if(sideb > sidea && sidea > round(sideb * sin(angleA))){
                double angleB1, angleC1;
                angleB = asin(sideb * sin(angleA)/sidea);
                angleC = PI - angleA - angleB;
                angleB1 = PI - angleB;
                angleC1 = PI - (angleB1 + angleA);
                angleB = round (angleB * 180/PI);
                angleC = round (angleC * 180/PI);
                angleB1 = round (angleB1 * 180/PI);
                angleC1 = round (angleC1 * 180/PI);
                cout << "Angle B = " << angleB << " degrees" << endl
                     << "Angle C = " << angleC << " degrees" << endl
                     << "OR" << endl
                     << "Angle B = " << angleB1 << " degrees" << endl
                     << "Angle C = " << angleC1 << " degrees" << endl;
        }
        else if(sidea == round(sideb * sin(angleA))){
                angleB = asin(sideb * sin(angleA)/sidea);
                angleC = PI - angleA - angleB;
                angleB = round (angleB * 180/PI);
                angleC = round (angleC * 180/PI);
                cout << "Angle B = " << angleB << " degrees" << endl
                     << "Angle C = " << angleC << " degrees" << endl;
        }
        else if(sidea < round(sideb * sin(angleA))){
                cout << "No solution."
                     << endl;
        }
    }
    else if(angleA < PI/2 && sidea >= sideb){

                angleB = asin(sideb * sin(angleA)/sidea);
                angleC = PI - angleA - angleB;
                angleB = round (angleB * 180/PI);
                angleC = round (angleC * 180/PI);
                cout << "Angle B = " << angleB << " degrees" << endl
                     << "Angle C = " << angleC << " degrees" << endl;
    }
    else if(angleA > PI/2 || angleA == PI/2){

         if(sidea <= sideb){
        cout << "No solution."
             << endl;
        }
        else
                angleB = asin(sideb * sin(angleA)/sidea);
                angleC = PI - angleA - angleB;
                angleB = round (angleB * 180/PI);
                angleC = round (angleC * 180/PI);
                cout << "Angle B = " << angleB << " degrees" << endl
                     << "Angle C = " << angleC << " degrees" << endl;
    }

    return 0;
}

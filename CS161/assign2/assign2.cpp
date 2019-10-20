/**
  * @brief Assignment 2
  * @authors Gabriel Brehm and Jacob Mcleod
  */

#include <iostream>

using namespace std;

int main()
{
    double gpa;
    int satScore;
    cout << "Please enter GPA: ";
    cin >> gpa;


    if (gpa >= 4.0){
        cout << "Admit"
             << endl;
             return 0;
    }
        else cout << "Please enter SAT: ";
             cin >> satScore;
    if ((gpa < 4.0 && gpa >= 3.5) && (satScore > 1400))
    {
        cout << "Admit"
             << endl;
    }
    else if ((gpa < 3.5 && gpa >= 3) && (satScore > 2000)){
        cout << "Admit"
             << endl;
    }
    else if ((gpa < 3.0) && (satScore >= 2300)){
        cout << "Admit"
             << endl;
    }
    else if ((gpa < 4 && gpa >=3.5) && (satScore <= 1400 && satScore >= 1100)){
        cout << "Waitlist"
             << endl;
    }
    else if ((gpa < 3.5 && gpa >= 3.0) && (satScore <= 2000 && satScore >= 1500)){
        cout << "Waitlist"
             << endl;
    }
    else if ((gpa < 4 && gpa >= 3.5) && (satScore < 1100)){
        cout << "Deny"
             << endl;
    }
    else if ((gpa < 3.5 && gpa >= 3.0) && (satScore < 1500)){
        cout << "Deny"
             << endl;
    }
    else if ((gpa < 3.0) && (satScore < 2300)){
        cout << "Deny"
             << endl;
    }
}

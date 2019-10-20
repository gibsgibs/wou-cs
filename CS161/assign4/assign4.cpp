/**
  * @brief Assignment 4
  * @authors Gabriel Brehm and Osama
  */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{   //truncate all values to 2 decimal places
    //print out requests for all the data, and take in the user imput for them
    cout << fixed << setprecision(2);
    double balance, payment, apr;
    cout << "Enter balance: ";
    cin >> balance;
    cout << "Enter payment: ";
    cin >> payment;
    cout << "Enter APR: " << endl;
    cin >> apr;
    //convert APR to a decimal
    apr = apr/100;
    int month = 0;
    //print out the header row
    cout << "Month \t Int \t Pay \t\t Balance \n";
    if(month == 0){
        //print out the first line
        cout << month << "\t\t\t\t" << balance << endl;
        month++;
}
    for(month = 1; balance > 0; month++)
    {
        //calculate interest
        double intrest = balance *(apr/12);
        //calculate balance
        balance = (balance *(1 + apr/12) - payment);
        //print out the row
        cout << month << "\t" << intrest << "\t" << payment << "\t\t" << balance << endl;
        //check if the balance is less than the payment
        if(balance < payment){
            //calculate the interest
            intrest = balance *(apr/12);
            //calculate the balance
            balance = (balance *(1 + apr/12) - payment);
            //calculate the payment
            payment = balance + payment;
            //set the balance to 0
            balance = 0;
            //increment the month by 1
            month++;
            //cout the row
            cout << month << "\t" << intrest << "\t" << payment << "\t\t" << balance << endl;
        }
}
    return 0;
}

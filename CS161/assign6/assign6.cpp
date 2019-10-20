/**
  * @brief Assignment 6
  * @authors Gabriel Brehm and Matt O
  */

#include <iostream>
using namespace std;


/**
 * @brief getInput takes in a string as a parameter - prints that to the console,
 * then gets a string of input from the console and returns the input.
 * @param const string& prompt
 * @return cardNumber
 */
string getInput(const string& prompt)
{
    string cardNumber;
    cout << prompt;
    cin >> cardNumber;
    return cardNumber;
}
/**
 * @brief charTolnt turns a char like '3' into the number it represents (3).
 * Behavior is undefined for chars that do not representing digits.
 * @param char digit
 * @return digit
 */
int charTolnt(char digit)
{
    digit = (digit - '0');
    return digit;
}
/**
 * @brief doubleDigitValue processes a number to be doubled according to
 * the rule for a doubled digit in the Luhn algorithm. Double the number
 * and either return this value if the number is still single digits,
 * or return the sum of the digits if it is a double digit number.
 * Calling doubledDigitValue(4) should give 8. Calling doubledDigitValue(8) should give 7.
 * @param int number
 * @return number
 */
int doubleDigitValue(int number)
{
    number = number * 2;
    int digit1 = 0;
    int digit2 = 0;
    if(number > 9)
    {
        digit1 = number % 10;
        digit2 = (number - digit1) / 10;
        number = digit2 + digit1;
    }
    return number;
}
/**
 * @brief sumOfDigits sums the digits of a credit card number
 * according to the Luhn algorithm. i.e. Calling sumOfDigits("79927398713")
 * should result in 70. (This should make use of charToInt and doubledDigitValue.)
 * @param const string& cardNumber
 * @return sum
 */
int sumOfDigits(const string& cardNumber)
{
    int sum = 0;
    int length = cardNumber.length() - 1;
    for(int i = length; i >= 0; i--)
    {
        int num = charTolnt(cardNumber.at(i));
        int evenNum = i % 2;
        cout << num;
        if(evenNum == 1)
            num = doubleDigitValue(num);

        sum += num;
    }
    return sum;
}
/**
 * @brief isValid returns true/false indicating if a credit card
 * number is potentially a valid number according to Luhn algorithm.
 * (This should use a call to sumOfDigits!)
 * @param cardNumber
 * @return true or false
 */
bool isValid(const string& cardNumber)
{
    if(sumOfDigits(cardNumber) % 10 == 0)
        return true;
    else
        return false;
}
/**
 * @brief getCardType returns a string representing the type
 * of credit card a number is: Visa, MasterCard, American Express, or Unknown.
 * @param cardNumber
 * @return type
 */
string getCardType(const string& cardNumber)
{
    string type;
    if(cardNumber.at(0) == '4')
        type = "Visa";
    else if(cardNumber.at(0) == '5')
        type = "MasterCard";
    else if((cardNumber.substr(0, 2) == "34") || (cardNumber.substr(0, 2) == "37"))
        type = "American Express";
    else
        type = "Unknown issuer";
    return type;
}

int main()
{
    string cardNumber = getInput("Enter card number: ");
    string valid;
    if(isValid(cardNumber))
        valid = "Valid number";
    else
        valid = "Not a valid number";

    cout << valid
         << ", "
         << getCardType(cardNumber)
         << endl;
    return 0;
}

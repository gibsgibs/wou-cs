#include "number.h"
#include <iostream>

using std::to_string;

Number::Number(string num)
{
    // Convert the given string to its decimal equivilent.
    num_ = stoi(num, 0, 2);
}

string Number::ConvertToBinaryString()
{
    int temp = num_;
    int num_in_binary[32];
    int i = 0;
    while(temp > 0)
    {
        num_in_binary[i] = temp % 2;
        temp = temp / 2;
        i++;
    }
    string result;
    for(int j = i - 1; j >= 0; j--)
    {
        result += std::to_string(num_in_binary[j]);
    }
    return result;
}

void Number::Square()
{
    num_ = num_ * num_;
}

void Number::Cube()
{
    num_ = num_ * num_ * num_;
}
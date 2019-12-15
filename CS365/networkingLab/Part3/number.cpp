#include "number.h"
#include <iostream>
#include <bitset>

// Bitset from: https://stackoverflow.com/questions/41949009/decimal-to-binary-signed-in-c.

using std::to_string;
using std::bitset;

Number::Number(string num_1)
{
    num_1_ = stoi(num_1, 0, 2);
    num_2_ = 0;
}

Number::Number(string num_1, string num_2)
{
    // Convert the given strings to their decimal equivilent.
    num_1_ = stoi(num_1, 0, 2);
    num_2_ = stoi(num_2, 0, 2);

}

void Number::Sum()
{
    result_num_ = num_1_ + num_2_;
}

void Number::Product()
{
    result_num_ = num_1_ * num_2_;
}

string Number::Negate()
{
    result_num_ = num_1_ * (-1);
    return bitset<sizeof(result_num_)*8>(result_num_).to_string();
}

string Number::ConvertToBinaryString()
{
    int temp = result_num_;
    int result_num_in_binary[32];
    int i = 0;
    while(temp > 0)
    {
        result_num_in_binary[i] = temp % 2;
        temp = temp / 2;
        i++;
    }
    string result;
    for(int j = i - 1; j >= 0; j--)
    {
        result += std::to_string(result_num_in_binary[j]);
    }
    return result;
}
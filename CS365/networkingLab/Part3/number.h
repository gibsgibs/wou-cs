#ifndef NUMBER_H
#define NUMBER_H

#include <string>

using std::string;

class Number
{
    public:
        Number(string num_1);
        Number(string num_1, string num_2);
        void Sum();
        void Product();
        string Negate();
        string ConvertToBinaryString();
    private:
        int result_num_ = 0;
        int num_1_;
        int num_2_;
};

#endif
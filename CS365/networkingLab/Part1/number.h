#ifndef NUMBER_H
#define NUMBER_H

#include <string>

using std::string;

class Number
{
    public:
        Number(string num);
        string ConvertToBinaryString();
        void Square();
    private:
        int num_;
};

#endif
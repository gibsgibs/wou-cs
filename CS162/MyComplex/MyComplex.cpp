#include "MyComplex.h"
#include <cmath>
#include <iostream>

MyComplex::MyComplex()
{
    rValue = 0;
    iValue = 0;
}

MyComplex::MyComplex(double theRValue)
{
    rValue = theRValue;
    iValue = 0;
}

MyComplex::MyComplex(double theRValue, double theIValue)
{
    rValue = theRValue;
    iValue = theIValue;
}

double MyComplex::getRealPart()
{
    return rValue;
}

double MyComplex::getComplexPart()
{
    return iValue;
}

MyComplex MyComplex::operator+(const MyComplex &secondComplex) const

{
    double temp1 = rValue + secondComplex.rValue;
    double temp2 = iValue + secondComplex.iValue;
    return MyComplex(temp1, temp2);
}

MyComplex MyComplex::operator-(const MyComplex &secondComplex) const
{
    double temp1 = rValue - secondComplex.rValue;
    double temp2 = iValue - secondComplex.iValue;
    return MyComplex(temp1, temp2);
}
MyComplex MyComplex::operator*(const MyComplex &secondComplex) const
{
    double first = rValue * secondComplex.rValue;
    double outer = rValue * secondComplex.iValue;
    double inner = iValue * secondComplex.rValue;
    double last = iValue * secondComplex.iValue;
    double newRValue = first - last;
    double newIValue = outer + inner;

    return MyComplex(newRValue, newIValue);
}

MyComplex MyComplex::operator/(const MyComplex &secondComplex) const
{
    double first = rValue * secondComplex.rValue;
    double last = iValue * secondComplex.iValue;
    double top1 = first + last;
    double bot = abs((secondComplex.rValue * secondComplex.rValue) +
                 (secondComplex.iValue * secondComplex.iValue));
    double top2 = (iValue * secondComplex.rValue) -
                  (rValue * secondComplex.iValue);
    double newRValue = top1/bot;
    double newIValue = top2/bot;
    return MyComplex(newRValue, newIValue);
}

MyComplex MyComplex::operator+=(const MyComplex &secondComplex)
{
    double temp1 = this->rValue + secondComplex.rValue;
    double temp2 = this->iValue + secondComplex.iValue;
    rValue = temp1;
    iValue = temp2;
    return *this;
}

MyComplex MyComplex::operator-=(const MyComplex &secondComplex)
{
    double temp1 = rValue - secondComplex.rValue;
    double temp2 = iValue - secondComplex.iValue;
    rValue = temp1;
    iValue = temp2;
    return *this;
}

MyComplex MyComplex::operator*=(const MyComplex &secondComplex)
{
    double first = rValue * secondComplex.rValue;
    double outer = rValue * secondComplex.iValue;
    double inner = iValue * secondComplex.rValue;
    double last = iValue * secondComplex.iValue;
    double newRValue = first - last;
    double newIValue = outer + inner;
    rValue = newRValue;
    iValue = newIValue;
    return *this;
}

MyComplex MyComplex::operator/=(const MyComplex &secondComplex)
{
    double first = rValue * secondComplex.rValue;
    double last = iValue * secondComplex.iValue;
    double top1 = first + last;
    double bot = abs((secondComplex.rValue * secondComplex.rValue) +
                 (secondComplex.iValue * secondComplex.iValue));
    double top2 = (iValue * secondComplex.rValue) -
                  (rValue * secondComplex.iValue);
    double newRValue = top1/bot;
    double newIValue = top2/bot;
    rValue = newRValue;
    iValue = newIValue;
    return *this;
}

MyComplex& MyComplex::operator++()
{
    rValue++;
    return *this;
}

MyComplex& MyComplex::operator--()
{
    rValue--;
    return *this;
}

MyComplex& MyComplex::operator++(int dummy)
{
    MyComplex temp(rValue, iValue);
    rValue++;
    return temp;
}

MyComplex& MyComplex::operator--(int dummy)
{
    MyComplex temp(rValue, iValue);
    rValue--;
    return temp;
}

MyComplex MyComplex::operator+()
{
    return *this;
}

MyComplex MyComplex::operator-()
{
    return MyComplex(-rValue, -iValue);
}

bool MyComplex::operator==(const MyComplex &secondComplex)
{
    double val1 = rValue * secondComplex.iValue;
    double val2 = iValue * secondComplex.rValue;
    return(static_cast<int>(val1) == static_cast<int>(val2));
}

bool MyComplex::operator!=(const MyComplex &secondComplex)
{
    double val1 = rValue * secondComplex.iValue;
    double val2 = iValue * secondComplex.rValue;
    return(static_cast<int>(val1) != static_cast<int>(val2));
}

ostream& operator<<(ostream& stream, const MyComplex& output)
{
    if(static_cast<int>(output.iValue) == 0)
    {
        stream << output.rValue;
    }
    else if(output.iValue < 0)
    {
        stream << output.rValue
               << " - "
               << -output.iValue
               << 'i';
    }
    else
    {
        stream << output.rValue
               << " + "
               << output.iValue
               << 'i';
    }
   return stream;
}

istream& operator>>(istream& stream, MyComplex& input)
{
    char c, sign;

    stream >> input.rValue
           >> sign
           >> input.iValue
           >> c;
    if(sign == '-')
    {
        input.iValue = -input.iValue;
    }
    return stream;
}


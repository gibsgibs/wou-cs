/**
  * @brief MyComplex Project
  * @authors Gabriel Brehm, Jacob M., Megan T., Jacob M.
  */
#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H
#include <iostream>

using namespace std;

class MyComplex
{
private:
    double rValue;
    double iValue;
public:
    /**
     * @brief MyComplex - the no arg constuctor
     */
    MyComplex();
    /**
     * @brief MyComplex - the single arg constuctor with rValue
     * @param rValue - the real value part of the complex number
     */
    MyComplex(double rValue);
    /**
     * @brief MyComplex - the 2 arg constuctor wiht rValue and iValue
     * @param realValue - the real value part of the complex number
     * @param imgValue - the imaginary part of the complex number
     */
    MyComplex(double realValue, double imgValue);
    /**
     * @brief getRealPart - gets the real part of the complex number
     * @return - rValue
     */
    double getRealPart();
    /**
     * @brief getComplexPart - gets the imaginary part of the complex number
     * @return - iValue
     */
    double getComplexPart();
    /**
     * @brief operator + - overloads the "+" operator to work with complex numbers
     * @param secondComplex - the complex number that is being added to the object
     *                        that is calling it
     * @return - the sum
     */
    MyComplex operator+(const MyComplex& secondComplex) const;
    /**
     * @brief operator - - overloads the "-" operator to work with complex numbers
     * @param secondComplex - the complex number that is being subtracted from the
     *                        object that is calling it
     * @return - the difference
     */
    MyComplex operator-(const MyComplex& secondComplex) const;
    /**
     * @brief operator * - overloads the "*" operator to work with complex numbers
     * @param secondComplex - the complex number that is being multipled by the
     *                        object that is calling it
     * @return - the product
     */
    MyComplex operator*(const MyComplex& secondComplex) const;
    /**
     * @brief operator / - overloads the "/" operator to work with complex numbers
     * @param secondComplex - the complex number that the calling object is being
     *                        divided by
     * @return - the qutient
     */
    MyComplex operator/(const MyComplex& secondComplex) const;
    /**
     * @brief operator += - overloads the "+=" operator to work with complex numbers
     * @param secondComplex - the complex number that is being added to the object
     *                        that is calling it
     * @return - this
     */
    MyComplex operator+=(const MyComplex& secondComplex);
    /**
     * @brief operator -= - overloads the "-=" operator to work with complex numbers
     * @param secondComplex - the complex number that is being substracted from the
     *                        object that is calling it
     * @return - this
     */
    MyComplex operator-=(const MyComplex& secondComplex);
    /**
     * @brief operator *= - overloads the "*=" operator to work with complex numbers
     * @param secondComplex - the complex number that is being multiplied by the object
     *                        that is calling it
     * @return - this
     */
    MyComplex operator*=(const MyComplex& secondComplex);
    /**
     * @brief operator /= - overloads the "/=" operator to work with complex numbers
     * @param secondComplex - the complex number that is being divided by the object
     *                        that is calling it
     * @return - this
     */
    MyComplex operator/=(const MyComplex& secondComplex);
    /**
     * @brief operator ++ - overloads the "++" (pre-increment) operator to work with
     *                      complex numbers
     * @return - this
     */
    MyComplex& operator++();
    /**
     * @brief operator -- - overloads the "--" (pre-decrement) operator to work with
     *                      complex numbers
     * @return - this
     */
    MyComplex& operator--();
    /**
     * @brief operator ++ - overloads the "++" (post-increment) operator tow work
     *                      with complex numbers
     * @param dummy
     * @return - a temp complex number
     */
    MyComplex& operator++(int dummy);
    /**
     * @brief operator -- - overloads the "--" (post-decrement) operator to work
     *                      work with complex numbers
     * @param dummy
     * @return - a temp complex number
     */
    MyComplex& operator--(int dummy);
    /**
     * @brief operator + - overloads the "+" function posative function to work
     *                     with complex numbers
     * @return - this
     */
    MyComplex operator+();
    /**
     * @brief operator - - overloads the "-" function, negative function, to
     *                     work with complex numbers
     * @return MyComplex(-rValue, -iValue)
     */
    MyComplex operator-();
    /**
     * @brief operator == - overloads the "==" operator to work with complex
     *                      numbers
     * @param secondComplex - the complex number that is being compared to
     * @return - true or false
     */
    bool operator==(const MyComplex& secondComplex);
    /**
     * @brief operator != - overloads the "!=" operator to work with complex
     *                      numbers
     * @param secondComplex - the complex number that is being compared to
     * @return - true or false
     */
    bool operator!=(const MyComplex& secondComplex);
    /**
     * @brief operator << - overloads the "<<" operator to work with complex
     *                      numbers
     * @param stream - the output stream
     * @param output - a complex number
     * @return - the stream
     */
    friend ostream& operator<<(ostream& stream, const MyComplex& output);
    /**
     * @brief operator >> - overloads the ">>" operator to work with complex
     *                      numbers
     * @param stream - the input stream
     * @param input - a complex number
     * @return - the strea,
     */
    friend istream& operator>>(istream& stream, MyComplex& input);
};

#endif // MYCOMPLEX_H

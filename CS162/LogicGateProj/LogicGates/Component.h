/**
  * @brief LogicGates Project
  * @authors Gabriel Brehm, Jacob M., Megan T.
  */
#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>
using namespace std;

class Component
{
private:
    string label;
public:
    /**
     * @brief Component - sets label to componentLabel
     * @param componentLabel - the variable that label is set to
     */
    Component(string componentLabel);
    /**
     * @brief getOutput - a virtual function that gets the output
     * @return - returns the output
     */
    virtual bool getOutput() = 0;
    /**
     * @brief prettyPrint - outputs the padding string, the label,
     *                      a colon, and then the result
     * @param padding - the string that is outputed
     */
    virtual void prettyPrint(string padding);
};

#endif // COMPONENT_H

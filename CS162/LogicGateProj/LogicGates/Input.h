/**
  * @brief LogicGates Project
  * @authors Gabriel Brehm, Jacob M., Megan T.
  */
#ifndef INPUT_H
#define INPUT_H
#include "Component.h"

class Input : public Component
{
private:
    bool value;
public:
    Input(string inputName);
    /**
     * @brief setValue - sets value to the variabel newValue
     * @param newValue - the newValue that value is being set to
     */
    void setValue(bool newValue);
    /**
     * @brief getOutput - just returns the value
     * @return the value
     */
    bool getOutput();
};

#endif // INPUT_H

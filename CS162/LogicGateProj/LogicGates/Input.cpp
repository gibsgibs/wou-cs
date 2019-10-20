#include "Input.h"

Input::Input(string inputName)
    : Component(inputName)
{
    //I guess nothing goes here...
}

void Input::setValue(bool newValue)
{
    value = newValue;
}

bool Input::getOutput()
{
    return value;
}

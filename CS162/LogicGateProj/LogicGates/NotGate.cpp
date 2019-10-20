#include "NotGate.h"
#include <cassert>

NotGate::NotGate()
    : ChainableComponent("NOT")
{
    //nothing goes here, and it bothers me.
    //I should figure out why
}

bool NotGate::getOutput()
{
    assert(input != nullptr);
    bool temp;
    if(input->getOutput() == 0)
        temp = true;
    else
        temp = false;
    return temp;
}

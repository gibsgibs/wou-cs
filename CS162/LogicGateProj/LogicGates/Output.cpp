#include "Output.h"

Output::Output(string outputName)
    : ChainableComponent(outputName)
{
    //gahh
}

bool Output::getOutput()
{
    return input->getOutput();
}

#include "TwoInputGate.h"
#include <cassert>
using namespace std;
TwoInputGate::TwoInputGate(LogicOperation gateOperator)
    : ChainableComponent(LOGIC_LABELS[gateOperator])
{
    gateType = gateOperator;
}

void TwoInputGate::setInput2(Component* inputLink)
{
    input2 = inputLink;
}

void TwoInputGate::prettyPrint(string padding)
{
    ChainableComponent::prettyPrint(padding);
    input->prettyPrint(padding + "---");
}

bool TwoInputGate::getOutput()
{
    assert(input != nullptr && input2 != nullptr);

    bool temp = false;

    if(gateType == OR)
    {
        if(input->getOutput() == 1 || input2->getOutput() == 1)
            temp = true;
    }
    else if(gateType == AND)
    {
        if(input->getOutput() == 1 && input2->getOutput() == 1)
            temp = true;
    }
    else if(gateType == XOR)
    {
        if(input->getOutput() != input2->getOutput())
            temp = true;
    }
    return temp;
}

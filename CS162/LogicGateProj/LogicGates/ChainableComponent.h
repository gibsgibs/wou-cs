/**
  * @brief LogicGates Project
  * @authors Gabriel Brehm, Jacob M., Megan T.
  */
#ifndef CHAINABLECOMPONENT_H
#define CHAINABLECOMPONENT_H
#include "Component.h"

class ChainableComponent : public Component
{
protected:
    Component* input;
public:
    ChainableComponent(string componentLabel);
    /**
     * @brief setInput - sets the input to inputLink
     * @param inputLink - is what input is set to
     */
    void setInput(Component* inputLink);
    /**
     * @brief prettyPrint - uses the Component version of prettyPrint,
     *                      and then adds "---"
     * @param padding - is the "---" that is added to the prettyPrint
     */
    void prettyPrint(string padding);
};

#endif // CHAINABLECOMPONENT_H

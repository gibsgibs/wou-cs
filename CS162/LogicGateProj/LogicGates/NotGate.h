/**
  * @brief LogicGates Project
  * @authors Gabriel Brehm, Jacob M., Megan T.
  */
#ifndef NOTGATE_H
#define NOTGATE_H
#include "ChainableComponent.h"

class NotGate : public ChainableComponent
{
public:
    NotGate();
    /**
     * @brief getOutput - calculate output by negating the input
     * @return the output
     */
    bool getOutput();

};

#endif // NOTGATE_H

/**
  * @brief LogicGates Project
  * @authors Gabriel Brehm, Jacob M., Megan T.
  */
#ifndef OUTPUT_H
#define OUTPUT_H
#include "ChainableComponent.h"

class Output : public ChainableComponent
{
public:
    Output(string outputName);
    /**
     * @brief getOutput - returns the output given by its input
     * @return the output
     */
    bool getOutput();
};

#endif // OUTPUT_H

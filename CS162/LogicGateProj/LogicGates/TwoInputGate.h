#ifndef TWOINPUTGATE_H
#define TWOINPUTGATE_H
/**
  * @brief LogicGates Project
  * @authors Gabriel Brehm, Jacob M., Megan T.
  */
#include <string>
#include "ChainableComponent.h"

//Supported operations
enum LogicOperation {OR, AND, XOR};

//Lookup table for names of operations:
//  LOGIC_LABELS[OR] --> "OR"
//  LOGIC_LABELS[AND] --> "AND"...
const std::string LOGIC_LABELS[] = {"OR", "AND", "XOR"};

class TwoInputGate : public ChainableComponent
{
private:
    LogicOperation gateType;
    Component* input2;
public:
    /**
     * @brief TwoInputGate - constuctor that sets the gateType to the
     *                       gateOperator
     * @param gateOperator - the parameter that sets the gateType
     */
    TwoInputGate(LogicOperation gateOperator);
    /**
     * @brief setInput2 - sets the second input
     * @param inputLink - the pointer to inputLink
     */
    void setInput2(Component* inputLink);
    /**
     * @brief prettyPrint - does the ChainableComponent pretty print,
     *                      then use padding
     * @param padding - the "---"
     */
    void prettyPrint(string padding);
    /**
     * @brief getOutput - gets the output based on the logical
     *                    opperation used
     * @return - the output
     */
    bool getOutput();
};

#endif // TWOINPUTGATE_H

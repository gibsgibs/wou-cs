#include "ChainableComponent.h"

ChainableComponent::ChainableComponent(string componentLabel)
    : Component(componentLabel)
{

}
void ChainableComponent::setInput(Component* inputLink)
{
    input = inputLink;
}

void ChainableComponent::prettyPrint(string padding)
{
    Component::prettyPrint(padding);
    if(input != nullptr)
    {
        input->prettyPrint(padding + "---");
    }
}

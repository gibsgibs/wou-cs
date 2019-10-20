#include "Component.h"

Component::Component(string componentLabel)
{
    label = componentLabel;
}

void Component::prettyPrint(string padding)
{
    cout << padding
         << label
         << ": "
         << getOutput()
         << endl;
}


#include "Die.h"
#include <cstdlib>

Die::Die()
{
    numSides = 6;
    value = (rand() % numSides) + 1;
}

Die::Die(int theNumSides)
{
    numSides = theNumSides;
    value = (rand() % numSides) + 1;
}

void Die::roll()
{
    value = (rand() % numSides) + 1;
}

int Die::getValue()
{
    return value;
}

void Die::setValue(int forcedValue)
{
    value = forcedValue;
}

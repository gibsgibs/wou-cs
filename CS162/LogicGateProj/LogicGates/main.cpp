#include <iostream>

#include "Input.h"
#include "Output.h"
#include "NotGate.h"
#include "TwoInputGate.h"

using namespace std;

int main()
{
    ////Sample usage:

    Input a("A");
    a.setValue(false);

    NotGate n1;
    n1.setInput(&a);

    Input b("B");
    b.setValue(false);

    TwoInputGate g1(OR);
    g1.setInput(&n1);
    g1.setInput2(&b);

    Output x("X");
    x.setInput(&g1);

    x.prettyPrint("");


    return 0;
}


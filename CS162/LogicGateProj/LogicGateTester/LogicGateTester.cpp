//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Input.h"
#include "Output.h"
#include "NotGate.h"
#include "TwoInputGate.h"

#include <iostream>

using namespace std;


TEST_CASE( "Components/InputOnly", "Input only" ) {
    cout << "Input Only Test..." << endl;

    Input a("A");
    a.setValue(false);

    REQUIRE(a.getOutput() == false);

    a.setValue(true);
    REQUIRE(a.getOutput() == true);

    a.prettyPrint("");
}


TEST_CASE( "Components/InputOutput", "Input to Output" ) {
    cout << "Input to Output Test..." << endl;

    Input a("A");
    a.setValue(false);

    Output x("X");
    x.setInput(&a);

    REQUIRE(x.getOutput() == false);

    a.setValue(true);
    REQUIRE(x.getOutput() == true);

    x.prettyPrint("");
}


TEST_CASE( "Components/NotGate", "Input to Output through Not gate" ) {
    cout << "Not Gate Test..." << endl;

    Input a("A");
    a.setValue(false);

    NotGate n1;
    n1.setInput(&a);

    Output x("X");
    x.setInput(&n1);

    REQUIRE(x.getOutput() == true);

    a.setValue(true);
    REQUIRE(x.getOutput() == false);

    x.prettyPrint("");
}


TEST_CASE( "Components/AndLogic", "Test And gate" ) {
    cout << "And Gate Test..." << endl;

    Input a("A");

    Input b("B");

    TwoInputGate g1(AND);
    g1.setInput(&a);
    g1.setInput2(&b);

    a.setValue(false); b.setValue(false);
    REQUIRE(g1.getOutput() == false);

    a.setValue(false); b.setValue(true);
    REQUIRE(g1.getOutput() == false);

    a.setValue(true); b.setValue(false);
    REQUIRE(g1.getOutput() == false);

    a.setValue(true); b.setValue(true);
    REQUIRE(g1.getOutput() == true);

    g1.prettyPrint("");
}


TEST_CASE( "Components/ORLogic", "Test Or gate" ) {
    cout << "Or Gate Test..." << endl;

    Input a("A");

    Input b("B");

    TwoInputGate g1(OR);
    g1.setInput(&a);
    g1.setInput2(&b);

    a.setValue(false); b.setValue(false);
    REQUIRE(g1.getOutput() == false);

    a.setValue(false); b.setValue(true);
    REQUIRE(g1.getOutput() == true);

    a.setValue(true); b.setValue(false);
    REQUIRE(g1.getOutput() == true);

    a.setValue(true); b.setValue(true);
    REQUIRE(g1.getOutput() == true);

    g1.prettyPrint("");
}


TEST_CASE( "Components/XORLogic", "Test XOr gate" ) {
    cout << "XOr Gate Test..." << endl;

    Input a("A");

    Input b("B");

    TwoInputGate g1(XOR);
    g1.setInput(&a);
    g1.setInput2(&b);

    a.setValue(false); b.setValue(false);
    REQUIRE(g1.getOutput() == false);

    a.setValue(false); b.setValue(true);
    REQUIRE(g1.getOutput() == true);

    a.setValue(true); b.setValue(false);
    REQUIRE(g1.getOutput() == true);

    a.setValue(true); b.setValue(true);
    REQUIRE(g1.getOutput() == false);

    g1.prettyPrint("");
}


TEST_CASE( "Components/NANDLogic", "Test Not of And gate" ) {
    cout << "XOr Gate Test..." << endl;

    Input a("A");

    Input b("B");

    TwoInputGate g1(AND);
    g1.setInput(&a);
    g1.setInput2(&b);

    NotGate n1;
    n1.setInput(&g1);

    a.setValue(false); b.setValue(false);
    REQUIRE(n1.getOutput() == true);

    a.setValue(false); b.setValue(true);
    REQUIRE(n1.getOutput() == true);

    a.setValue(true); b.setValue(false);
    REQUIRE(n1.getOutput() == true);

    a.setValue(true); b.setValue(true);
    REQUIRE(n1.getOutput() == false);

    n1.prettyPrint("");
}


TEST_CASE( "Components/HalfAdder", "Test doing addition" ) {
    cout << "Addition Test..." << endl;

    Input a("A");

    Input b("B");

    TwoInputGate g1(XOR);
    g1.setInput(&a);
    g1.setInput2(&b);

    TwoInputGate g2(AND);
    g2.setInput(&a);
    g2.setInput2(&b);

    Output sum("Sum");
    sum.setInput(&g1);

    Output carry("Carry");
    carry.setInput(&g2);

    a.setValue(false); b.setValue(false);
    REQUIRE(carry.getOutput() == false);
    REQUIRE(sum.getOutput() == false);

    a.setValue(false); b.setValue(true);
    REQUIRE(carry.getOutput() == false);
    REQUIRE(sum.getOutput() == true);

    a.setValue(true); b.setValue(false);
    REQUIRE(carry.getOutput() == false);
    REQUIRE(sum.getOutput() == true);

    a.setValue(true); b.setValue(true);
    REQUIRE(carry.getOutput() == true);
    REQUIRE(sum.getOutput() == false);

    carry.prettyPrint("");
    sum.prettyPrint("");
}

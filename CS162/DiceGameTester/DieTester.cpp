
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Die.h"


TEST_CASE( "Die/ForcedValue", "Test forcing value on die" ) {
    Die d1;
    d1.setValue(1);
    REQUIRE( d1.getValue() == 1 );
    d1.setValue(5);
    REQUIRE( d1.getValue() == 5 );
}

TEST_CASE( "Die/Randomness", "Default die" ) {
    Die d1; //6 sides

    //test initial value
    REQUIRE( d1.getValue() >= 1 );
    REQUIRE( d1.getValue() <= 6 );

    //verify that die stays in bounds
    for(int i = 0; i < 1000; i++) {
        d1.roll();
        int roll = d1.getValue();
        REQUIRE( roll >= 1 );
        REQUIRE( roll <= 6 );
    }

    //verify that it hits all values
    bool seenValue[6] = {false};
    for(int i = 0; i < 1000; i++) {
        d1.roll();
        int roll = d1.getValue();
        seenValue[roll - 1] = true;
    }
    for(int value = 0; value < 6; value++) {
        REQUIRE( seenValue[value] == true );
    }
    //out of 1000 rolls, should see each number at least once...
}


TEST_CASE( "Die/Randomness2", "Non-default die" ) {
    Die d1(12); //12 sides

    //test initial value
    REQUIRE( d1.getValue() >= 1 );
    REQUIRE( d1.getValue() <= 12 );

    //verify that die stays in bounds
    for(int i = 0; i < 1000; i++) {
        d1.roll();
        int roll = d1.getValue();
        REQUIRE( roll >= 1 );
        REQUIRE( roll <= 12 );
    }

    //verify that it hits all values
    bool seenValue[12] = {false};
    for(int i = 0; i < 1000; i++) {
        d1.roll();
        int roll = d1.getValue();
        seenValue[roll - 1] = true;
    }
    for(int value = 0; value < 12; value++) {
        REQUIRE( seenValue[value] == true );
    }
    //out of 1000 rolls, should see each number at least once...
}

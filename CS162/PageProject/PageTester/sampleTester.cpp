
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files

TEST_CASE( "SAMPLE/TEST1", "Sample Test" ) {
    //CAPTURE is like cout but only shows if we fail the test
    //CAPTURE("My message");

    //An actual test
    REQUIRE( 1 == 1 );
}

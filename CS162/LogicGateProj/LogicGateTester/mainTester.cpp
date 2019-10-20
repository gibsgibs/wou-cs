
//A main funciton for running unit tests on the project
//Uses Catch unit test framework:
//https://github.com/philsquared/Catch/wiki/Reference


//Tell catch this is our main
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"


int main ()
{
    //Create testing session
    Catch::Session session;

    //Uncomment next three lines to show all tests, not just failed ones
//    Catch::ConfigData options;
//    options.showSuccessfulTests = true;
//    session.useConfigData(options);


    //Uncommenting would configure CATCH to run
    // only tests starting with word SAMPLE/
    //session.config().addTestSpec( "SAMPLE/*" );

    //Uncomment to send output to file testData.txt instead of console
    //session.config().setFilename("testData.txt");

    //Run the tests - return the result
    return session.run();
}



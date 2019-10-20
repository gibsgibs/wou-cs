
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

    return session.run();
}



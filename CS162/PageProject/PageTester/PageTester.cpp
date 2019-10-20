
#include <ctime>
#include <cstdlib>

//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Page.h"

TEST_CASE( "Page/Constuctor", "Test constructor that takes name" ) {

    Page p("http:foo.com");

    REQUIRE( p.getNumLinks() == 0 );
    REQUIRE( p.getNumVisits() == 0 );
    REQUIRE( p.getURL() == "http:foo.com" );
}

TEST_CASE( "Page/Constuctor2", "Test no arg constructor" ) {

    Page p;

    REQUIRE( p.getNumLinks() == 0 );
    REQUIRE( p.getNumVisits() == 0 );
    REQUIRE( p.getURL() == "" );
}

TEST_CASE( "Page/Visit", "Test no arg constructor" ) {

    Page p;
    REQUIRE( p.getNumVisits() == 0 );

    p.visit();
    REQUIRE( p.getNumVisits() == 1 );

    p.visit();
    REQUIRE( p.getNumVisits() == 2 );
}

TEST_CASE( "Page/AddLinkIncrementsCount", "Test addLink changes numLinks" ) {
    //Note - only tests that you THINK you added the links
    Page p;
    Page p2;
    Page p3;

    REQUIRE( p.getNumLinks() == 0 );

    p.addLink(&p2);
    REQUIRE( p.getNumLinks() == 1 );

    p.addLink(&p3);
    REQUIRE( p.getNumLinks() == 2 );
}


TEST_CASE( "Page/getRanomLink", "Test getRandomLink" ) {
	//Seed the random number generator with a constant for easy debugging
	srand(1);
	//You can use this instead to get different random patterns
	//srand(time(nullptr));

    //Tests by setting up a page with 3 links, then
    // randomly asking for a link 30 times.
    //If we ever get back something that does not match a known page
    // or we never see one of the possible answers, that is a failure.
    //It is possible (but unlikely) to fail by really bad luck...
    // if that happens it is OK as long as most runs pass

    Page p;
    Page p2;
    Page p3;
    Page p4;
    p.addLink(&p2);
    p.addLink(&p3);
    p.addLink(&p4);

    bool fistLinkSeen = false;
    bool secondLinkSeen = false;
    bool thirdLinkSeen = false;

    for(int i = 0; i < 30; i++) {
        //Get the address of a random Page p links to
        Page* linkedPagePtr = p.getRandomLink();

        //Addres we got must match the address of one of the three pages we actually link to
        bool validLink = linkedPagePtr == &p2 || linkedPagePtr == &p3 || linkedPagePtr == &p4;
        REQUIRE( validLink == true );

        //Record we have seen the page who's address is the same
        // as the link we got back
        if(linkedPagePtr == &p2)
            fistLinkSeen = true;
        else if(linkedPagePtr == &p3)
            secondLinkSeen = true;
        else if(linkedPagePtr == &p4)
            thirdLinkSeen = true;
    }

    //We should have seen everything, unless we got REALLY unlucky
    bool allSeen = fistLinkSeen && secondLinkSeen && thirdLinkSeen;
    REQUIRE( allSeen == true );
}

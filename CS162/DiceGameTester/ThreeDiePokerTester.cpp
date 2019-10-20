#include <iostream>

using namespace std;

//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "ThreeDicePoker.h"


TEST_CASE( "3DP/RollDie" ) {
    ThreeDicePoker p1;

    //for each die
    for(int die = 0 ; die < 3; die++) {
        int value = p1.getDieValue(die);
        //roll 100 times, it better change at some point
        bool changeObserved = false;
        for(int roll = 0; roll < 100; roll++) {
            p1.rollDie(die);
            int newVal = p1.getDieValue(die);
            if(newVal != value) {
                changeObserved = true;
                break;
            }
        }
        REQUIRE(changeObserved == true);
    }
}

TEST_CASE( "3DP/RollAll" ) {
    ThreeDicePoker p1;

    //for each die
    int value1 = p1.getDieValue(0);
    int value2 = p1.getDieValue(1);
    int value3 = p1.getDieValue(2);

    //roll 100 times, all better change at some point
    bool changeObserved = false;
    for(int roll = 0; roll < 100; roll++) {
        p1.rollAll();
        if(value1 != p1.getDieValue(0)
           && value2 != p1.getDieValue(1)
           && value3 != p1.getDieValue(2))
        {
            changeObserved = true;
            break;
        }
    }
    REQUIRE(changeObserved == true);
}


TEST_CASE( "3DP/HighDie" ) {
    ThreeDicePoker p1;
    p1.setDie(0,1);
    p1.setDie(1,2);
    p1.setDie(2,4);
    REQUIRE(p1.getScore() == 40);
    p1.setDie(2,5);
    REQUIRE(p1.getScore() == 50);
    p1.setDie(2,6);
    REQUIRE(p1.getScore() == 60);
}


TEST_CASE( "3DP/Pair" ) {
    ThreeDicePoker p1;

    //test 1's
    p1.setDie(0,1);
    p1.setDie(1,1);
    p1.setDie(2,4);
    REQUIRE(p1.getScore() == 40);

    //test other pairs:
    for(int i = 2; i <= 6; i++) {
        p1.setDie(1, i);
        p1.setDie(2, i);
        REQUIRE(p1.getScore() == 40 * i);
    }
}


TEST_CASE( "3DP/ThreeOfKind" ) {
    ThreeDicePoker p1;

    //test all triples
    for(int i = 1; i <= 6; i++) {
        p1.setDie(0, i);
        p1.setDie(1, i);
        p1.setDie(2, i);
        REQUIRE(p1.getScore() == 1000);
    }
}

void shuffleArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        int randIndex = rand() % size;
        std::swap(array[i], array[randIndex]);
    }
}

TEST_CASE( "3DP/Straights" ) {
    ThreeDicePoker p1;

    //test all in-order straights
    for(int i = 1; i <= 4; i++) {
        p1.setDie(0, i);
        p1.setDie(1, i+1);
        p1.setDie(2, i+2);
        REQUIRE(p1.getScore() == 400);
    }

    //test variety of mixed up straights
    for(int i = 0; i <= 300; i++) {
        int start = rand() % 4 + 1;
        int values[3] = { start, start + 1, start + 2 };
        shuffleArray(values, 3);
        p1.setDie(0, values[0]);
        p1.setDie(1, values[1]);
        p1.setDie(2, values[2]);
        INFO("Did not detect an out of order straight");
        INFO("Dice were " << values[0] << " " << values[1] << " " << values[2]);
        REQUIRE(p1.getScore() == 400);
    }
}



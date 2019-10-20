
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Set.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE( "Constructor/Add/Contains" ) {
    cout << "Testing Constructor/Add/Contains" << endl;
    Set<char> s;
    s.add('A');
    REQUIRE( s.contains('A') );

    s.add('B');
    REQUIRE( s.contains('A') );
    REQUIRE( s.contains('B') );
}

TEST_CASE( "getSize" ) {
    cout << "Testing getSize" << endl;
    Set<char> s;
    REQUIRE( s.getSize() == 0 );

    s.add('A');
    REQUIRE( s.getSize() == 1 );

    s.add('B');
    s.add('C');
    REQUIRE( s.getSize() == 3 );

    s.add('A');
    REQUIRE( s.getSize() == 3 );
}


TEST_CASE( "Grow" ) {
    cout << "Testing Grow" << endl;
    Set<int> s;

    for(int i = 0; i < 1000; i++)
        s.add(i);

    for(int i = 0; i < 1000; i++)
        REQUIRE( s.contains(i) );

    REQUIRE( s.getSize() == 1000 );
}



TEST_CASE( "Remove" ) {
    cout << "Testing Remove" << endl;

    Set<char> s;
    s.add('A');
    s.add('B');
    s.add('C');
    REQUIRE( s.getSize() == 3 );
    REQUIRE( s.contains('A') );
    REQUIRE( s.contains('B') );
    REQUIRE( s.contains('C') );

    s.remove('A');

    REQUIRE( s.getSize() == 2 );
    REQUIRE( !s.contains('A') );
    REQUIRE( s.contains('B') );
    REQUIRE( s.contains('C') );

    s.add('D');
    s.add('E');
    s.remove('C');

    REQUIRE( s.getSize() == 3 );
    REQUIRE( s.contains('B') );
    REQUIRE( !s.contains('C') );
    REQUIRE( s.contains('D') );
    REQUIRE( s.contains('E') );
}




TEST_CASE( "CopyConstructor" ) {
    cout << "Testing CopyConstructor" << endl;
    Set<int> s;
    s.add(1);
    s.add(2);

    Set<int> s2(s);
    s2.add(3);

    s.remove(1);

    REQUIRE( !s.contains(1) );
    REQUIRE( s.contains(2) );
    REQUIRE( !s.contains(3) );

    REQUIRE( s2.contains(1) );
    REQUIRE( s2.contains(2) );
    REQUIRE( s2.contains(3) );
}

TEST_CASE( "AssignmentOp" ) {
    cout << "Testing AssignmentOperator" << endl;

    SECTION( "AssignmentOperator/DeepCopy") {
        cout << "   ...DeepCopy" << endl;
        Set<int> s;
        s.add(1);
        s.add(2);

        Set<int> s2;
        s2.add(4); //should be cleared out
        s2 = s;
        s2.add(3);

        s.remove(2);

        REQUIRE( s.contains(1) );
        REQUIRE( !s.contains(2) );
        REQUIRE( !s.contains(3) );

        REQUIRE( s2.contains(1) );
        REQUIRE( s2.contains(2) );
        REQUIRE( s2.contains(3) );
        REQUIRE( !s2.contains(4) );
    }

    SECTION( "AssignmentOperator/SelfAssignment") {
        cout << "   ...SelfAssignment" << endl;
        Set<int> s;
        s.add(1);
        s.add(2);

        s = s;

        REQUIRE( s.contains(1) );
        REQUIRE( s.contains(2) );
    }

}


TEST_CASE( "Clear" ) {
    cout << "Testing Clear" << endl;

    Set<char> s;
    s.add('A');
    s.add('B');
    s.clear();
    REQUIRE( s.getSize() == 0 );
    REQUIRE( !s.contains('A') );
    REQUIRE( !s.contains('B') );

}




TEST_CASE( "RemoveSmallest" ) {
    cout << "Testing removeSmallest" << endl;
    Set<int> s;
    s.add(20);
    s.add(5);
    s.add(30);
    s.add(10);
    s.add(25);
    s.add(15);

    int temp = s.removeSmallest();
    REQUIRE( temp == 5 );
    REQUIRE( !s.contains(5) );
    REQUIRE( s.getSize() == 5 );


    temp = s.removeSmallest();
    REQUIRE( temp == 10 );
    REQUIRE( !s.contains(10) );
    REQUIRE( s.getSize() == 4 );

    temp = s.removeSmallest();
    REQUIRE( temp == 15 );
    REQUIRE( !s.contains(15) );
    REQUIRE( s.getSize() == 3 );

    REQUIRE( s.contains(20) );
    REQUIRE( s.contains(25) );
    REQUIRE( s.contains(30) );

}



TEST_CASE( "Operator==" ) {
    cout << "Testing operator==" << endl;
    Set<int> s;
    for(int i = 1; i <= 4; i++)
        s.add(i);
    //s = 1,2,3,4

    Set<int> s2;
    for(int i = 5; i >= 1; i--)
        s2.add(i);
    //s2 = 5,4,3,2,1

    bool areEqualResult = s == s2;
    REQUIRE( areEqualResult == false  );

    s.add(5); //s = 1,2,3,4,5
    areEqualResult = s == s2;
    REQUIRE( areEqualResult == true  );

    s.add(6); //s = 1,2,3,4,5,6
    areEqualResult = s == s2;
    REQUIRE( areEqualResult == false  );
}


//NOTE - you only need this OR toString, not both tests
/*TEST_CASE( "StreamInsertion" ) {
    cout << "Testing StreamInsertion" << endl;

    Set<int> s;

    stringstream buffer;
    buffer << s;
    string str1 = buffer.str();
    REQUIRE( str1 == "{}" );

    s.add(1);
    s.add(2);
    s.add(3);

    stringstream buffer2;
    buffer2 << s;
    string str2 = buffer2.str();
    REQUIRE( str2 == "{1, 2, 3}" );
}*/

//NOTE - you only need this OR StreamInsertion, not both tests
TEST_CASE( "ToString" ) {
    cout << "Testing ToString" << endl;

    Set<int> s;
    string str1 = s.toString();
    REQUIRE( str1 == "{}" );

    s.add(1);
    s.add(2);
    s.add(3);

    string str2 = s.toString();
    REQUIRE( str2 == "{1, 2, 3}" );
}


TEST_CASE( "Intersection" ) {
    cout << "Testing intersectionWith" << endl;
    Set<int> s;
    Set<int> s2;
    Set<int> s3;

    for(int i = 0; i <= 100; i += 2)
        s.add(i);

    for(int i = 0; i <= 100; i += 5)
        s2.add(i);

    for(int i = 10; i <= 16; i++)
        s3.add(i);


    Set<int> s4 = s.intersectionWith(s2);
    Set<int> s5 = s3.intersectionWith(s);

    REQUIRE( s4.getSize() == 11 );
    REQUIRE( s5.getSize() == 4 );
}




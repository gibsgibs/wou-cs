
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "DLList.h"
#include "Queue.h"
#include "DLListIterator.h"


TEST_CASE("DLListTester - test getSize()"){
    DLList<string> list;
    REQUIRE(list.getSize() == 0); //size must be 0 after constructor
    list.clear();
    REQUIRE(list.getSize() == 0); //size must be 0 after clear
    list.add("30");
    REQUIRE(list.getSize() == 1); //size must be 1 after first add
    list.add("40");
    REQUIRE(list.getSize() == 2); //size must be 2 after second add
    list.add("15");
    REQUIRE(list.getSize() == 3); //size must be 3 after third add
    list.add("25");
    REQUIRE(list.getSize() == 4); //size must be 4 after fourth add
    list.add("45");
    REQUIRE(list.getSize() == 5); //size must be 5 after fifth add
    list.removeAt(0);
    REQUIRE(list.getSize() == 4); //size must be 4 after first remove
    list.removeAt(2);
    REQUIRE(list.getSize() == 3); //size must be 3 after second remove
    list.clear();
    REQUIRE(list.getSize() == 0); //size must be 0 after clear

}

TEST_CASE("DLListTester - test isEmpty()"){
    DLList<string> list;
    REQUIRE(list.isEmpty() == 1); //isEmpty returns true after constructor
    list.clear();
    REQUIRE(list.isEmpty() == 1); //isEmpty returns true after clear
    list.add("10");
    list.add("20");
    REQUIRE(list.isEmpty() == 0); //isEmpty returns false after adds
    list.add("30");
    list.add("40");
    list.add("15");
    REQUIRE(list.isEmpty() == 0); //isEmpty returns false after adds
    list.add("25");
    list.add("35");
    list.add("45");
    REQUIRE(list.isEmpty() == 0); //isEmpty returns false after adds
    list.clear();
    REQUIRE(list.isEmpty() == 1); //isEmpty returns true after clear
}

TEST_CASE("DLListTester - test contains()"){
    DLList<string> list;
    list.clear();
    list.add("10");
    list.add("20");
    list.add("30");
    list.add("40");
    list.add("15");
    list.add("25");
    list.add("35");
    list.add("45");

    REQUIRE(list.contains("80") == 0); //contains returns false for element 80
    REQUIRE(list.contains("5") == 0);  //contains returns false for element 5
    REQUIRE(list.contains("30") == 1); //contains returns true for element 30
    REQUIRE(list.contains("45") == 1); //contains returns true for element 45
    REQUIRE(list.contains("10") == 1); //contains returns true for element 10
    list.clear();
    REQUIRE(list.contains("45") == 0); // contains returns false for element 45
}

TEST_CASE("DLListTester - test add()"){
    DLList<string> list;
        list.add("10");
        REQUIRE(list.get(list.getSize() - 1) == "10"); //tail of list must be 10 after add

        list.add("20");
        REQUIRE(list.get(list.getSize() - 1) == "20"); //tail of list must be 20 after add

        list.add("30");
        REQUIRE(list.get(list.getSize() - 1) == "30"); //tail of list must be 30 after add

        list.add("40");
        REQUIRE(list.get(list.getSize() - 1) == "40"); //tail of list must be 40 after add

        list.add("15");
        REQUIRE(list.get(list.getSize() - 1) == "15"); //tail of list must be 15 after add

        list.add("25");
        REQUIRE(list.get(list.getSize() - 1) == "25"); //tail of list must be 25 after add

        list.add("35");
        REQUIRE(list.get(list.getSize() - 1) == "35"); //tail of list must be 35 after add

        list.add("45");
        REQUIRE(list.get(list.getSize() - 1) == "45"); //tail of list must be 45 after add
        list.clear();
}

TEST_CASE("DLListTester - test get(index)"){

    DLList<string> list;
    list.clear();
    list.add("10");
    list.add("20");
    list.add("30");
    list.add("40");
    list.add("15");
    list.add("25");
    list.add("35");
    list.add("45");

    REQUIRE(list.get(0) == "10"); //head of list must be 10 after the adds
    REQUIRE(list.get(7) == "45"); //tail of list must be 45 after the adds
    REQUIRE(list.get(3) == "40"); //4th item of list must be 40 after the adds
    REQUIRE(list.get(5) == "25"); //6th item of list must be 25 after the adds
    list.clear();

}

TEST_CASE("DLListTester - test remove(element T)"){
    DLList<string> list;
    list.clear();
    list.add("10");
    list.add("20");
    list.add("30");
    list.add("40");
    list.add("15");
    list.add("25");
    list.add("35");
    list.add("45");

    REQUIRE(list.remove("99") == 0); //Remove returns false for 99
    REQUIRE(list.getSize() == 8); //size must be 8 after failed remove

    REQUIRE(list.remove("45") == 1); //Remove returns true for 45
    REQUIRE(list.contains("45") == 0); //contain must return false for 45
    REQUIRE(list.getSize() == 7); //size must be 7 after remove

    REQUIRE(list.remove("10") == 1); //Remove returns true for 10
    REQUIRE(list.contains("10") == 0); //contain must return false for 10
    REQUIRE(list.getSize() == 6); //size must be 6 after remove

    REQUIRE(list.remove("40") == 1); //Remove returns true for 40
    REQUIRE(list.contains("40") == 0); //contain must return false for 40
    REQUIRE(list.getSize() == 5); //size must be 5 after remove

    REQUIRE(list.remove("20") == 1); //Remove returns true for 20
    REQUIRE(list.contains("20") == 0); //contain must return false for 20
    REQUIRE(list.getSize() == 4); //size must be 4 after remove

    REQUIRE(list.remove("30") == 1); //Remove returns true for 30
    REQUIRE(list.contains("30") == 0); //contain must return false for 30
    REQUIRE(list.getSize() == 3); //size must be 3 after remove

    REQUIRE(list.remove("15") == 1); //Remove returns true for 15
    REQUIRE(list.contains("15") == 0); //contain must return false for 15
    REQUIRE(list.getSize() == 2); //size must be 2 after remove

    REQUIRE(list.remove("25") == 1); //Remove returns true for 25
    REQUIRE(list.contains("25") == 0); //contain must return false for 25
    REQUIRE(list.getSize() == 1); //size must be 1 after remove

    REQUIRE(list.remove("35") == 1); //Remove returns true for 35
    REQUIRE(list.contains("35") == 0); //contain must return false for 35
    REQUIRE(list.getSize() == 0); //size must be 0 after remove


    REQUIRE(list.remove("45") == 0); //Remove returns false on empty list
    REQUIRE(list.getSize() == 0); //size must be 0 after failed remove
    list.clear();
}

TEST_CASE("DLListTester - test clear())"){
    DLList<string> list;
    list.clear();
    list.add("10");
    list.add("20");
    list.clear();
    REQUIRE(list.getSize() == 0); //size must be 0 after clear
    REQUIRE(list.isEmpty() == 1); //isEmpty must return true after clear
    list.add("30");
    list.add("40");
    list.add("15");
    list.clear();
    REQUIRE(list.getSize() == 0); //size must be 0 after clear
    REQUIRE(list.isEmpty() == 1); //isEmpty must return true after clear
    list.add("25");
    list.add("35");
    list.add("45");
    list.clear();
    REQUIRE(list.getSize() == 0); //size must be 0 after clear
    REQUIRE(list.isEmpty() == 1); //isEmpty must return true after clear
    list.clear();

}

TEST_CASE("DLListTester - test add(index)"){

    DLList<string> list;
    list.add(0, "10");
    REQUIRE(list.get(0) == "10"); //tail of list should be 10 after the add
    REQUIRE(list.getSize() == 1); //size must be 1 after the add

    list.add(0, "20");
    REQUIRE(list.get(0) == "20"); //head of list should be 10 after the add
    REQUIRE(list.getSize() == 2); //size must be 2 after the add

    list.add(2, "30");
    REQUIRE(list.get(2) == "30"); //tail of list should be 30 after the add
    REQUIRE(list.getSize() == 3); //size must be 3 after the add

    list.add(1, "40");
    REQUIRE(list.get(1) == "40"); //2nd element of list should be 40 after the add
    REQUIRE(list.getSize() == 4); //size must be 4 after the addlist.
    list.clear();
}

TEST_CASE("DLListTester - test removeAt(index)"){
    DLList<string> list;
    list.clear();
    list.add("10");
    list.add("20");
    list.add("30");
    list.add("40");
    list.add("15");
    list.add("25");
    list.add("35");
    list.add("45");

    REQUIRE(list.contains("10") == 1); //contains returns true before removal of 10
    REQUIRE(list.removeAt(0) == "10"); //remove must return 10 after remove of index 0
    REQUIRE(list.contains("10") == 0); //contains returns false after removal of 10

    REQUIRE(list.contains("40") == 1); //contains returns true before removal of 40
    REQUIRE(list.removeAt(2) == "40"); //remove must return 40 after remove of index 2
    REQUIRE(list.contains("40") == 0); //contains returns false after removal of 40

    REQUIRE(list.contains("45") == 1); //contains returns true before removal of 45
    REQUIRE(list.removeAt(5) == "45"); //remove must return 45 after remove of index 5
    REQUIRE(list.contains("45") == 0); //contains returns false after removal of 45
    list.clear();
}


TEST_CASE("Queue Tests - test enqueue(T value))"){
    Queue<string> list;
    list.enqueue("10");
    list.enqueue("20");
    list.enqueue("30");
    list.enqueue("40");

    REQUIRE(list.front() == "10"); //head of queue must be 10
    REQUIRE(list.getSize() == 4); //size of queue must be 4 after adds
    REQUIRE(list.back() == "40"); //tail of queue must be 40 after adds

}

TEST_CASE("Queue Tests - test dequeue())"){
    Queue<string> list;
    list.enqueue("10");
    list.enqueue("20");
    list.enqueue("30");
    list.enqueue("40");

    REQUIRE(list.front() == "10"); //head of queue must be 10
    REQUIRE(list.dequeue() == "10"); //dequeue must return head of queue
    REQUIRE(list.front() == "20"); //head of queue must now be 20
    REQUIRE(list.dequeue() == "20"); //dequeue must return head of queue
    REQUIRE(list.front() == "30"); //head of queue must now be 20
}

TEST_CASE("Queue Tests - test front())"){
    Queue<string> list;
    list.enqueue("10");
    list.enqueue("20");
    list.enqueue("30");
    list.enqueue("40");

    REQUIRE(list.front() == "10"); //front of queue must be 10 after adds
    list.dequeue();
    REQUIRE(list.front() == "20"); //front of queue must be 20 after dequeue
    list.dequeue();
    REQUIRE(list.front() == "30"); //front of queue must be 30 after dequeue
}


TEST_CASE("Queue Tests - test back())"){
    Queue<string> list;
    list.enqueue("10");
    list.enqueue("20");
    list.enqueue("30");
    list.enqueue("40");

    REQUIRE(list.back() == "40"); //back of queue must be 40 after adds
    list.dequeue();
    REQUIRE(list.back() == "40"); //back of queue must be 40 after dequeue
    list.enqueue("50");
    REQUIRE(list.back() == "50"); //back of queue must be 50 after enqueue
}

TEST_CASE("Queue Tests - test getSize())"){
    Queue<string> list;
    list.enqueue("10");
    list.enqueue("20");
    list.enqueue("30");
    list.enqueue("40");

    REQUIRE(list.getSize() == 4); //size of queue must be 4 after adds
    list.dequeue();
    REQUIRE(list.getSize() == 3); //size of queue must be 3 after dequeue
    list.dequeue();
    REQUIRE(list.getSize() == 2); //size of queue must be 2 after dequeue
}

//test case for iterator, created by Mike D
TEST_CASE("DLListIterator - testing iterator operations")
{
    DLList<int> list;
    list.add(50);
    list.add(60);
    list.add(70);
    list.add(80);
    list.add(90);
    DLListIterator<int> location = list.begin();
    REQUIRE(*location == list.get(0));
    REQUIRE(*location == 50);
    location.operator ++();
    REQUIRE(*location == 60);
    location.operator ++();
    REQUIRE(*location == 70);
    location.operator ++();
    REQUIRE(*location == 80);
    REQUIRE(*location != 70);
    location.operator --();
    REQUIRE(*location == 70);
    list.clear();

}

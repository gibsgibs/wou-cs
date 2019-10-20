//Bring in unit testing code
#include "catch.hpp"
#include "dllist.h"
#include "queue.h"
#include "HashSet.h"

//Include your .h files

TEST_CASE( "TESTSIZE", "Test getSize()" ) {
    //CAPTURE is like cout but only shows if we fail the test
    //CAPTURE("My message");

    //An actual test
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

TEST_CASE("TESTEMPTY", "Test isEmpty()")
{
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

TEST_CASE("TESTCONTAINS", "Test contains()")
{
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
    REQUIRE(list.contains("5") == 0); //contains returns false for element 5
    REQUIRE(list.contains("30") == 1); //contains returns true for element 30
    REQUIRE(list.contains("45") == 1); //contains returns true for element 45
    REQUIRE(list.contains("10") == 1); //contains returns true for element 10
    list.clear();
    REQUIRE(list.contains("45") == 0); //contains returns false for element 45
}

TEST_CASE("TESTADDT", "Test addT()")
{
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
}

TEST_CASE("TESTGET", "Test get(int)")
{
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
}

TEST_CASE("TESTREMOVEELEM", "Test remove(element)")
{
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

}

TEST_CASE("TESTCLEAR", "Test clear()")
{
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
}

TEST_CASE("TESTADDINT", "Test add(int, T)")
{
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
    REQUIRE(list.getSize() == 4); //size must be 4 after the add
}

TEST_CASE("TESTREMOVEINT", "Test removeAt()")
{
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
}

TEST_CASE("TESTENQ", "Test enqeueu()")
{
    Queue<string> list;
    list.enqueue("10");
    list.enqueue("20");
    list.enqueue("30");
    list.enqueue("40");

    REQUIRE(list.front() == "10"); //head of queue must be 10
    REQUIRE(list.getSize() == 4); //size of queue must be 4 after adds
    REQUIRE(list.back() == "40"); //tail of queue must be 40 after adds
}

TEST_CASE("TESTDEQ", "Test dequeue()")
{
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

TEST_CASE("TESTFRONT", "Test front()")
{
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

TEST_CASE("TESTBACK", "Test back()")
{
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

TEST_CASE("TESTQSIZE", "Test getSize()")
{
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

TEST_CASE("TEST HASHSET INSERT", "test HashSet insert")
{
    HashSet<string> set;
    REQUIRE(set.getSize() == 0); //size must be 0 after constructor
    set.insert("100");
    set.insert("300");
    set.insert("500");
    set.insert("700");
    set.insert("900");
    set.insert("101");
    set.insert("301");
    set.insert("501");
    set.insert("701");
    set.insert("901");
    REQUIRE(set.getSize() == 10); //size must be 10 after adds

    REQUIRE(set.find("100") == 1); //find must return true for 100
    REQUIRE(set.find("300") == 1); //find must return true for 300
    REQUIRE(set.find("500") == 1); //find must return true for 500
    REQUIRE(set.find("700") == 1); //find must return true for 700
    REQUIRE(set.find("900") == 1); //find must return true for 900
    REQUIRE(set.find("101") == 1); //find must return true for 101
    REQUIRE(set.find("301") == 1); //find must return true for 301
    REQUIRE(set.find("501") == 1); //find must return true for 501
    REQUIRE(set.find("701") == 1); //find must return true for 701
    REQUIRE(set.find("901") == 1); //find must return true for 901

    REQUIRE(set.find("102") == 0); //find must return false for 102
    REQUIRE(set.find("302") == 0); //find must return false for 302
    REQUIRE(set.find("502") == 0); //find must return false for 502
    REQUIRE(set.find("702") == 0); //find must return false for 702
    REQUIRE(set.find("902") == 0); //find must return false for 902

    REQUIRE(set.insert("100") == 0); //insert returns false for duplicate add
    REQUIRE(set.insert("300") == 0); //insert returns false for duplicate add
    REQUIRE(set.insert("500") == 0); //insert returns false for duplicate add
    REQUIRE(set.getSize() == 10); //size must be 10 after duplicate adds

    REQUIRE(set.find("100") == 1); //find must return true for 100
    REQUIRE(set.find("300") == 1); //find must return true for 300
    REQUIRE(set.find("500") == 1); //find must return true for 500
}

TEST_CASE("TEST GETSIZE", "test getSize() method")
{
    HashSet<string> set;
    REQUIRE(set.getSize() == 0); //size must be 0 after constructor
    set.clear();
    REQUIRE(set.getSize() == 0); //size must be 0 after clear
    set.insert("10");
    REQUIRE(set.getSize() == 1); //size must be 1 after add
    set.insert("20");
    REQUIRE(set.getSize() == 2); //size must be 2 after add
    set.insert("30");
    REQUIRE(set.getSize() == 3); //size must be 3 after add
    set.insert("40");
    REQUIRE(set.getSize() == 4); //size must be 4 after add
    set.insert("15");
    REQUIRE(set.getSize() == 5); //size must be 5 after add
    set.insert("25");
    REQUIRE(set.getSize() == 6); //size must be 6 after add
    set.insert("35");
    REQUIRE(set.getSize() == 7); //size must be 7 after add
    set.insert("45");
    REQUIRE(set.getSize() == 8); //size must be 8 after add
    set.clear();
    REQUIRE(set.getSize() == 0); //size must be 0 after clear
}

TEST_CASE("TEST CLEAR", "test clear() method")
{
     HashSet<string> set;
     set.clear();
     set.insert("10");
     set.insert("20");
     REQUIRE(set.isEmpty() == 0); //isEmpty returns false after adds
     set.clear();
     REQUIRE(set.getSize() == 0); //size is 0 after clear
     REQUIRE(set.isEmpty() == 1); //isEmpty returns true after clear
     set.insert("30");
     set.insert("40");
     set.insert("15");
     REQUIRE(set.isEmpty() == 0); //isEmpty returns false after add
     set.clear();
     REQUIRE(set.isEmpty() == 1); //isEmpty returns true after clear
     set.insert("25");
     set.insert("35");
     set.insert("45");
     REQUIRE(set.isEmpty() == 0); //isEmpty returns false after adds
     set.clear();
     REQUIRE(set.getSize() == 0); //size is 0 after clear
     REQUIRE(set.isEmpty() == 1); //isEmpty returns true after clear
}

TEST_CASE("TEST ISEMPTY", "Test isEmpty() method")
{
    HashSet<string> set;
    REQUIRE(set.isEmpty() == 1); //isEmpty returns true after constructor
    set.clear();
    REQUIRE(set.isEmpty() == 1); //isEmpty returns true after clear
    set.insert("10");
    set.insert("20");
    REQUIRE(set.isEmpty() == 0); //isEmpty return false after adds
    set.insert("30");
    set.insert("40");
    set.insert("15");
    REQUIRE(set.isEmpty() == 0); //isEmpty return false after adds
    set.insert("30");
    set.insert("40");
    set.insert("15");
    REQUIRE(set.isEmpty() == 0); //isEmpty return false after adds
    set.clear();
    REQUIRE(set.isEmpty() == 1); //isEmpty returns true after clear
    set.insert("10");
    set.insert("20");
    REQUIRE(set.isEmpty() == 0); //isEmpty return false after adds
}

TEST_CASE("TEST FIND", "Test find() method")
{
    HashSet<string> set;
    set.clear();
    set.insert("10");
    set.insert("20");
    set.insert("30");
    set.insert("40");
    set.insert("15");
    set.insert("25");
    set.insert("5");
    set.insert("1");
    REQUIRE(set.find("80") == 0); //find return false for 80
    REQUIRE(set.find("3") == 0); //find return false for 3
    REQUIRE(set.find("10") == 1); //find return true for 10
    REQUIRE(set.find("5") == 1); //find return true for 5
    REQUIRE(set.find("20") == 1); //find return true for 20
    REQUIRE(set.find("25") == 1); //find return true for 25
    REQUIRE(set.find("40") == 1); //find return true for 40
    set.clear();
    REQUIRE(set.find("10") == 0); //find returns false after clear
}

TEST_CASE("TEST ERASE", "Test erase() method")
{
    HashSet<string> set;
    set.clear();
    set.insert("10");
    set.insert("20");
    set.insert("30");
    set.insert("40");
    set.insert("15");
    set.insert("25");
    set.insert("35");
    set.insert("45");

    REQUIRE(set.getSize() == 8); //size must return 8 after failed remove

    REQUIRE(set.find("45") == 1); //find must return true for 45
    REQUIRE(set.erase("45") == 1); //erase must return true for 45
    REQUIRE(set.find("45") == 0); //find must return false for 45 after remove
    REQUIRE(set.getSize() == 7); //size must return 7 after remove

    REQUIRE(set.erase("10") == 1); //erase must return true for 10
    REQUIRE(set.find("10") == 0); //find must return false for 10 after remove
    REQUIRE(set.getSize() == 6); //size must return 6 after remove

    REQUIRE(set.find("40") == 1); //find must return true for 40
    REQUIRE(set.erase("40") == 1); //erase must return true for 40
    REQUIRE(set.getSize() == 5); //size must return 5 after remove

    REQUIRE(set.erase("20") == 1); //erase must return true for 20
    REQUIRE(set.find("20") == 0); //find must return false for 20 after remove
    REQUIRE(set.getSize() == 4); //size must return 4 after remove

    REQUIRE(set.erase("30") == 1); //erase must return true for 30
    REQUIRE(set.find("30") == 0); //find must return false for 30 after remove
    REQUIRE(set.getSize() == 3); //size must return 3 after remove

    REQUIRE(set.erase("15") == 1); //erase must return true for 15
    REQUIRE(set.find("15") == 0); //find must return false for 15 after remove
    REQUIRE(set.getSize() == 2); //size must return 2 after remove

    REQUIRE(set.erase("25") == 1); //erase must return true for 25
    REQUIRE(set.find("25") == 0); //find must return false for 25 after remove
    REQUIRE(set.getSize() == 1); //size must return 4 after remove
}




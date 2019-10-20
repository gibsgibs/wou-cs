//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "BSTree.h"
#include "Iterator.h"
//#include "AVLTree.h"

TEST_CASE( "TEST INSERT", "Test insert() method" ) {
    BSTree<int> tree;
    REQUIRE(tree.getSize() == 0); //size must be 0 after consructor

    tree.insert(8);
    tree.insert(12);
    tree.insert(4);
    tree.insert(6);
    tree.insert(10);
    tree.insert(2);
    tree.insert(14);
    REQUIRE(tree.getSize() == 7); //size must be 7 after adds

    REQUIRE(tree.search(8) == 1); //contains/search must be true for 8
    REQUIRE(tree.search(2) == 1); //contains/search must be true for 2
    REQUIRE(tree.search(10) == 1); //contains/search must be true for 10
    REQUIRE(tree.search(12) == 1); //contains/search must be true for 12
}

TEST_CASE("TEST GETSIZE", "Test getSize() method"){
    BSTree<int> tree;
    REQUIRE(tree.getSize() == 0); //size must be 0 after consructor
    tree.clear();
    REQUIRE(tree.getSize() == 0); //size must be 0 after clear
    tree.insert(10);
    REQUIRE(tree.getSize() == 1); //size must be 1 after add
    tree.insert(20);
    REQUIRE(tree.getSize() == 2); //size must be 2 after add
    tree.insert(30);
    REQUIRE(tree.getSize() == 3); //size must be 3 after add
    tree.insert(40);
    REQUIRE(tree.getSize() == 4); //size must be 4 after add
    tree.insert(15);
    REQUIRE(tree.getSize() == 5); //size must be 5 after add
    tree.insert(25);
    REQUIRE(tree.getSize() == 6); //size must be 6 after add
    tree.insert(35);
    REQUIRE(tree.getSize() == 7); //size must be 7 after add
    tree.insert(45);
    REQUIRE(tree.getSize() == 8); //size must be 8 after add
    tree.clear();
    REQUIRE(tree.getSize() == 0); //size must be 0 after clear
}

TEST_CASE("TEST CLEAR", "Test clear() method"){
    BSTree<int> tree;
    tree.clear();
    tree.insert(10);
    tree.insert(20);
    REQUIRE(tree.isEmpty() == 0); //isEmpty must be false after adds
    tree.clear();
    REQUIRE(tree.getSize() == 0); //size must be 0 after clear
    REQUIRE(tree.isEmpty() == 1); //isEmpty must be true after clear
    tree.insert(30);
    tree.insert(40);
    tree.insert(15);
    REQUIRE(tree.isEmpty() == 0); //isEmpty must be false after adds
    tree.clear();
    REQUIRE(tree.getSize() == 0); //size must be 0 after clear
    REQUIRE(tree.isEmpty() == 1); //isEmpty must be true after clear
    tree.insert(25);
    tree.insert(35);
    tree.insert(45);
    REQUIRE(tree.isEmpty() == 0); //isEmpty must be false after adds
    tree.clear();
    REQUIRE(tree.getSize() == 0); //size must be zero after clear
    REQUIRE(tree.isEmpty() == 1); //isEmpty must be true after clear
}

TEST_CASE("TEST ISEMPTY", "Test isEmpty method"){
    BSTree<int> tree;
    REQUIRE(tree.isEmpty() == 1); //isEmpty must be true after constructor
    tree.clear( );
    REQUIRE(tree.isEmpty() == 1); //isEmpty must be true after clear
    tree.insert( 10);
    tree.insert( 20);
    REQUIRE(tree.isEmpty() == 0); //isEmpty must be false after adds
    tree.insert( 30);
    tree.insert( 40);
    tree.insert( 15);
    REQUIRE(tree.isEmpty() == 0); //isEmpty must be false after adds
    tree.insert( 5);
    tree.insert( 1);
    tree.insert( 25);
    REQUIRE(tree.isEmpty() == 0); //isEmpty must be false after adds
    tree.clear( );\
    REQUIRE(tree.isEmpty() == 1); //isEmpty must be true after clear
    tree.insert( 10);
    tree.insert( 20);
    REQUIRE(tree.isEmpty() == 0); //isEmpty must be false after adds
}

TEST_CASE("TEST SEARCH", "Test search(element) method"){
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    tree.insert(5);
    tree.insert(1);
    REQUIRE(tree.search(80) == 0); //search must return false for 80
    REQUIRE(tree.search(3) == 0); //search must return false for 3
    REQUIRE(tree.search(10) == 1); //search must return true for 10
    REQUIRE(tree.search(5) == 1); //search must return true for 5
    REQUIRE(tree.search(1) == 1); //search must return true for 1
    REQUIRE(tree.search(20) == 1); //search must return true for 20
    REQUIRE(tree.search(25) == 1); //search must return true for 25
    REQUIRE(tree.search(40) == 1); //search must return true for 40
    tree.clear();
    REQUIRE(tree.search(10) == 0); //search must return false after clear
}

TEST_CASE("TEST ITERATION", "Test iterator() method"){
    int sum = 0;
    BSTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);

    Iterator<int> it = tree.begin();

    for(unsigned i = 0; i < it.v.size(); i++){
        int num = it.v[i];
        //num = num - 0;
        sum = sum + num;
    }



    REQUIRE(sum == 45); //sum of BST/vector must be 45
}

//TEST_CASE("TEST AVL ADD", "test AVL insert() method"){
//    AVLTree<int> tree;
//    REQUIRE(tree.getSize() == 0); //size must be 0 after constructor

//    //Test simple 3 node single rotate right
//    tree.clear();
//    tree.insert(3);
//    tree.insert(2);
//    tree.insert(1);
//    REQUIRE(tree.getSize() == 3); //size must be 3 after adds
//    REQUIRE(tree.search(1) == 1); //search must return true for 1
//    REQUIRE(tree.search(2) == 1); //search must return true for 2
//    REQUIRE(tree.search(3) == 1); //search must return true for 3

//    //inorder traversal check
//    Iterator<int> it = tree.begin();
//    REQUIRE(it.v[0] == 1);
//    REQUIRE(it.v[1] == 2);
//    REQUIRE(it.v[2] == 3);

//    //test simple 3 node single rotate left
//    tree.clear();
//    tree.insert(4);
//    tree.insert(5);
//    tree.insert(6);
//    REQUIRE(tree.getSize() == 3); //size must be 3 after adds
//    REQUIRE(tree.search(4) == 1); //search must return true for 4
//    REQUIRE(tree.search(5) == 1); //search must return true for 5
//    REQUIRE(tree.search(6) == 1); //search must return true for 6

//    it = tree.begin();
//    REQUIRE(it.v[0] == 4);
//    REQUIRE(it.v[1] == 5);
//    REQUIRE(it.v[2] == 6);

//    //test simple 3 node double rotate right
//    tree.clear();
//    tree.insert(9);
//    tree.insert(7);
//    tree.insert(8);
//    REQUIRE(tree.getSize() == 3); //size must be 3 after adds
//    REQUIRE(tree.search(7) == 1); //search must return true for 7
//    REQUIRE(tree.search(8) == 1); //search must return true for 8
//    REQUIRE(tree.search(9) == 1); //search must return true for 9

//    it = tree.begin();
//    REQUIRE(it.v[0] == 7);
//    REQUIRE(it.v[1] == 8);
//    REQUIRE(it.v[2] == 9);

//    //Test simple 3 node double rotate left
//    tree.clear();
//    tree.insert(1);
//    tree.insert(3);
//    tree.insert(2);
//    REQUIRE(tree.getSize() == 3); //size must be 3 after adds
//    REQUIRE(tree.search(1) == 1); //search must return true for 1
//    REQUIRE(tree.search(2) == 1); //search must return true for 2
//    REQUIRE(tree.search(3) == 1); //search must return true for 3

//    //inorder traversal check
//    it = tree.begin();
//    REQUIRE(it.v[0] == 1);
//    REQUIRE(it.v[1] == 2);
//    REQUIRE(it.v[2] == 3);

//    //Test larger tree single rotate right
//    tree.clear();
//    tree.insert(8);
//    tree.insert(9);
//    tree.insert(5);
//    tree.insert(7);
//    tree.insert(3);
//    tree.insert(1);
//    REQUIRE(tree.getSize() == 6); //size must be 6 after adds
//    REQUIRE(tree.search(8) == 1); //search must return true for 8
//    REQUIRE(tree.search(9) == 1); //search must return true for 9
//    REQUIRE(tree.search(5) == 1); //search must return true for 5
//    REQUIRE(tree.search(7) == 1); //search must return true for 7
//    REQUIRE(tree.search(3) == 1); //search must return true for 3
//    REQUIRE(tree.search(1) == 1); //search must return true for 1

//    //inorder traversal check
//    it = tree.begin();
//    REQUIRE(it.v[0] == 1);
//    REQUIRE(it.v[1] == 3);
//    REQUIRE(it.v[2] == 5);
//    REQUIRE(it.v[3] == 7);
//    REQUIRE(it.v[4] == 8);
//    REQUIRE(it.v[5] == 9);

//    //Test larger tree single rotate left
//    tree.clear();
//    tree.insert(3);
//    tree.insert(7);
//    tree.insert(1);
//    tree.insert(8);
//    tree.insert(5);
//    tree.insert(9);
//    REQUIRE(tree.getSize() == 6); //size must be 6 after adds
//    REQUIRE(tree.search(8) == 1); //search must return true for 8
//    REQUIRE(tree.search(9) == 1); //search must return true for 9
//    REQUIRE(tree.search(5) == 1); //search must return true for 5
//    REQUIRE(tree.search(7) == 1); //search must return true for 7
//    REQUIRE(tree.search(3) == 1); //search must return true for 3
//    REQUIRE(tree.search(1) == 1); //search must return true for 1

//    //inorder traversal check
//    it = tree.begin();
//    REQUIRE(it.v[0] == 1);
//    REQUIRE(it.v[1] == 3);
//    REQUIRE(it.v[2] == 5);
//    REQUIRE(it.v[3] == 7);
//    REQUIRE(it.v[4] == 8);
//    REQUIRE(it.v[5] == 9);

//    //Test larger tree double rotate right
//    tree.clear();
//    tree.insert(8);
//    tree.insert(9);
//    tree.insert(3);
//    tree.insert(5);
//    tree.insert(1);
//    tree.insert(7);
//    REQUIRE(tree.getSize() == 6); //size must be 6 after adds
//    REQUIRE(tree.search(8) == 1); //search must return true for 8
//    REQUIRE(tree.search(9) == 1); //search must return true for 9
//    REQUIRE(tree.search(5) == 1); //search must return true for 5
//    REQUIRE(tree.search(7) == 1); //search must return true for 7
//    REQUIRE(tree.search(3) == 1); //search must return true for 3
//    REQUIRE(tree.search(1) == 1); //search must return true for 1

//    //inorder traversal check
//    it = tree.begin();
//    REQUIRE(it.v[0] == 1);
//    REQUIRE(it.v[1] == 3);
//    REQUIRE(it.v[2] == 5);
//    REQUIRE(it.v[3] == 7);
//    REQUIRE(it.v[4] == 8);
//    REQUIRE(it.v[5] == 9);

//    //Test larger tree double rotate left
//    tree.clear();
//    tree.insert(3);
//    tree.insert(8);
//    tree.insert(1);
//    tree.insert(5);
//    tree.insert(9);
//    tree.insert(7);
//    REQUIRE(tree.getSize() == 6); //size must be 6 after adds
//    REQUIRE(tree.search(8) == 1); //search must return true for 8
//    REQUIRE(tree.search(9) == 1); //search must return true for 9
//    REQUIRE(tree.search(5) == 1); //search must return true for 5
//    REQUIRE(tree.search(7) == 1); //search must return true for 7
//    REQUIRE(tree.search(3) == 1); //search must return true for 3
//    REQUIRE(tree.search(1) == 1); //search must return true for 1

//    //inorder traversal check
//    it = tree.begin();
//    REQUIRE(it.v[0] == 1);
//    REQUIRE(it.v[1] == 3);
//    REQUIRE(it.v[2] == 5);
//    REQUIRE(it.v[3] == 7);
//    REQUIRE(it.v[4] == 8);
//    REQUIRE(it.v[5] == 9);
//}

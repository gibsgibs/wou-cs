/**
  * @brief rectangle
  * @authors Gibs, Jacob M., Meg
  */

//Bring in unit testing code
#include "catch.hpp"
#include "rectangle.h"
#include <cmath>
#include <iostream>

TEST_CASE( "Testing first constuctor", "3 argument constuctor" ) {
    Point p1(0, 5);
    //taking in point, width, height
    Rectangle r1(p1, 4 ,2);
    Point temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1));
    REQUIRE(r1.getHeight() == Approx(2));
    REQUIRE(r1.getWidth() == Approx(4));
}
TEST_CASE("Testing second constuctor", "2 argument constuctor") {
    Point p1(0, 5);
    Point p2(5, 0);
    Rectangle r1(p1, p2);
    Point temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1));
    REQUIRE(r1.getHeight() == Approx(5));
    REQUIRE(r1.getWidth() == Approx(5));
}
TEST_CASE("Testing getUpperLeftVertex")
{
    Point p1(0, 5);
    Point p2(5, 0);
    Rectangle r1(p1, p2);
    Point temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1));
}
TEST_CASE("testing get get area function")
{
    Point p1(0, 5);
    Point p2(5, 0);
    Rectangle r1(p1, p2);
    double theArea = r1.getArea();
    REQUIRE(theArea == Approx(25));
}
TEST_CASE("get perimeter")
{
    Point p1(0, 5);
    Point p2(5, 0);
    Rectangle r1(p1, p2);
    double thePerimeter = r1.getPerimeter();
    REQUIRE(thePerimeter == Approx(20));
}
TEST_CASE("testing the get center function")
{
    Point p1(0, 5);
    Point p2(5, 0);
    Rectangle r1(p1, p2);
    Point temp(2.5, 2.5);
    REQUIRE(r1.getCenter().isSameAs(temp));
}
TEST_CASE("testing the shift function")
{
    Point p1(0, 5);
    Point p2(5, 0);
    Rectangle r1(p1, p2);
    r1.shift(1, 1);
    REQUIRE(r1.getUpperLeftVertex().getX() == Approx(1));
    REQUIRE(r1.getUpperLeftVertex().getY() == Approx(6));
}
TEST_CASE("Testing the contains function")
{
    Point p1(0, 5);
    Point p2(5, 0);
    Point p3(0.5, 2.5);
    Point p4(6, 6);
    Rectangle r1(p1, p2);
    r1.contains(p3);
    REQUIRE(r1.contains(p3) == true);
    REQUIRE(r1.contains(p4) == false);
}

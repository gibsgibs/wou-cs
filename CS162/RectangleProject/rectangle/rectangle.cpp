/**
  * @brief rectangle
  * @authors Gibs, Jacob M., Meg
  */

#include <iostream>
#include <cmath>

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(Point p1, Point p2)
{
    width = abs(p2.getX() - p1.getX());
    height = abs(p1.getY() - p2.getY());
    upperLeftVertex.setX(p1.getX());
    upperLeftVertex.setY(p1.getY());
}
Rectangle::Rectangle(Point p1, double theWidth, double theHeight)
{
    width = theWidth;
    height = theHeight;
    upperLeftVertex.setX(p1.getX());
    upperLeftVertex.setY(p1.getY());
}
Point Rectangle::getUpperLeftVertex() const
{
    return upperLeftVertex;
}
double Rectangle::getWidth() const
{
    return width;
}
double Rectangle::getHeight() const
{
    return height;
}
double Rectangle::getArea() const
{
    double area = width * height;
    return area;
}
double Rectangle::getPerimeter() const
{
    double perimeter = 2 * width + 2 * height;
    return perimeter;
}
Point Rectangle::getCenter() const
{
    double xCenter = width / 2;
    double yCenter = height / 2;
    Point center(xCenter, yCenter);
    return center;
}
void Rectangle::shift(double xShift, double yShift)
{
    double xPos = upperLeftVertex.getX();
    double yPos = upperLeftVertex.getY();
    xPos += xShift;
    yPos += yShift;
    upperLeftVertex.setX(xPos);
    upperLeftVertex.setY(yPos);

}
bool Rectangle::contains(Point p)
{
    if((p.getX() >= upperLeftVertex.getX()) && (p.getX() <= (upperLeftVertex.getX() + width)) &&
       (p.getY() <= upperLeftVertex.getY()) && (p.getY() >= (upperLeftVertex.getY() - height)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

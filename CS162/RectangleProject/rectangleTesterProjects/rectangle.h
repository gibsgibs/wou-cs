#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

class Rectangle
{
private:
    Point upperLeftVertex;
    double height;
    double width;
public:
    Rectangle(Point p1, Point p2);
    Rectangle(Point p1, double width, double height);
    Point getUpperLeftVertex() const;
    double getWidth() const;
    double getHeight() const;
    double getArea() const;
    double getPerimeter() const;
    Point getCenter() const;
    void shift(double xShift, double yShift);
    bool contains(Point p);
};
#endif // RECTANGLE_H

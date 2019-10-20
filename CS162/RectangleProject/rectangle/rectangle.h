/**
  * @brief rectangle
  * @authors Gibs, Jacob M., Meg
  */

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
    /**
     * @brief getUpperLeftVertex - gets the upper left vertex of the rectangle
     * @return the upper left vertex
     */
    Point getUpperLeftVertex() const;
    /**
     * @brief getWidth - gets the width
     * @return the width
     */
    double getWidth() const;
    /**
     * @brief getHeight - gets the height
     * @return the height
     */
    double getHeight() const;
    /**
     * @brief getArea - computes the area
     * @return the area
     */
    double getArea() const;
    /**
     * @brief getPerimeter - computes the perimeter
     * @return the perimeter
     */
    double getPerimeter() const;
    /**
     * @brief getCenter - finds the center based on the vertex, height and width
     * @return the center
     */
    Point getCenter() const;
    /**
     * @brief shift - shifts the rectangle by moving where the upper left vertex is
     * @param xShift - the amount of x shifting
     * @param yShift - the amount of y shifting
     */
    void shift(double xShift, double yShift);
    /**
     * @brief contains - checks if the rectangle contains the given point
     * @param p - a point
     * @return true or false
     */
    bool contains(Point p);
};
#endif // RECTANGLE_H

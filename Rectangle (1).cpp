/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Casey Lee
 * leecasey
 *
 * This represents a rectangle.
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// Default contructor
Rectangle::Rectangle() {
}

//Overloaded contructor that sets start, end and single color
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    start = pt1;
    end = pt2;
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

//Overloaded contructor that sets start, end and four colors
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
    
}

// Sets start point (top left) of rectangle.
void Rectangle::setStart(Point pt) {
    start = pt;
}

// Returns start point of rectangle
Point Rectangle::getStart() {
    return start;
}

// Sets end point (bottom right) of rectangle
void Rectangle::setEnd(Point pt) {
    end = pt;
}

// Returns end point of rectangle.
Point Rectangle::getEnd() {
    return end;
}

//Sets the four colors of rectangle to color
void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

// Sets top left color of rectangle
void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}
 
// Returns top left color of rectangle.
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

// Sets top right color of rectangle
void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

// Returns top right color of rectangle.
Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

// Sets bottom right color of rectangle.
void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

// Returns bottom right color of rectangle
Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

// Sets bottom left color of rectangle.
void Rectangle::setColorBottomLeft(Color c) {
    colorBottomLeft = c;
}

// Returns bottom left color of rectangle.
Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

//Reads rectangle in forms
void Rectangle::read(istream& ins) {
    ins >> start >> end >> colorTopLeft >> colorTopRight >>
        colorBottomRight >> colorBottomLeft;
    
    // check if it failed or not
    if (ins.fail()) {
        ins.clear();
        
        colorTopRight = colorTopLeft;
        colorBottomRight = colorTopLeft;
        colorBottomLeft = colorTopLeft;
    }
}

// Writes rectangle in form
void Rectangle::write(ostream& outs) {
    outs << start << " " << end << " " << colorTopLeft << " " << colorTopRight
        << " " << colorBottomRight << " " << colorBottomLeft;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}

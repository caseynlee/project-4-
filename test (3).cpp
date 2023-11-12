/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Casey Lee
 * leecasey
 *
 * Contains functions for testing classes in the project. 
 */

#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;

void test_Point();
void test_Color();
void test_Circle();
void test_Line();
void test_Rectangle();
void test_Triangle();

// testing functions
void startTests() {
    test_Point();
    test_Color();
    test_Line();
    test_Triangle();
    test_Circle();
    test_Rectangle();
    
    return;
}

// test Point
void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0, 0), actual: " << p1 << endl;
    
    // test second point within dimensions
    Point p2(3, 9);
    cout << "Expected: (3, 9), actual: " << p2 << endl;
    
    // test third point out of dimensions
    Point p3(-1, 105);
    cout << "Expected: (-1, 105), actual: " << p2 << endl;

    // test fourth point with setters
    Point p4;
    p4.setX(5);
    p4.setY(3);
    
    cout << "Expected: (5, 3), actual: ";
    cout << "( " << p4.getX()
         << ", " << p4.getY()
         << " )" << endl;
    
    // test fifth point with negative setters
    Point p5;
    p5.setX(-5);
    p5.setY(-3);
    
    cout << "Expected: (-5, -3), actual: ";
    cout << "( " << p5.getX()
         << ", " << p5.getY()
         << " )" << endl;
    
    return;
}

// test Color
void test_Color() {
    // default  constructor
    Color c1(0, 0, 0);
    cout << "Expected: (0, 0, 0), actual: " << c1 << endl;
    
    // test within range
    Color c2(50, 50, 50);
    cout << "Expected: (50, 50, 50), actual: " << c2 << endl;
    
    // test outside of range
    Color c3(-1, 300, 300);
    cout << "Expected: (-1, 300, 300), actual: " << c3 << endl;
    
    // test setters and getters
    Color c4;
    c4.setRed(-300);
    cout << "c4 is: " << c4.getRed();
    c4.setRed(50);
    cout << "c4 is: " << c4.getRed();
    c4.setRed(0);
    cout << "c4 is: " << c4.getRed();
    
    c4.setBlue(-300);
    cout << "c4 is: " << c4.getBlue();
    c4.setBlue(50);
    cout << "c4 is: " << c4.getBlue();
    c4.setBlue(0);
    cout << "c4 is: " << c4.getBlue();
    
    c4.setGreen(-300);
    cout << "c4 is: " << c4.getGreen();
    c4.setGreen(50);
    cout << "c4 is: " << c4.getGreen();
    c4.setGreen(0);
    cout << "c4 is: " << c4.getGreen();
    
    // test range
    Color c5(0, 255, 0);
    cout << "Expected: (0, 255, 0), actual: " << c5 << endl;
}

// test Line
void test_Line() {
    Point p1;
    Point p2;
    Color c1(30,30,50);
    
    // test default constructor
    Line l1;
    cout << "l1 is " << l1 << endl;
    
    // test different constructor
    Line l2(p1, p2, c1);
    cout << "l2 is " << l2 << endl;
    
    // test setEnd and setStart
    Line l4;
    l4.setStart(p1);
    cout << "l4 start is: " << l4.getStart() << endl;

    l4.setEnd(p2);
    cout << "l4 end is: " << l4.getEnd() << endl;
    
    l4.setColor(c1);
    cout << "l4 color is: " << l4.getColor() << endl;
    
    l4.read(cin);
    cout << "l4 read is: " << l4 << endl;
}

// test Rectangle
void test_Rectangle() {
    Point p1;
    Point p2;
    Point p3;
    Color c1;
    Color c2;
    Color c3;
    Color c4;
    
    // default constructor
    Rectangle r1;
    cout << r1 << endl;
    
    // test non default constructor
    Rectangle r2(p1, p2, c1);
    cout << "r2 is: " << r2 << endl;
    
    // test wrong data
    Rectangle r3(p2, p2, c1);
    cout << "r3 is: " << r3 << endl;
    
    // test non default constructor
    Rectangle r4(p1, p2, c1, c2, c3, c4);
    cout << "r4 is: " << r4 << endl;
    
    // test setters and getters
    r1.setStart(p2);
    cout << "r1 one is: " << r1.getStart() << endl;
    r1.setEnd(p3);
    cout << "r1 one is: " << r1.getEnd() << endl;
    r1.setColorTopLeft(c1);
    cout << "r1 one is: " << r1.getColorTopLeft() << endl;
    r1.setColorTopRight(c3);
    cout << "r1 one is: " << r1.getColorTopRight() << endl;
    r1.setColorBottomRight(c1);
    cout << "r1 one is: " << r1.getColorBottomRight() << endl;
    r1.setColorBottomLeft(c2);
    cout << "r1 one is: " << r1.getColorBottomLeft() << endl;
    
}

// test Triangle
void test_Triangle() {
    Point p1;
    Point p2;
    Point p3;
    Color c1;
    Color c2;
    Color c3;
    
    // default constructor
    Triangle t1;
    cout << t1 << endl;
    
    // test second constructor
    Triangle t2(p1, p2, p3, c1);
    cout << t2 << endl;
    
    // test last constructor
    Triangle t3(p1, c1, p2, c2, p3, c3);
    cout << t3 << endl;
    
    // test setters and getters
    Triangle t4;
    t4.setVertexOne(p3);
    cout << "t4 vertex one is: " << t4.getVertexOne() << endl;
    t4.setVertexThree(p1);
    cout << "t4 vertex one is: " << t4.getVertexOne() << endl;
    t4.setVertexOneColor(c3);
    cout << "t vertex three color is: " << t4.getVertexThreeColor();
    t1.setVertexThreeColor(c1);
    cout << "t vertex three color is: " << t4.getVertexThreeColor();
}

// test Circle
void test_Circle() {
    Point p1;
    Point p2;
    Color c1;
    Color c2;
    Color c3;
    Point center(4,8);
    int r = 4;
    
    // default
    Circle i1;
    cout << i1.getCenter() << endl;
    cout << i1.getRadius() << endl;
    cout << i1.getColor() << endl;
    i1.read(cin);
    cout << i1 << endl;
    
    // test within range
    Circle i2(p2, 50, c1);
    cout << i2.getCenter() << endl;
    cout << i2.getRadius() << endl;
    cout << i1.getColor() << endl;
    i1.read(cin);
    cout << i2 << endl;
    
    // test outside of range
    Circle i3(p2, -50, c3);
    cout << i3.getCenter() << endl;
    cout << i3.getRadius() << endl;
    cout << i3.getColor() << endl;
    i3.read(cin);
    cout << i3 << endl;
    
    // test setters
    Circle i4;
    i4.setRadius(50);
    cout << "i4 center is: " << i4.getRadius() << endl;
    i4.setRadius(0);
    cout << "i4 center is: " << i4.getRadius() << endl;
    i4.setRadius(-10);
    cout << "i4 center is: " << i4.getRadius() << endl;
    i4.setRadius(300);
    cout << "i4 center is: " << i4.getRadius() << endl;
}

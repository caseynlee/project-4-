/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Casey Lee
 * leecasey
 *
 * This will represent a color in RGB mode.
 */

#include "Color.h"

//Default constructor sets black to (0,0,0)
Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

//This constructor sets RGB values
Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

// Sets red value
void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

// Returns red
int Color::getRed() {
    return red;
}

// Sets green value
void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}
 
// Returns green
int Color::getGreen() {
    return green;
}

// Sets blue value
void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

// Returns blue
int Color::getBlue() {
    return blue;
}

// Reads input of color in form red green blue
void Color::read(istream& ins) {
    ins >> red >> green >> blue;
    red = checkRange(red);
    green = checkRange(green);
    blue = checkRange(blue);
}

// Reads output of color in form red green blue
void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue << " ";
}

int Color::checkRange(int val) {
    if (val < 0) {
        return 0;
    }
    else if (val > 255){
        return 255;
    }
    else {
        return val;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}

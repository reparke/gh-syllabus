/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/


#include "Shape.h"  //needed to refer to Shape objects
#include "Rectangle.h"  //needed to refer to Shape objects
            
#include <string>    //needed for string objects

#include <iostream>    //needed for cout

/*

Calling parent constructor
  As in Java / Python, in a child constructor we will want to call the parent constructor.
  In C++, this must be done immediately and OUTSIDE of the function definition.
  The notation is as follows

    CHILD_CONSTR(...)
      :  PARENT_CONSTR(...)
    {
      // rest of the child constructor defintion
    }
 
  Note that if you don't specify a parent constructor, the default (parameterless)
    constructor of the parent will be called.

Calling parent methods
  As in Java / Python, it is possible to make an explicit call to a parent method
  The notation is as follows

    PARENT_CLASS :: PARENT_METHOD(...)

  In the example below, the Shape class has a method called display.
    The Rectangle class inherits from Shape and overrides the display method.
    To make call to the parents version display from the Rectangle class, you use

      void display() {
        Shape::display();
        ...

*/

Rectangle::Rectangle() // No parent constructor specified, so calls Shape()
{
  length = 0.0;
  width = 0.0;
}

//overloaded constructor
Rectangle::Rectangle(std::string& inputName, double inputlength, double inputWidth)
  : Shape(inputName) // Call the Shape constructor that takes in a std::string
{
  length = inputlength;
  width = inputWidth;
}

//accessor / mutator
void Rectangle::setLength(double inputlength)
{
  length = inputlength; 
}

void Rectangle::setWidth(double inputWidth)
{
  width = inputWidth; 
}

double Rectangle::getLength()
{
  return length; 
}

double Rectangle::getWidth()
{
  return width; 
}

//methods
double Rectangle::calcArea()
{
  return length * width;
}
    
void Rectangle::display()
{
  Shape::display();
  std::cout << "length = " << length << std::endl;
  std::cout << "width = " << width << std::endl;
}

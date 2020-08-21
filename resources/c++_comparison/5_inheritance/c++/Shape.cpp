/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

/* Implementation of Shape class
 
  Notice that in this file, all of the function implementations are
    prefaced with Shape::

  This is how we specify to C++ that all of these functions we are
    implementing exist inside of the Shape class.
*/
#include "Shape.h"    //connect to class header definition

#include <iostream>    //needed for cout

//default constructor
Shape::Shape()
{
  name = "unnamed";
}

//overloaded constructor
Shape::Shape(std::string& inputName) // by reference
{
  name = inputName;
}

//accessor / mutator
void Shape::setName(std::string& inputName) // by reference
{
  name = inputName; 
}

std::string Shape::getName()
{
  return name; 
}
    
//methods
void Shape::display()
{
  std::cout << "name = " << name << std::endl;
}

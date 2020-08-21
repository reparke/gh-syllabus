/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

// This file defines the prototype (aka outline) of the Shape class
 
#pragma once      // Required at the top of new header (.h) files

// We need to include string here because the prototype of Shape requires
// to know what a std::string is, as there is a std::string member variable.

#include <string>    //needed for string objects

class Shape
{
private:          //private member declarations
  std::string name;

public:            // public member declarations
  //default constructor
  Shape();

  //overloaded constructor
  Shape(std::string& inputName); // By reference

  //accessor / mutator
  void setName(std::string& inputName); // By reference
  std::string getName();

  //methods
  void display();

};   // class ends with a semi-colon


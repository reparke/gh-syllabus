/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

/*
Multiple files
 
  In the typical usage case, for each class we create there will be corresponding
    .h and .cpp files.
 
  The .h file is the "outline" of the class that contains the name of the class, the
    variables in the class, and the name of all the member functions in the class (but not
    the implementation of the functions).
 
  The .cpp file contains the implementation of all the member funcitons in the class.
 
  In this project, there are 4 additional files;
    Shape.h/cpp - The base "Shape" class
    Rectangle.h/cpp - The Rectangle class that inherits from the Shape class.
 
  More information on inheritance is in the Rectangle.h file.
 
*/
#include "Rectangle.h"  // This is our custom Rectangle library that defines the Rectangle object
#include <iostream>    // for cin and cout

int main()
{
  //create Rectangle object with default (no arguments) constructor
  Rectangle rect1;
  //create Rectangle with overloaded constructor
  std::string name = "tennis court";
  Rectangle tennisCourt = Rectangle(name, 78, 36);

  double area = 0;
  
  std::cout << "Calling 'display()' on the rect1 results in the following output:" << std::endl;
  rect1.display();
  std::cout << std::endl;
  
  
  std::cout << "Calling 'display()' on the rectTennisCourt results in the following output:" << std::endl;
  tennisCourt.display();
  std::cout << std::endl;

  area = tennisCourt.calcArea();
  std::cout << "The area of " << tennisCourt.getName() << " is " << area << " feet";
  std::cout << std::endl << std::endl;

  return 0;
}

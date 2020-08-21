/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/


/*
Classes concept
  Very similar to Java / Python with most syntax changes
  
  Class can contain instance variables and instance methods
  Methods and variables can have an access level (public, private, or protected)
 
Definition
  As in Java / Python, classes are defined in a block of code and begin with the word "class"
 
  Class definitions end with a SEMI-COLON;
 
Constructor
  The constructor method always has the same name as the class
 
  Python: There is no __init__.  Instead, the class name serves as the constructor.
    For instance, the class "Coffee" would have a constructor called
    Coffee()
 
Public / Private and declaring instance variables
  Classes in C++ have a public and private section.
  Within each section you specify all the methods and variables that are either public or private
 
  For example, if a class has private int variable foo and public methods getFoo and setFoo, use
    private:
      int foo;
    public:
      int getFoo()
        ...
      void setFoo(int num)
        ...
 
  Java: You do not specify "public" or "private" for every variable / method.
    Rather, you include all relevant variables / methods with section.

  Python: A major difference in C++ is that you MUST define all instance variables
    in the class defintion (i.e. OUTSIDE of the constructor).
    For example, instead of creating private variale "self.__foo" in __init__,
      you instead use "int foo" in the private section of the class.
    This follows the C++ principle that you must define ahead of time all
      variables / functions before using them
 
Parameters by value vs. by reference
  When parameters are passed to functions, there are two primary options:
    - If a parameter is passed by value, a copy of the parameter is passed
      to the function. Generally, basic types (such as int, double, etc)
      should be passed by value.
    - If a parameter is passed by reference, the variable is handed off to the
      class, and no copy is made. Generally, object types (such as std::string,
      and custom classes) should be passed by reference.
    ** A major exception to this is arrays. Arrays are never copied, and are
      more or less "automatically" passed by reference
  
  We have been passing parameters by value in our functions so far. So for
    example, calcSquare takes in the parameter num by value:
      int calcSquare(int num)
      {
        return num * num;
      }
 
  To pass a parameter by reference, an ampersand & is placed between the type and the
    parameter name. So for example, this function takes in a std::string by reference:
      void printString(std::string& toPrint)
      {
        std::cout << toPrint << std::endl;
      }
 
Note: In this example, we declare our class and use it in the same file.
  Typically, this is not the case and we create separate .h/.cpp files for each class
  (as in the Inheritance example #5).
 
As with functions, classes must be declared before any code that uses them.
 
*/

#include "Order.h"  // This is our custom Rectangle 
#include <iostream>    //needed for cin / cout
#include <string>    //needed for strings


// function prototype
void finalizeOrder(Order& newOrder) // Pass by reference!
{
  double cost = 0;
  
  newOrder.displayOrder();
  cost = newOrder.calcCost();
  std::cout << "Your order costs $" << cost;
  
}

int main() {
  //const means the variable is a CONSTANT and can not change
  const double COST_PER_POUND = 7.99;

  //create an order object
  //Java: note we do not use NEW in the basic case of constructing
  // a class as a local variable
  Order order1;
  std::string tempName = "";
  int tempPounds = 0;
  
  std::cout << "Enter coffee name (one word please): ";
  std::cin >> tempName;
  order1.setName(tempName);

  std::cout <<"Enter # of pounds: ";
  std::cin >> tempPounds;
  order1.setPounds(tempPounds);

  order1.setCostPerPound(COST_PER_POUND);

  finalizeOrder(order1);

  std::cout << std::endl << std::endl;

  return 0;
}









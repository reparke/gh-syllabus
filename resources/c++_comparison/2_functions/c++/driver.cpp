/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

/*
Creating and using functions
  As in Java/Python, C++ has "function declarations" where you specify what the function does
    and "function calls" where you actually use the function
  Functions must be declared before they are used. So if the functions are used in main
    they must be declared before main.
 
  If two functions call each other, this issue can be solved, using something called
    "function prototypes". But don't worry about that just yet.
 
  A program in a single file will typically be structured as:

    #include ...
    
    // any function declarations

    int main()
    {
      ...
    }

  

Function syntax
  RETURN_TYPE NAME_OF_FUNCTION (INPUT_TYPE1 INPUT_PARAMETER1, ... )
  {
    BODY_OF_FUNCTION
  }
 
  For example,
    int calcSquare(int numberToSquare)
    {
      return numberToSquare * numberToSquare;
    }

Return type
  Every function must specify a return type (e.g. int, bool, string)
    and should end with a return statement
  If the function does not return anything, the return type must be "void"
    In this case, the return statement is optional
    
Input parameters
  Functions can take zero or more input parameters
  Every input parameter must have a data type specified
  For example,
    void printThings(string word, int num, double pi)

Functions vs. Methods
  Technically, functions are free-standing executing blocks
    while methods are blocks that a part of a class (just like Python)
  Notice that this file defines functions WITHOUT using classes

  Java:
    Java does not have this concept of functions because all "executing blocks"
      are part of some class of everything is a method.
    You can consider "functions" to be similar to "public static void"
      methods you created--basically you can call the functions without
      creating an instance of a class

Default Values
  Python: Generally, C++ doesn't use default values in functions.
    Instead, the preferred approach is to "overload functions,"
    which is explained in the "Inheritance" example

*/

#include <iostream>

// Function declarations

// CalcSumSquares
// Takes two parameters (the numbers to square and then sum)
// Returns the result of the computation as an integer
int calcSumSquares(int num1, int num2)
{
  return num1 * num1 + num2 * num2;
}

// displayResult
// Takes three parameters to display to cout
// Returns nothing (void)
void displayResult(int num1, int num2, int result)
{
  std::cout << "The sum of squares of " << num1 << " and " << num2 << " is " << result;
  std::cout << std::endl << std::endl;
  
  //since this function returns void, there is no need for a return statement
}

// main
int main()
{
  int a = 0, b = 0, result = 0;

  std::cout << "Enter two integers: ";
  std::cin >> a >> b;

  //calling function calcSumSquares with inputs a and b
  //and storing the return value in result
  result = calcSumSquares(a, b);  

  //calling function display result
  //return type is void so there is not result to store
  displayResult(a, b, result);
  return 0;
}




/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/



/*
Array concept
  Arrays in C++ are similar to very arrays in Java and "somewhat" similar lists in Python
  One major difference in C++ is that arrays are not objects
    This means they are a little more difficult to work with

  Arrays are a data structure that store variables which can be accessed by an integer index
  Indices start at zero and go up to (ARRAY_SIZE - 1)

  Python: 
    Arrays can NOT be resized after they are created
      As a result, you can not create empty arrays and then append to them
    Every element of an array MUST hold the same type of data (unlike lists)
  Java / Python:
    Arrays can NOT tell you their own size (since they are not objects)
    This means you must always keep track of the size yourself

Creating arrays
  DATA_TYPE NAME_OF_ARRAY [ARRAY_SIZE];
  For example,
    int numbers [5];
    string words [26];
  
  Java / Python:
    The size of the array can NOT be determined at run-time.
      It must be a known constant size in the code.
      This means you can NOT ask the user for a size and THEN create the array
    In the below example, you can use a variable for the size of "numbers" only 
      because SIZE_OF_ARRAY is a constant

Accessing arrays
  Use the [ ] operator
    int numbers [5];
    numbers[0] = 36;
    cout << numbers[0];

Arrays as arguments to functions
  To pass an array as input to a function, simply use the name of the array
    int numbers[5];
    ...
    int result = calcSum(numbers);

  To write a function prototype with an array input, use the following syntax
    int calcSum(int numArray[])
 
unsigned
  unsigned is a type modifier for integral types, that specifies the number is
    greater than or equal to zero, and cannot be negative.
  
  To declare an integer as unsigned, simply add unsigned in front of int:
    unsigned int myUnsignedInt;
 
const
  const means that the variable cannot be modified after declaration. So
    if you create a const integral value, you can use that as a size of the
    array, since it is a known constant size.

*/
#include <iostream>

//function defintion
// calcSum takes in two parameters:
//    - The integer array
//    - The size of the array
int calcSum(int numArray[], unsigned int size)
{
  int sum = 0;
  for (unsigned int i = 0; i < size; i++)
  {
    sum += numArray[i];
  }
  return sum;
}

//main
int main()
{
  const unsigned int SIZE_OF_ARRAY = 4; // array MUST be initalized with constant values

  int numbers[SIZE_OF_ARRAY];    // do not need to use NEW to initialize
                  // however, you can not have the size be dynamically
                  // assigned (i.e. by user input at run-time

  //fill array with user input
  for (unsigned int i = 0; i < SIZE_OF_ARRAY; i++)  // note that arrays in C++ are not objects
  {                          // so they have no mechanism to store
    std::cout << "Enter num: ";            // the array size
    std::cin >> numbers[i];
  }

  //print array
  std::cout << "The numbers in the array are: ";
  for (unsigned int i = 0; i < SIZE_OF_ARRAY; i++)
  {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  int sum = calcSum(numbers, SIZE_OF_ARRAY);
  std::cout << "The sum of the numbers is " << sum << std::endl << std::endl;

  return 0;
}

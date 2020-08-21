/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

// Comments: single line
/*
  Comments: Multi-line

*/

/*
Importing libraries
  To include a library or file in your code, use #include at the top of the file
  Angle brackets (<...>) indicate that the library/file is a standard
    C++ library (and stored in Visual Studio's path somewhere)
  For example, to import the C++ iostream library, use
    #include <iostream>

  Quotations marks ("...") indicate that the file is something you
    created (and in the same directory as this current code)
  For example, to import a file you wrote called "coffee.cpp", use
    #include "coffee.cpp"

Useful libraries
  iosteam    -    input (keyboard) and output (console)
  string    -    creating, accessing, manipulating std::strings


Program structure
  The "int main()" function is where the program starts, which is equivalent to 
    "public static void main" in Java or "main()" in Python
    Python: note that you do NOT have to call main() yourself
  One difference is that the main function MUST return a value
    Hence at the end of every "main" you will return 0
      int main()
      {
        ...
        ...
        return 0;
      }

Basic syntax
  C++ is caSe-SeNiSiTiVe
  You can name variables/classes however you want to, but in these examples:
    - Variables and functions are named usingCamelCase
    - Classes are named with EveryWordCapitalized
  All statements (e.g. variable declarations, function calls, etc.)
    end with a semi-colon
  Blocks of code are denoted with curly braces { }
    Python: White space is ignored--curly braces are the only way to 
      enclose a block
Namespaces
  Objects that are part of the standard library are in the "std" namespace
    this is why we use std::string, std::cout, std::cin, etc.

Variables
  Variables must explicitly be given a type when declaredd
  For example,
    int a;
    float x = 9.8;
  Common variables primitives (i.e. simple variables, not objects)
    int    -    integers (see also long)
    double  -    floating point numbers (see also float)
    bool  -    booleans (either true or false)
    char  -    number that represents an ASCII character (letter)

  std::strings are objects (not primitives) and enclosed with "..."
    Java: note the lowercase 's'

Output
  To print to the console, use std::cout
    std::cout << "SOME std::string TO PRINT"
  Multiple statements can be chained together
    std::cout << "Hello" << " " << "World";
  Variables can be concatenated to the output also
    int num = 8;
    std::cout << "The value of variable num is " << num;

Input
  To read input from the keyboard, use std::cin
    int a;
    std::cin >> a;
  Multiple input can be chained together
    int a;
    double x;
    std::string message;
    std::cin >> a >> x >> message;
  Note how you do not need to specify the type of input you are reading
    and it works with primitives and std::strings
  std::cin will read until it encounters any white space 
  std::getline will read until there is a '\n' so use it to read in multiple words
      std::string sentence;
      std::getline(std::cin, sentence);
  Quirk (particularly for Python programmers): 
    Just like nextInt() in Java, std::cin >> ... reads the user input but leaves the
    '\n' on the input buffer (here the '\n' is the user hitting enter.
    This means that if a std::getline() follows a std::cin >> ..., 
      the std::getline() will see the leftover '\n' and not the new input.
    Thus, whenever you have std::cin >> ... followed by std::getline(), you need
      to remove the leftover '\n' using std::cin.ignore()
    For example
      int a;
      std::string sentence;
      std::cin >> a;
      std::cin.ignore();
      std::getline(std::cin, sentence);

If / else if / else
  Virtually the same as in Java / Python
  Python: Note that "elif" is replaced with "else if"

While
  Virtually the same as in Java / Python
  C++ also has also has a variation called "do while" 
    see http://www.cplusplus.com/doc/tutorial/control/

For loops
  Java: virtually the same
  Python: for loops operate very differently in C++
    see http://www.cplusplus.com/doc/tutorial/control/
  
*/
#include <iostream>    //needed for std::cout and std::cin
#include <string>    //needed for std::string objects

int main()
{
  // variable declarations
  int a = 8;
  double x;
  x = 3.14;
  std::string message = "Hello World!";
  bool gotMilk = true;

  // Output
  std::cout << "This will print to the console\n";
  std::cout << message << std::endl;
  std::cout << "The value of X is " << x << std::endl;
  std::cout << "---------------------------\n";

  // input
  std::cout << "Enter a integer: ";
  std::cin >> a;
  std::cout << a << std::endl;

  std::cout << "Enter a single word: ";
  std::cin >> message;
  std::cin.ignore(); // clear extra newline
  std::cout << message << std::endl;

  std::cout << "Enter multiple words: ";
  std::getline(std::cin, message);
  std::cout << message << std::endl;
  std::cout << "---------------------------\n";

  // If statements
  if (gotMilk == true)
  {
    std::cout << "You've got milk\n";
  }
  else if (gotMilk == false)
  {
    std::cout << "There is an absence of milk!\n";
  }
  else
  {
    std::cout << "This will never execute because boolean variables can only be T or F\n";
  }
  std::cout << "---------------------------\n";

  // while loops
  a = 7;
  while (a != 0)
  {
    std::cout << "This loop will continue until you enter 0." << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> a;
  }
  std::cout << "----------------------------\n";

    
  // for loops
  std::cout << "Enter a positive number to sum: ";
  std::cin >> a;
  int total = 0;
  for (int i = 0; i <= a; i++)
  {
    total += i;
  }
  std::cout << "The summation of " << a << " is " << total << std::endl;
  std::cout << "---------------------------\n";

  return 0;
}

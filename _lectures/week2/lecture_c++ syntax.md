---
marp: true
theme: itp
paginate: true

week: 2
category: lecture
title: C++ Syntax

---

<!-- headingDivider: 2 -->

# C++ Syntax Overview

## C++ and Other Languages

- C++ are **conceptually** similar to other languages
  - Loops, functions, variables, etc. are in both
- The biggest difference is the specific **syntax** is new
- There are a few other things to note that we will discuss as we go
  

## Example program

```c++
/* Awesome 
Argon Program
*/
#include "OLED_screen.h"	//library

const int MAX_PRESSES = 4;	//globcal constant
int numPresses = 0;			//global variable
bool areDone = false;

void loop() {
  if (numPresses >= MAX_PRESSES) {
      areDone = true;
  }
}
```
## Comments

- `//` are single line comments
- `/* ... */`are multiple line comments

```c++
/* Awesome 
Argon Program
*/
#include "OLED_screen.h"	//library
```
## Ending Lines

- Every executable line of code ends with a semi-colon `;`

```
int age = 4;
String animal = "cat";
```

- Code blocks (e.g. loops, functions, ifs) **do not** end with semi-colons

```c++
void loop() {
  if (numPresses >= MAX_PRESSES) {
      areDone = true;
  }
}
```
## Code Blocks

- Blocks of code are started and ended with `{ }`
- Whitespace is doesn't matter

```c++
void loop() {
  if (numPresses >= MAX_PRESSES) {
      areDone = true;
  }
}
```

```c++
void loop() {  if (numPresses >= MAX_PRESSES) {areDone = true;  }}
```

Both of the code blocks are correct and equivalent

## Variables

```c++
type variableName = value

int numPresses = 0;
```

- You must always specify the type of a variable when you declare it
- Ex: `int`, `double`, `String`, `bool`

## Constants

```c++
const type variableName = value;

const int MAX_PRESSES = 4;
```

- `const` means the variable is a constant and **cannot** change after you initialize it

## Aside: C++ Typing

- Python and JavaScript are called **weakly typed** languages: 
  - A variable can be hold a string, and then later hold an int

```python
age = "Jurassic"
age = "34"
```

- C++ is called **strongly typed** language: 
  - A variable must be declared as a type and **cannot**  change

```c++
String age = "Jurassic";
age = "34"		//Error!;
```

## Functions: Return Values

```c++
returnType functionName (parameterType parameterName, ...) { ...}
```

- Functions can may or may not return a value
- Always specify the return type before the function name

```c++
double thisFunctionReturnsADouble() { ... }
```

- `void` means the function **does not** return a value 

```c++
void setup() { ... }
```

## Functions: Input Parameters

```c++
returnType functionName (parameterType parameterName, ...) { ...}
```

- Functions can may or may not take an input parameters

```c++
double squareRoot(int num) {...}
int sumNumbers(int num1, int num2) {...}
void loop() {...}
```
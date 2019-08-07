---
marp: true
theme: itp
paginate: true

week: 2
category: lecture
title: Argon Program Structure
---

<!-- headingDivider: 2 -->

# Structure of a Microcontroller Program

## Important Note

- Your Argon folder name cannot contain any spaces at all
  - `C:\Users\Rob\ITP_348\Projects` is ok
  - `c:\Users\Rob Parke\ITP 348\Cool Projects` is not

## Key features

- Argon programs are written in C++ *(we will discuss C++ syntax in depth on Thurs)*
- Every Argon program has two functions *(you can create your own too)*
  - `setup()`
  - `loop()`
- In addition, most programs will also have
  - global variable declarations
  - library includes

## Example program

```c++
#include "OLED_screen.h"	//library

const int MAX_PRESSES = 4;	//globcal constant
int numPresses = 0;			//global variable

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

## Libraries

```c++
#include "OLED_screen.h"
```

- Similar to `import`
- Allows us to access additional code and functions
- We will use this to communicate with certain devices like LCD screens
- Notice the `#`

## Variable Declaration

```c++
const int MAX_PRESSES = 4;	//globcal constant
int numPresses = 0;			//global variable
```

- Typically, many of our variables will be global (declared outside a function in the global namespace)
- In C++, every variable must *explicitly* declare it's

## `setup()` Function

```c++
void setup() {
  // put your setup code here, to run once:
}
```

- The `setup()` function will ***only run once***
  - Runs after each powerup or reset the Argon
- Use it to initialize variables, pin modes, start using libraries, etc.

## `loop()` Function

```c++
void loop() {
  // put your main code here, to run repeatedly:
}
```

- After `setup()` is called once, the`loop()` function is called endlessly 
  - Basically an infinite loop
- Use it for the main functionality of your program

## `pinMode` 

Syntax

```c++
pinMode(PIN_NUMBER, MODE);
MODE: OUTPUT or INPUT
```

- Most pins on the Argon can be configured to SEND output (e.g. to turn on a light) or to RECEIVE input (e.g. a button press)
- When you want to use a pin in your program, you should specify its mode in `setup()`

## `digitalWrite` 

Syntax

```c++
digitalWrite(PIN_NUMBER, VALUE);
VALUE: HIGH or LOW
```

- You can send an ON (HIGH) or OFF (LOW) signal at output on a pin
- This is writing a **digital** value
  - Digital values are like boolean values: 0/1, on/off, true/false
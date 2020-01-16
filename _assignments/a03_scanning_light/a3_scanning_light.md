---
week_assigned: 3
number: 3
category: assignment
title: Scanning Light
date_due: TBD @ 11:59 pm
---

Assignment 3 – Scanning Light
=============================

*[Submit on Blackboard](https://blackboard.usc.edu)*


Goals
-----

-   Connect LEDs to Argon

-   Read analog input with a potentiometer

-   Control scanning LEDS with potentiometer

-   Use PWM to change LED intensity

**Overview**

This assignment is to create variable scanning / oscillating light pattern on 5
LEDs. The scanning rate will be controlled with a potentiometer. This pattern is
often seen in TV and films such as [KITT from Knight
Rider](https://www.youtube.com/watch?v=WxE2xWZNfOc) and the [Cylons from
Battlestar Galatica](https://youtu.be/-z-HQBfnwiA?t=5).

The light pattern will oscillate from right to left and back again. As the
potentiometer is turned, the lights will blink faster or slower. However, in
addition to the rate changing, the intensity will also change (more bright to
less bright.

Here is an example with 7 lights.

<img src="media/24cca9ef54a3cdbd348cf9e02bf651c9.png" alt="" style="width:400px" />

**Components**

-   Argon

-   Breadboard

-   5 x LEDs

-   5 x 330 Ohm resistors

-   1 x 10k Ohm potentiometer

-   Jumper wire (standard male-male)

**Requirements**

-   Connect five LEDs to Argon

-   Control potentiometer

-   Use the potentiometer to control both the oscillating rate *and* the
    brightness

    -   When the potentiometer is turned fully clockwise, the lights should be
        bright and fully on

-   When turned counter-clockwise, the lights should be very dim and blinking
    slowly

**Challenge**

-   Use a for loop to iterate through the LEDs (hint: this will require the use
    of an array, which is like a C++ list)

**Required naming convention** (replace \# with the current assignment number)

-   **Project Name**

    -   itp348_a\#_lastname_firstname

-   **Zip File** (include entire project folder)

    -   itp348_a\#_lastname_firstname.zip

Deliverables
------------

*[Submit on Blackboard](https://blackboard.usc.edu)*


1.  A compressed file containing your project. Follow the guidelines for full
    credit.

    *Here are the instructions for submission*

2.  Navigate to your project folder.

3.  Include the *entire* folder in a zip file

4.  Rename the zip file based on naming convention

5.  Upload zip file to Blackboard site for our course

6.  A photograph of your device connected to USB with the blue light on.

7.  A (very) short video demonstrating your project functioning

Grading
-------

| Item                              | Points |
|-----------------------------------|--------|
| 5 LEDs used                       | 5      |
| Potentiometer controls scan rate  | 10     |
| Potentiometer controls brightness | 10     |
|                                   |        |
| Total                             | 20     |


*Inspiration for project from* [Dr. Peter
Dalmaris](https://www.udemy.com/course/arduino-step-by-step-2017-getting-started-projects/)

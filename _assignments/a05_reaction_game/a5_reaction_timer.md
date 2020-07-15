---
week_assigned: 5
number: 5
category: assignments
title: Reaction Timer Game
date_due: Sep 22 @ 11:59 pm

---

Assignment 5 – Reaction Timer Game
==================================

*[Submit on Blackboard](https://blackboard.usc.edu)*


Goals
-----

-   Control RGB LEDs

-   Use push button for analog input

-   Process timed events

**Overview**

This assignment is to create a simple reaction timer game. Two players will each
have two buttons (“red” and “blue”). A RGB LED will flash white three times, and
then it will flash either red or blue. The player that presses their correct
button the faster will win that round. The cumulative score will be displayed on
the serial monitor.

The exact layout of this project is left unspecified so you can come up with
your own design and modifications

**Components**

-   Argon

-   Breadboard

-   1 x RGB LED (and any associated resistors)

-   4 x push button (and any associated resistors)

-   Jumper wire 

**Requirements**

-   General game setup

    -   Two players each control two push buttons

    -   Each button represents either “red” or “blue”

    -   Between the two rows of buttons is a RGB LED

-   Algorithm for each round

    -   RGB LED will flash white three times. Use a delay in between each flash
        with a random value

    -   RGB LED will then flash either red or blue (randomly chosen)

    -   Argon will wait for either player 1 or player 2 to press the correct
        button

    -   The first player to press the correct button scores 100 points;
        incorrect presses result in -100 point deduction

    -   After each round, the winner of the round is displayed on the serial
        monitor. The cumulative scores of both players are also displayed on the
        serial monitor.

    -   Press reset on the argon to reset the game

-   Create a Fritzing breadboard prototype layout of your design

-   Once you’re satisfied with the design, build the device and create firmware

**Required naming convention** (replace \# with the current assignment number)

-   **Project Name**

    -   itp348_a\#_lastname_firstname

-   **Zip File** (include entire project folder)

    -   itp348_a\#_lastname_firstname.zip

Deliverables
------------

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

| Item                  | Points |
|-----------------------|--------|
| Fritzing layout       | 5      |
| RGB LED configuration | 5      |
| Button configuration  | 5      |
| Game logic functional | 20     |
|                       |        |
| Total                 | 35     |

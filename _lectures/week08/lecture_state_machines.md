---
marp: true
theme: itp

week: 8
category: lectures
title: State Machines
---
<!-- headingDivider: 2 -->

# State Machines



## What's the point?

* Our devices should operate remotely without constant user intervention
* Our devices can receive many different sensor data (**input**), in different situations (**states**), resulting in different actions (**outputs**)
* Tracking and organizing all these possibilities can become very complicated
* **State machines** provide a way of thinking about and designing for the various situations that arise

## State Machine

* A state machine (or *finite state machine*) is mental **model** to help us make decisions
  * It is not strictly hardware or software code
* Examine
  * What has happened previously (**state**)
  * What is happening currently (**input**)

* Generate
  * Next **output**
  * Next **state**

## Example #1 Stoplight

<img src="lecture_finite_state_machines.assets/stoplight.jpg" alt="stoplight" style="height:300px;" />

## Example #1 Stoplight

* Consider stoplight with no pedestrians
* What states are there?
* How do we transition to new states?

## Example #1 Stoplight Diagram

## Example #1 Stoplight

| State            | Stoplight |
| ---------------- | --------- |
| Traffic Flows    | Green     |
| Traffic Stopping | Yellow    |
| Traffic Stopped  | Red       |

## Example #2 Sprinkles Cupcake ATM

<img src="lecture_finite_state_machines.assets/image-20200303153612762.png" alt="image-20200303153612762" style="width:800px;" />

<!-- draw state diagram
idle +start+ display 
display +select+ process
display -cancel- idle
display |selection empty| display 
process +credit card valid+ dispense
process |credit card valid| process
dispense |cupcake remains| dispense
dispense +cupcake taken| idle
-->

## Example #2 Sprinkles Cupcake ATM Diagram

## Example #2 Sprinkles Cupcake ATM

| State               | Input              | Next State          |
| ------------------- | ------------------ | ------------------- |
| Idle                | None               | Idle                |
| Idle                | Start button       | Display choices     |
| Display choices     | Choice available   | Process credit card |
| Display choices     | Choice unavailable | Display choices     |
| Display choices     | Cancel             | Idle                |
| Process credit card | Card valid         | Dispense cupcake    |
| Process credit card | Card invalid       | Process credit card |
| Dispense cupcake    | Cupcake taken      | Idle                |
| Dispense cupcake    | Cupcake remains    | Dispense cupcake    |

## In class Lab - Stoplight and Pedestrian Signal

<img src="lecture_finite_state_machines.assets/stoplight.jpg" alt="stoplight" style="height:300px;" /> <img src="lecture_finite_state_machines.assets/ped_signal.jpg" alt="ped_signal" style="width:200px;" />

## In class Lab - Stoplight and Pedestrian Signal

* We are going to build a stoplight / pedestrian crossing for a two way intersection
* Download starting code
  * Go to [https://bit.ly/ProjectZip](https://bit.ly/ProjectZip)
  * Paste the following link into the top right
    https://github.com/reparke/ITP348-Physical-Computing/tree/master/_exercises/week08/stop_light_start

## Wiring Diagram

<img src="lecture_finite_state_machines.assets/IMG_8948.jpg" alt="IMG_8948" style="height:500px;" />

## Wiring Diagram

| LED                   | Argon Pins |
| ---------------------------- | ---- |
| NorthSouth Red LED      | D2     |
| NorthSouth Yellow LED  | D3      |
| NorthSouth Green LED  | D4      |
| WestEast Red LED    |   A0   |
| WestEast Yellow LED  |     A1 |
| WestEast Green LED   | D5     |
| Walk White LED     |  D6    |
| Don't Walk Red LED   |  D7    |

## Lab Stages

1. North South stop light
2. Add Pedestrian Walk / Don't Walk light
3. Make Don't Walk light blink
4. Add West East stop light

## Approach

* We will need to create a way to represent the states using **enum**
* We will need to track state transitions with **variables** for state
* We will need to control timing with **millis()**

* What does `loop()` do
  * calculate new state
  * output traffic signal LEDs based on state
  * independently flash walk signal *(later)*

## Credits

* [Bill Siever](http://siever.info) - [CS132 FSM](http://siever.info/cse132/guides/intro-to-FSMs.html)  (Washington University at St. Louis) 
* [Bill Siever](http://siever.info) - [CS132 Delta Timing](http://siever.info/cse132/weeks/3/)  (Washington University at St. Louis) 
* [USC EE109 State Machines](http://bits.usc.edu/files/ee109/)
* Laurie Parke
* Photo by [Free To Use Sounds](https://unsplash.com/@freetousesoundscom?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText) on [Unsplash](https://unsplash.com/?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText)
* Photo by [NON](https://unsplash.com/@non_creation?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText) on [Unsplash](https://unsplash.com/?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText)
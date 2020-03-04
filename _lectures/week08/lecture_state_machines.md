---
marp: true
theme: itp

week: 8
category: lectures
title: State Machines
---

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

* tips
  * give students a wiring diagram (or fritzing)
  * give students a sample program that turns all lights on (or is a pattern) so they can test wiring before coding (`examples/light_test.ino`)
* suggestions
  * need to cover enum, switch, delta timing, fsm
  * give students wiring diagrams
  * give students starting code that has light test and base code for starting project
  * lecture: switch
  * lab: start with delta timing to blink lights in one direction
  * lecture: FSM and enum
  * lab: draw out different states for one direction + pedestrians
  * lab: students code state transition 
  * lab: students try to add second direction of traffic; make states diagram and code
* need to:
  * change solution code to use prevMillis
  * create wiring diagram
  * create basic slides on enum, switch, fsm, delta (this one might already be made)
* Role of `loop()`
  * calculate new state
  * output traffic signal LEDs based on state
  * independently flash walk signal *(later)*
* Stage 1: NS traffic light ==(do together with class)==
  * Lights transition from NSGreen, NSYellow, NSRed
  * States: NSG, NSY, NSR
  * Duration: 
    * NSG, NSR = GO_TIME (5000)
    * NSY = TRANSITION_TIME (1000)

| State            | NS Stoplight |
| ---------------- | ------------ |
| Traffic Flows    | Green        |
| Traffic Stopping | Yellow       |
| Traffic Stopped  | Red          |

* Stage 2: add pedestrians
  * Lights transition from NSGreen, NSYellow, Ped Walk, Ped Don't Walk
  * States: NSG, NSY, **PED, PEDDW**
    * NSR is replaced by two new states for pedestrians
  * Duration: 
    * NSG, NSR, **PED** = GO_TIME (5000)
    * NSY, **PEDDW** = TRANSITION_TIME (1000)

| State                | NS Stoplight | Pedestrian Light |
| -------------------- | ------------ | ---------------- |
| NS Traffic Flows     | Green        | Don’t walk       |
| NS Traffic Stopping  | Yellow       | Don’t walk       |
| Pedestrians Go       | Red          | Walk             |
| Pedestrians Stopping | Red          | Don’t walk       |

* Stage 3: add don't walk blinking
  * add another state timer for blink rate
  * Question: When should we blink?
    * DW light should blink in every state except PED
    * if we are after blink rate, then blink light

| State                | NS Stoplight | Pedestrian Light      |
| -------------------- | ------------ | --------------------- |
| NS Traffic Flows     | Green        | Don’t walk (flashing) |
| NS Traffic Stopping  | Yellow       | Don’t walk (flashing) |
| Pedestrians Go       | Red          | Walk                  |
| Pedestrians Stopping | Red          | Don’t walk (flashing) |

* Stage 4: add WE light
  * Lights transition from NSGreen, NSYellow, **WEGreen, WEYellow**, Ped Walk, Ped Don't Walk
  * States: NSG, NSY, **WEG, WEY**, PED, PEDDW**
    * NSR is replaced by two new states for pedestrians
  * Duration: 
    * NSG, NSR, **WEG**, PED = GO_TIME (5000)
    * NSY, **WEY,** PEDDW = TRANSITION_TIME (1000)

| State                | NS Stoplight | WE Stoplight | Pedestrian Light      |
| -------------------- | ------------ | ------------ | --------------------- |
| NS Traffic Flows     | Green        | Red          | Don’t walk (flashing) |
| NS Traffic Stopping  | Yellow       | Red          | Don’t walk (flashing) |
| WE Traffic Flow      | Red          | Green        | Don’t walk (flashing) |
| WE Traffic Stopping  | Red          | Yellow       | Don’t walk (flashing) |
| Pedestrians Go       | Red          | Red          | Walk                  |
| Pedestrians Stopping | Red          | Red          | Don’t walk (flashing) |



<img src="lecture_finite_state_machines.assets/ped_signal.jpg" alt="ped_signal" style="width:200px;" />



## Credits

* [Bill Siever](http://siever.info) - [CS132 FSM](http://siever.info/cse132/guides/intro-to-FSMs.html)  (Washington University at St. Louis) 
* [Bill Siever](http://siever.info) - [CS132 Delta Timing](http://siever.info/cse132/weeks/3/)  (Washington University at St. Louis) 
* [USC EE109 State Machines](http://bits.usc.edu/files/ee109/)
* Laurie Parke
* Photo by [Free To Use Sounds](https://unsplash.com/@freetousesoundscom?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText) on [Unsplash](https://unsplash.com/?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText)
* Photo by [NON](https://unsplash.com/@non_creation?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText) on [Unsplash](https://unsplash.com/?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText)
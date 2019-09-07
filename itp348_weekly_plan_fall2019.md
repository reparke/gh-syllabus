#### General Feedback

* Assignment 0 is given out week 1, day 1; due week 2, day 2; that is the pattern
* change A1 blink so that it gives out code to make D7 blink, or change the name of the assignment to something like **initial project**
* Develop a way to post readings on website
* Try to integrate lectures, readings, assignments all on one webpage under "weeks"
* Add to Assignment 0 how to install fritzing parts for Argon (from Rob github)

0. #### Pre-semester

   - [x] Send students installation instructions
   - [ ] Create Google slides presentations; ask students to create one intro slide
   - [x] purchase:
     - [x] small envelopes
     - [x] coin batteries
     - [x] paper circuits classroom kit
     - [x] construction paper
     - [x] conductive tape
     - [x] colored straws

1. #### Introduction

   - Reading
     - Enabling the Internet of Things https://web.eecs.umich.edu/~prabal/teaching/resources/eecs582/want15iot.pdf
- Day 1 
  - Lecture
    - Course introduction / syllabus
    - Student intro slides 
    - Ice breaker
    - Introduction to IoT
    - Possibly show this [mind map](https://www.mindmeister.com/1308604904?t=O0Vcty0Uys) from Boris Tomas
  - Lab
    - none
- Day 2
  
  - Lecture
  
    - Pass out argons
       - students are responsible for returning devices if they drop before drop deadline
       - Have students sign
    - Kit Overview
    - Software tools
       - Workbench (open and discuss)
       - Fritzing (open and show example project)
    - Safety
    - ==*Explain with slides what particle does, cloud, flash, etc. -- skip and do later==
   - Lab
     
     - Paper circuits
     - Then ask student to complete a creative expression with multiple LEDs
  - Assignment
    - A0 - Software and tool installation
  - ==Feedback==
    - update A1 to include code to make D7 blink (not available default)
    - Day 2 "making project" was fun; ping pong balls and glue guns were a hit
  

2. #### Electricity, Microcontrollers, LEDs
   
   - Reading
     - http://www.tigoe.com/pcomp/code/circuits/understanding-electricity/
     - https://learn.sparkfun.com/tutorials/voltage-current-resistance-and-ohms-law/all
   - Day 1
     - Lecture (fall 2019)
       - ==I walked through claiming a device== 
     - Lecture
       * C++ Syntax
       * Argon Microcontroller
     - Lab
       * Have students work in pairs to answer datasheet questions
     - Lecture
       - Electricity and Ohm's Law
     - Lab
       - Walk students through connecting LED + Resistor to VUSB on Argon
         - Ask students how they would connect more than 1 LEDs
         - Ask students how they would make LEDs blink
       - ==Feedback==
         - Fall 2019: 80% of students had seen C++ already (skipped over c++ slides quickly)
         - Practically all students were familiar with electricity principles, units (kilo, milli) so the electricity presentation very simple
   - Day 2
     - Lecture: Open Workbench
       * IDE like PyCharm
       * Create project
       * explain folder structure
       * Walk through command palette
       * Login, Target project
     - Lecture
       * Argon program structure
       * ==fall 2019 only== show students how to download and install fritzing parts
     - Lab
       * Let students try to complete blinking of three LEDs
       * Build three LEDs; 
       * show in Fritzing (students observe)
       * show formal coding with variables (students code together)
     - Lecture
       - LEDs
     - Lab
       - Compare 10k ohm vs 330 ohm resistor
     - Lecture
       - Look at LED datasheet; calculate ideal resistance for LED
   - Assignment
     - A1 - Blink
   
3. #### ADC, Potentiometers, Serial Monitor

   - Reading
     - https://learn.sparkfun.com/tutorials/analog-vs-digital/all
     - https://learn.sparkfun.com/tutorials/pulse-width-modulation/all
     - https://www.youtube.com/watch?v=GQLED3gmONg
   - Day 1
     - Lecture
       - Serial monitor: display info for debugging; only available when USB connected (not via cloud)
     - Guided activity
       - Let them work for a few minutes first
       - Ask them to digitalRead() on D2; use serial monitor to read with no connection (will be floating); then directly connect to **3.3v**, then GND
     - Lecture
       - Analog vs. digital
       - Pulse width modulation, PWM pins, analogWrite 
     - Lab
       - Make light fully bright for 2 sec, half as bright for 2 sec, 1/3 as bright for 2 sec, 
       - Challenge: Increase light level of LED automatically
     - Lecture
       - C++ for loops
     - Lab
       - Have students use for loop to sweep the brightness of an LED
   - Day 2
     - Lecture
       
       - Potentiometer, voltage dividers
       
     - Lab
     
       - Have students connect pot to 3.3v, gnd, and A0; display the values
       
     - Lecture
     
       - Analog to digital conversion; explain the math / conversion between voltage and input values
     
     - Lab
     
       - Use potentiometer to control light level
     
   - Assignment
     
     - A2 - Light Scupture 
   
4. #### Buttons, RGB LEDs *(one class cancelled for Tapia)*

   - ​	Reading
     
     - https://learn.sparkfun.com/tutorials/pull-up-resistors
     
   - Day 1
     - Activity
       - Video chat with Cyane's class (1 hour)
     - Guided activity
       - connect button with pullup
       - Ask what is the voltage at pin when button pressed and not pressed
     - Lecture
       - Digital Input
       - Push buttons: component, schematic, pull-up resistors
     - Guided activity
       - Connect button with resistor
       - Latching button and debouncing
     - Lab (students work on)
       - Turn LED on while button pressed
       - Turn LED off after button pressed
       - Connect 3 LEDs and control on/off with button presses (3 states)
     
   - Day 2 - Class cancelled (==Future semesters this could be RGB LEDs, debouncing, or catch-up==)
     - Assignment
       - A3 - Cylon light 
     
   
5. #### Week 5
   
   - Reading
     - 
   - Day 1
     - Lecture
       - RGB LED lecture
     - Lab
       - Display random color
     - Lecture
       - Functions in C++ *(this should be review from week 2)*
     - Lab
       - Rewrite sketch using `displayColor(r, g, b)` and `displayRandomColor()`
     - Lecture
       - Libraries
     - Lab
       - Have students find and install `rgb-controls`
       - Ask them to create some colors effects on their own
       - Then walk through example together
       - If time, introduce a button to control states (idea of a state machine)
   - Day 2
     - Lecture
       - Using multimeter (==need to create==: how read DC voltage, resistance, current; have some random resistors and ask them to figure out, hook up potentiometer to measure resistance and current)
       - Reading resistors (completed))
       - TMP 36 (==need to create==)
       - Maybe start voltage dividers and photocell (==need to create==)
     - Lab
       - 
     - Lecture
       - 
     - Lab
       - 
   - Assignment
     - A4 - Electronic dice 
   
   
   
   
   
   
   - ==not sure where this goes yet==
   
   
   - Lecture
   
     - How to read resistors
   
   - Guided activity
   
     - Measure voltage at pin when potentiometer is turned (remove from circuit
     - Measure resistance
   
   - Lecture
   
     - RGB LEDs: common anode vs cathode, R+G+B != W
   
   - Lab
   
     - Display random color with analogWrite
   
   - Guided activity
   
     - Create function that take inputs to set the color
   
       ```c++
        void setColor(int r, int g, int b)
       ```
   
     - discuss how to enter hexcode 0xFF (==not sure what I meant by this==)
   
     - Try library for animation http://yaab-arduino.blogspot.com/p/ala-example-simplergbled.html



---



0. #### Week 3

   - Reading
     - 
   - Day 1
     - Lecture
       - 
     - Lab
       - 
     - Lecture
       - 
     - Lab
       - 
   - Day 2
     - Lecture
       - 
     - Lab
       - 
     - Lecture
       - 
     - Lab
       - 
   - Assignment
     - AX - 

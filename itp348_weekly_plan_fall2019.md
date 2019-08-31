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
    - A1 - Blink
  

2. #### Electricity, Microcontrollers, LEDs
   
   - Reading
     - http://www.tigoe.com/pcomp/code/circuits/understanding-electricity/
     - https://learn.sparkfun.com/tutorials/voltage-current-resistance-and-ohms-law/all
   - Day 1
     - Lecture
       - Electricity and Ohm's Law
     - Lab
       - Walk students through connecting LED + Resistor to VUSB on Argon
         - Ask students how they would connect more than 1 LEDs
         - Ask students how they would make LEDs blink
       - Open Workbench
         - IDE like PyCharm
         - Create project
         - explain folder structure
         - Walk through command palette
         - Login, Target project
     - Lecture
       - Argon program structure
     - Lab
       - Let students try to complete blinking of three LEDs
   - Day 2
     - Lecture
       - C++ Syntax
       - Argon Microcontroller
     - Lab
       - Have students work in pairs to answer datasheet questions
       - Build three LEDs; 
         - show in Fritzing (students observe)
         - show formal coding with variables (students code together)
     - Lecture
       - LEDs
     - Lab
       - Compare 10k ohm vs 330 ohm resistor
     - Lecture
       - Look at LED datasheet; calculate ideal resistance for LED
   - Assignment
     - A2 - Light Sculpture
   
3. #### ADC, Potentiometers, Serial Monitor

   - Reading
     - https://learn.sparkfun.com/tutorials/analog-vs-digital/all
     - https://learn.sparkfun.com/tutorials/pulse-width-modulation/all
     - https://www.youtube.com/watch?v=GQLED3gmONg
   - Day 1
     - Lecture
       - Serial monitor: display info for debugging; only available when USB connected (not via cloud)
     - Guided activity
       - digitalRead() on D2; use serial monitor to display floating value; then directly connect to **3.3v**, then GND
     - Lecture
       - Analog vs. digital
       - Pulse width modulation, PWM pins, analogWrite 
       - ==draw an "equivalent voltage" line on the duty cycle image e.g. 1.67v is 50%==
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
     
     - A3 - Cylon light 
   
4. #### Buttons, RGB LEDs *(one class cancelled for Tapia)*

   - ​	Reading
     
     - https://learn.sparkfun.com/tutorials/pull-up-resistors
     
   - Day 1
     - Activity
       - Video chat with Cyane's class
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
       - A4 - Electronic dice 
     
   
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
       - 
     - Lab
       - 
     - Lecture
       - 
     - Lab
       - 
   - Assignment
     - AX - 
   
   
   
   
   
   
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

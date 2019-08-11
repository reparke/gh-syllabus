0. #### Pre-semester

   - [ ] Send students installation instructions
   - [ ] Create Google slides presentations; ask students to create one intro slide
   - [ ] purchase:
     - [ ] small envelopes
     - [ ] coin batteries
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
   
3. #### Buttons, ADC, Potentiometers, Serial Monitor

   - Reading
     - https://learn.sparkfun.com/tutorials/analog-vs-digital/all
   - Day 1
     - Lecture
       - Analog vs. Digital, digitalRead, pinMode ==should this be moved from week 2?==
       - Serial monitor: display info for debugging; only available when USB connected (not via cloud)
     - Guided activity
       - digitalRead() on D2; use serial monitor to display floating value; then directly connect to **3.3v**, then GND
     - Lecture
       - Push buttons: component, schematic, datasheet?
     - Guided activity
       - Connect button with resistor
       - Latching button and debouncing
     - Lecture
       - Pullup and pulldown resistors
     - Lab (students work on)
       - Turn LED on while button pressed
       - Turn LED off after button pressed
       - Connect 3 LEDs and control on/off with button presses (3 states)
   - Day 2
     - Guided activity
       - connect button with pullup
       - Ask what is the voltage at pin when button pressed and not pressed
     - Lecture
       - Digital multimeter
       - How to read resistors
     - Guided activity
       - Measure voltage at pin when button pressed
       - Measure resistance
     - Lecture
       - Pulse width modulation, PWM pins, analogWrite, DAC
       - ==voltage dividers?==
     - Lab
       - Increase light level of LED automatically
     - Lecture
       - C++ for loops (==find an animation online==)
       - Potentiometer: explain the math / conversion between voltage and input values
     - Lab
       - Use potentiometer to control light level
   - Assignment
     - A3 - Cylon light 
4. #### RGB LEDs *(one class cancelled for Tapia)*

   - Reading
     
     - 
   - Day 1
     - Activity
       - Video chat with Cyane's class
       - Discuss Pecha Kucha
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
   - Day 2 - Class cancelled
     - Assignment
       - A4 - Electronic dice 



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

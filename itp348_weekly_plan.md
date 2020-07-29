---
layout: single
classes: wide
title: Weekly Plan
toc: false
toc_label: "Quick Links"
toc_icon: "bookmark"  # corresponding Font Awesome icon name (without fa prefix)
toc_sticky: true

---
## 		Things to implement

* Create "behavioral norms"
* wk1: record c++ review and create bb quiz
* wk0: record introduction for students
* wk1: record software tools for reference
* general: try to incorporate `enum` or `switch` earlier in semester
* idea: involve students in a couple weeks where we "flip" the classroom
* a8 (alarm): revise to use state machines

## General Feedback (Fall 2019)

* Assignment 0 and 1 are given out week 1, day 1; due week 2, day 1; that is the pattern
* Develop a way to post readings on website
* Try to integrate lectures, readings, assignments all on one webpage under "weeks"
* students like being show a small bit of using a sensor, and then extending it on their own
* students like hands-on

  

## Pre-semester

- [ ] Send students installation instructions / video
- [x] purchase items (see Evernote pre-semester tasks)

- Reading
  - Enabling the Internet of Things https://web.eecs.umich.edu/~prabal/teaching/resources/eecs582/want15iot.pdf

## 1. Intro, Microcontrollers, LEDs

### Reading / Video

* http://www.tigoe.com/pcomp/code/circuits/understanding-electricity/
* https://learn.sparkfun.com/tutorials/voltage-current-resistance-and-ohms-law/all
* Video discussion of C++ review (make little videos for functions); curate or record
* Have short blackboard quiz

### Day 1

#### Lecture

- Course introduction / syllabus
- Ice breaker *(see slides in local ITP 348 Docs folder)* 
- Introduction to IoT
- Possibly show this [mind map](https://www.mindmeister.com/1308604904?t=O0Vcty0Uys) from Boris Tomas
- Safety

#### Lab

- Paper circuits
- Time permitting
  - (on ground) ask student to complete a creative expression with multiple LEDs
  - (online) have student connect Argon to USB and connect an LED to 3.3v
  - Walk students through connecting LED + Resistor to VUSB on Argon
    - Ask students how they would connect more than 1 LEDs
    - Ask students how they would make LEDs blink
  - just ask the question: Compare 10k ohm vs 330 ohm resistor

### Day 2

#### Lecture

- Pass out argons 
   - students are responsible for returning devices if they drop before drop deadline
   - If online, students will already have these
- Kit Overview
- Software tools
   - Workbench (open and discuss)
   - Fritzing (open and show example project)

#### Lecture

* C++ Syntax (skip)
* Argon Microcontroller

#### Lab

* Have students work in pairs to answer datasheet questions from Argon Microcontroller slide

#### Lecture

- Electricity and Ohm's Law
- Argon program structure
- LED and Digital output

#### Lab

- turn on LED

#### Lecture (if time)

- Look at LED datasheet; calculate ideal resistance for LED

#### Feedback

- Most students were familiar with electricity principles, units (kilo, milli) so the electricity presentation very simple
- Didn't get to finish Electricity lecture or get to lab; should have gone faster

#### Feedback

- Day 2 "making project" was fun; ping pong balls and glue guns were a hit

### Assignment

- Due start of current week: none
- Given out start of current week: A0 - Software and tool installation; A1 - Blink

## 2. Pulse Width Modulation, ADC

### Reading

- Video: Software tools
  - Lecture: Open Workbench
    * IDE like PyCharm
    * Create project
    * explain folder structure
    * Walk through command palette
    * Login, Target project
  - Show students how to download and install fritzing parts

### Day 1

#### Notes

- TA and I spent some time class helping install
- Demonstrate how to reset device and go to safe mode

#### Lecture

- Analog vs. digital
- Pulse width modulation, PWM pins, analogWrite 

#### Lab

- Make light fully bright for 2 sec, half as bright for 2 sec, 1/3 as bright for 2 sec, 
- Challenge: Increase light level of LED automatically

#### Lab

- Have students use for loop to sweep the brightness of an LED

#### Lecture

* C++ `for` loops

#### Feedback

- ==Need to add additional exercises==

### Day 2

#### Lecture

- Serial monitor

- Guided activity
- Do simple example where there is a global variable that gets incremented and display its value with Serial monitor

#### Lecture

- Potentiometer, voltage dividers

#### Lab

- Have students connect pot to 3.3v, gnd, and A0; display the values on serial monitor

#### Lecture

- Analog to digital conversion; explain the math / conversion between voltage and input values

#### Lab

- Use potentiometer to control light level

#### Lecture

- Using multimeter (if time)

#### Lab

- Have students measure resistance of pot when its out of a circuit

- Show fritzing drawing, and have them measure voltage

#### Feedback

- 

#### Assignment

- Due start of current week: A0 and A1 - Blink
- Given out start of current week: A2 - Light Sculpture (have students bring to class; ==bring camera==) 

## 3. Buttons, Digital Input, RGB

### Reading

- https://learn.sparkfun.com/tutorials/pull-up-resistors
- https://learn.sparkfun.com/tutorials/how-to-use-a-multimeter/all

### Day 1

- ==Have students present light sculpture== Start class with presentations

#### Guided activity

- Ask them to **digitalRead()** on D2; use serial monitor to read with no connection (will be floating); then directly connect to **3.3v**, then GND
- connect button with pullup
- Ask what is the voltage at pin when button pressed and not pressed

#### Lecture

- Using multimeter

#### Lab

- Have students measure resistance of pot when its out of a circuit
- Show fritzing drawing, and have them measure voltage

#### Lecture

- Digital Input
- Push buttons: component, schematic, pull-up resistors

#### Guided activity

* Fritzing explain
* Create button with resistors in Fritzing

#### Guided activity

- Connect button with resistor on Argon

#### Lab (students work on)

- Turn LED on while button pressed
- Turn LED off after button pressed
- Connect two LEDs

#### Guided activity

- Latching button (if time) ==identify way to program this==
- Connect 3 LEDs and control on/off with button presses (3 states)

#### Lecture

- Latching button (==need to make slides==؟)
- If no slides, draw picture of square wave

#### Lecture (==if time==)

- Reading resistors (lab exercise is built into slides)

#### Feedback

- 

### Day 2

#### Lecture

- Switch
  * connect middle pin to argon
  * connect outer pins to power and ground
  * when moving the switch, it connects either left two, or right two pins

#### Guided activity

* Connect switch middle pin to digital input pin, outer pin to power and ground
* use serial monitor to display switch value

#### Lecture

- RGB LED lecture

#### Lab

- Display random color

#### Lecture

- Functions in C++ *(this should be review from week 2)*

#### Lab

- Button press trigger random color
- Rewrite sketch using `displayColor(r, g, b)` and `displayRandomColor()`
- cycle button presses to display C (BG) M (RB) Y (RG)

#### Lecture

- Libraries

#### Lab

- Have students find and install `rgb-controls`
- Ask them to create some colors effects on their own
- Then walk through example together
- If time, introduce a button to control states (idea of a state machine)


#### Feedback

### Assignment

- Due start of current week: A2 - Light Sculpture 
- Given out start of current week: A3 - Cylon light 

### Feedback 

- 

## 4. Multitasking, photoresistors

### Reading

* [Kirchoff's Voltage Law](https://www.khanacademy.org/science/ap-physics-1/ap-circuits-topic/kirchhoffs-loop-rule-ap/v/ee-kirchhoffs-voltage-law)

### Day 1

#### Lecture

- Show students wiring picture (two buttons and an LED); give them 5 minutes to connect
- Multitasking with millis

#### Lab

- Review latching code from previous class; code together LED1 toggling with button
- Then add LED2 blink have light blink to show delay is block so millis is needed
- Rewrite with blink LED2 and toggle LED1 using millis
- Then rewrite to remove toggle but have LEDs blink at different rates

### Day 2 

#### Interactive breakout

* Photoresistor (work in groups)

#### Lecture

* Photoresistor

#### Lab

* Calibrate photoresistor

#### Lecture (skip)

- (if time) show derivation of mathematically deriving exact resistor to calibrate. Explain this is an important part of engineering

#### Lecture

- Particle Cloud variables

#### Lab

- publish photoresistor value and "state" (for example bright, ambient, or dark to Particle cloud)

### Assignment

- Due start of current week: A3 - Cylon light 
- Given out start of current week: A4 - Electronic dice

## 5. TMP36, Cloud Function, OLED

### Day 1

#### Lecture

- TMP36

#### Lab (in slides)

* Connect a TMP36 and output the current temperature to the serial monitor
* Consider what type of input is this signal? How will this value be read by Argon

#### Lecture

- Particle Cloud functions

#### Lab

- Connect RGB LED and have students remotely control it

#### Lecture

* Consider covering `switch` to handle cloud function calls

### Day 2

#### Lecture

- Libraries
- Discuss OLED

#### Lab

- Have students connect OLED to display "Hello World"

#### Guided Activity

- Walk students through wiring

#### Lab

- Have students create an Etch-A-Sketch with OLED

### Assignment

- Due start of current week: A4 - Electronic dice 
- Given out start of current week: A5 - Reaction Timer
- Alternate ideas: use TMP36 to measure temperature and display colors on RGB LED. Use potentiometer to control brightness of RGB LED. Display results on serial monitor. **Optional** use button for diagnostic or to change cel/fahr 

## 6. Particle Cloud Publish and Subscribe; IFTTT

### Reading

- Have students create an [IFTTT account](https://ifttt.com/) 

### Day 1

#### Lecture

- Magnetic switch
- Particle Cloud: Publish

#### Lab

- Wire switch and RGB LED
- Publish variable state (door open or closed)
- Publish switch event in console (this won't take very long)

#### Lecture

* Particle Cloud: Subscribe

#### Lab

* Create function to change LED colors: white switch is closed, red switch is open
* subscribe to variable -- work in pairs 
  - create unique event ITP348/Door/<<UNIQUE_NAME>>

#### Lecture

* ==may need more here==

### Day 2

#### Lecture

- IFTTT

#### Guided activity

- set up IFTTT [https://ifttt.com/create](https://ifttt.com/create)
- Install iOS / Android app
- how do create an alarm?
  - If Particle - Publish <event name> open
  - Then send notification
  - Could enhance by using your location
  - set up location trigger to enter or exit that sets a variable
  - then change publish event
- **Ask students to work in pairs and come up with a cool idea**

#### Lecture

* ==may need more here==
* Also could work on reaction timer because it is challenging
* Could cover [IFTTT webhooks](https://ifttt.com/maker_webhooks) but they require HTML / JS editing to work, and they require JSON to send text values

#### Feedback

- Some of the IFTTT got a little bumpy but generally this was a good amount of material and worked well

#### Assignment

- Due start of current week: A5 - Reaction Timer
  - Warn students that it was time consuming
  - **==IDEA==** make reaction timer a state machine assignment and move forward (replace other assignment)
- Given out start of current week:  A6 - Preliminary Proposal Ideas
  - This seems early for this, but the semester is shortened by 2 weeks
  - Could consider moving this later in a future semester

## 7. Finite State Machines

### Reading

- ==Send wiring diagram out ahead of time==

### Day 1

#### Lecture

- `switch ` statement
- `enum`

#### Guided Activity

- *To save time, this exercise is just an illustration of coding with `switch` and `enum`*
- Create new project without any hardware
- Walk students through creating an `enum` for favorite food
- Create a global variable to store current food
- Create a `switch` statement to use Serial monitor to display main ingredients in each dish

#### Lecture

- Finite state machines

#### Lab

- Starting with sample code
- walk through NS light state transitions (length, state)
- use delay() (not `millis`)

### Feedback

- next day cover `millis`, then rest of light blinking
- some students enjoyed the complexity of all parts, other seemed bored

### Day 2

#### Lecture

- Continued with FSM

#### Lab

- Continued with stoplight example

#### Lecture (if time)

* Speaker
* Tone
* Pitches

### Feedback

- 

### Assignment

- Due start of current week:   A6 - Preliminary Proposal Ideas
- Given out start of current week: A7 - Shared environment monitor



## 8. Motors, Servos, Bluetooth

### Before class

- Send wiring guide with full fan circuit 
- ask students to have a narrow bottle of water and some tape
- Have students install Bluetooth phone apps
     - [Adafruit Bluefruit](https://learn.adafruit.com/bluefruit-le-connect)
   - [Nordic Semiconductor nRF Toolbox](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Toolbox)

### Reading

- Motors
  - [https://www.electronicproducts.com/Electromechanical_Components/Motors_and_Controllers/Motor_control_design_an_introduction_to_motors_and_controllers.aspx](https://www.electronicproducts.com/Electromechanical_Components/Motors_and_Controllers/Motor_control_design_an_introduction_to_motors_and_controllers.aspx)
- Bluetooth
  * [https://learn.sparkfun.com/tutorials/bluetooth-basics/all](https://learn.sparkfun.com/tutorials/bluetooth-basics/all)
  * [https://learn.adafruit.com/introduction-to-bluetooth-low-energy/](https://learn.adafruit.com/introduction-to-bluetooth-low-energy/)

### Day 1

#### Lecture

- DC Motors

#### Lab

- Students copy sketch to make fan blade rotate direction
- Do experimental exercise to determine min / max PWM values

#### Lecture

- Servo motors

#### Lab

- Connect servo to DC motor
- control fan speed and direction with a potentiometers (do one version where it controls rotation of servo, then one where it controls motor speed)

#### Feedback

- students followed remotely and enjoyed building the fan
- I skipped the separate servo part and went directly to using the servo to control the fan
- Next year, start with DC fan, then immediately wire servo to spin, then pot
- ==Need to change the DC motor slides. They are too technical==
- ==**Idea for next semester**==: create assignment using motors and bluetooth (something like the fan)

### Day 2

 ==**Give students velcro and have them assemble chassis before Thurs**==
#### Lecture

- Bluetooth
- Argon BLE syntax
- Show Bluefruit app (skip nRF Toolbox)

#### Lab - ble_uart_control_start

- Distribute github link to download (post on slides)
- Describe project goals
- Explain **argon_ble_setup.h** at a high level
  - Have students change **DEVICE_NAME**
- Pull up Bluefruit [documentation](https://learn.adafruit.com/bluefruit-le-connect/controller) and explain button signal
- Code together blinking D7 when **press 1**
- Have students code on their own D7 on with **press up** and D7 off when **release up**
- (If time) have students code play tone when **press right **
- Have students try using color picker to change RGB colors

#### Lab - ble_uart_control_start

- Have students try to control servo and fan motor on their own

#### Example - ble_uart_rgb_accel_example

<!--skip for time -->

- Distribute github link to download (post on slides)
- Describe project goals
- explain **onDataReceived()**
- explain **updateRGBvalues()**
- explain **changeRgbLight()**
- Demo device with code

### Feedback

### Assignment

* Due start of current week: A7 - Shared environment monitor
* Given out start of current week: A8 - Alarm clock



## 9. Ultrasonic Distance Sensor; OLED Graphics; Cloud Dashboards

### Reading

- 

### Day 1

#### Lecture

- project overview
- Ultrasonic distance sensor 
- OLED graphics

#### Lab

- Student design range finding with ultrasonic sensor. Provide starting project (same one that uses OLED later)

### Feedback Day 1

- Went generally well. Ran out of time to talk about graphics.

### Day 2

#### Lecture

- OLED graphics (if necessary)
- API and JSON overview
- Show students a few public APIs
- Dashboard and Initial State integration (single values)

#### Guided Activity

* Create InitialState account

* Create webhook in Particle

- Send photoresistor value`Particle.publish` to InitialState

#### Lecture

- InitialState integration (multiple values)

#### Lab

* Continue from before

- Send photoresistor value and light level threshold`Particle.publish` to InitialState

## Feedback

- Pre-class concern: we will be interleaving car

## Assignment

- Due start of current week: A8 - Alarm clock
- Given out start of current week: A9 - Bluetooth car part 1

## 10. APIs; Weather; Car; Battery 

### Reading

- Create [Weather Stack account](https://weatherstack.com/)

### Day 1 

#### Lecture / Lab

- Finish InitialState Integration (if necessary)

#### Lecture

- JSON Parsing
- Discuss [weather stack](https://weatherstack.com/) show example call
- Walkthrough integration
- Write json code together

#### Lab

- Create [weather stack](https://weatherstack.com/) account (hopefully they have already done this)
- Have them use their own API key to view JSON in a browser (use formatter online if necessary
- Create webhook in Particle
- Copy code from particle publishing and subscribing
- Test: publish request and see if subscribe code retrieves JSON data

- Show students an example of how the code works for JSON parser

- Have students show description, temp, location, rainfall

#### Idea

- find another API to show

### Day 2

#### Lecture / Lab

* Finish Weather Stack

#### Lecture 

* LIPO battery

#### Lecture

* car bluetooth - gave overview of coding -- no specifics but pseudocode design for carForward, leftMotor, etc. (students will build this for their)

### Assignment

- Due start of current: ==A9 - Bluetooth car== part 1
- Given out start of current week: ==A9 - Bluetooth car== part 2 **and** Proposal

## 11.

### Reading

- 

### Day 1 -- ==**Google Guest Lecture on Accessibility**==

#### Lecture

#### Guest Lecture

#### Lab

- After guest lecture, we all met in a circle and discuss project proposals and gave feedback

### Day 2

#### Lecture 

* Debouncing

#### Lab

- create State enum and state transistions
- set up debouncing

#### Lecture

* heart rate rate sensor
  * what is it
  * How does it work
  * how to program it

### Assignment

- project

## 12.

### Reading

- 

### Day 1

#### Lecture

* Review debouncing
* Review heart rate sensor

#### Lab

* Program heart screen

#### Lecture

* Time

#### Lab

* how to work with the clock

#### Lecture

* Connect to weather

### Day 2

#### Activity

- Check milestone (postponed to next week)

#### Lecture

- Discuss DHT 22
- accelerometer

#### Lab

- Use **tap** feature
- Use **portrait / landscape** detection
- Use accelerometer to control RGB LED

### Assignment

- AX - 

## 13. 

### Reading

- 

### Day 1

#### Activity

- Check milestone 

#### Lecture

- PIR sensor

#### Lab

- Do basic wiring together
- ask students to enable longer delay-to-off time

#### Lecture

- accelerometer

#### Lab

- Copy example code for display graphs
- Use **tap** feature
- Use **portrait / landscape** detection
- Use accelerometer to control RGB LED (if time)

### Day 2

#### Lecture

- Work on project 

### Assignment

- AX - 

## 14 - Final Project Presentation

   

[Two-Layer Chassis Assembly](https://youtu.be/L7-98Ejmb4M)

[Pictures of installation](https://learn.sparkfun.com/tutorials/assembly-guide-for-sparkfun-jetbot-ai-kit/1-circular-robotics-chassis-kit-two-layer-assembly) (only relevant through half of the first page)



---

# **Use when extra time**

## Week 5 - Photoresistor

#### Experiential Learning

- Photoresistor part 1
- Discuss
- Photoresistor part 2
- Discuss
- Photoresistor part 3
- Discuss and show code

#### Feedback

- some students enjoyed the exploration; others seemed a little lost
- change some things on the handout that were worded poorly
- create some short, simple photoresistor wiring notes
- One good thing was this followed learning about using the multimeter since the activity required it

## Week 8 - Soldering

### Day 1

#### Lab

* Soldering demo in EE lab
* had students build sparkfun flashlight
* Then Neftali did a quick demo of how to lay out a simple PCB in Fritzing

### Feedback

* Took about 1 hour
* soldering was fun but really simple. It would be cool to have a second, more complex circuit

## Losant part 1

### Day 2

#### Lecture

- Losant

#### Lab (together)

- Create application
- Create devices
- Create integrations
- Create workflows

## Losant part 2 + Rate

### Day 1

#### Activity

- Race competition

#### Lecture

- Losant

#### Lab

- Review workflow (make sure everyone is getting data in device by going to overview)
- Create dashboard
- Create web application

### Feedback

- make sure to set up voting ahead of time for best customization for voting
- [Create bracket online](https://challonge.com/tournament/bracket_generator)

### Day 2

#### Lecture

- Discuss controlling devices from Losant

#### Lab

- Revise firmware and Losant environment to support input controls (blink light on / off)

### Assignment

- Due start of current week: A10 - Bluetooth car 
- Given out start of current week: 

---



# **Skipped / Eliminated**

## BLE Health Service

- The goal was to send a temperature from Argon to Bluefruit app but it rarely worked

#### Lab - ble_health_temp_start

- Distribute github link to download (post on slides)
- Describe project goals
- Explain **argon_ble_setup.h** at a high level
  - Have students change **DEVICE_NAME**
- Draw picture of how temperature data is organized
  - 6 bytes total
  - byte 1: 8 bits of flags
  - bytes 2-5: 4 byte floating point number
  - byte 6: temperature type
- Define constants and globals
  - UPDATE_INTERVAL_MS
  - prevUpdate = 0;  // time of last update in millis()
  - float prevTempF = -1.0;        // previous temperature in Fahr
  - uint8_t batteryLevel = -1;     // battery level percentage [0-100]
- Write **loop()** together
- Write **getTemp()** together
  - Call       **update_ble_temperature**
- Write **getBatteryLevel()** together
  - call update_ble_battery_level



## LCD screen

#### Lecture

- I2C LCD
- Ultrasonic distance sensor

#### Lab

- exercises in slides

### Feedback

- Fail.
- The LCD devices only worked for half the students (either faulty devices or bad libraries). Definitely DO NOT use LCDs again
- Ultrasonic sensor worked mostly

## ThingSpeak 

### Day 2

### Lecture

- OLED graphics
- walk through of Thingspeak (==need to make slides==)
  - Create webhook in Particle
  - send temperature data through `Particle.publish` to thingspeak

### Feedback day1

- Recommend **NOT** using thingsspeak again. Thingspeak integration with webhook is fairly simple. It is also possible to discuss JSON to send multiple values.
- However, thingsspeak doesn't have a way to send commands to Argon (have to use something like IFTTT)

### Assignment

- Due start of current week: A8 - Alarm clock
- Given out start of current week: ==A9 - Bluetooth car== part 1 (build chassis only)

### Day 1 (following week)

#### Lecture

- Finish ThingSpeak integration with multiple values as JSON

#### Lab

- Finish ThingSpeak integration with multiple values as JSON walk through example

#### Lecture

- Explain what APIs are; show them a few public ones
- Discuss [weather stack](https://weatherstack.com/) show example call
- show JSON slides
- walkthrough integration
- write json code together

#### Lab

- Create [weather stack](https://weatherstack.com/) account
- Have them use their own api key to view JSON in a browser (use formatter online if necessary
- Create webhook in Particle
- Copy code from particle publishing and subscribing
- Test: publish request and see if subscribe code retrieves JSON data


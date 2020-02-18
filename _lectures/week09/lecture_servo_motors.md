---
marp: true
theme: itp

week: 9
category: lectures
title: Servo Motors

---

<!-- headingDivider: 2 -->

# Servo Motors

#### Guest Lecture by Ray Kim

## Goals

1. Discuss servos
2. Difference between servos and DC motors
3. Implement a servos
4. Combine DC motors and servos

## Servo

* Short for “servomechanism”
  * A servomotor is a type of servomechanism
* Uses feedback mechanism to precisely control the position or effect of a mechanical device

## Servomotor Applications

* Hobby servos typically control angles
  * Some servos are continuous and are essentially precisely controlled DC motors with a feedback mechanism

* Service range of typical servos are between 0 and 180 degrees

## Wiring Diagram

<img src="lecture_servo_motors.assets/servo_bb.png" alt="servo_bb" style="width:700px" />

## Servo Class

* The `servo` class is already part of the Particle OS, meaning we don’t need any special libraries to run it

* The `servo` class has a constructor for a **Servo** object and methods to interact with the servo

## Servo Code

1. Create the Servo object

2. Attach the Servo object to a pin

3. Write to the Servo object

## Servo Code

```c++
const int SERVOPIN = D2;
//Create the servo object
Servo servoObj;
void setup(){
    //attach the servo object to the servo pin 
    servoObj.attach(SERVOPIN);
}
void loop(){
    servoObj.write(0); //write the servo to position 0 degrees
    delay(1000); //wait one second
    servoObj.write(90); //write the servo to position 90 degrees
    delay(1000);
    servoObj.write(180); //write servo to position 180 degrees
    delay(1000);
}
```

## Servo Limitations

* Small hobby servos usually have a small plastic tab that keeps the armature from rotating past a certain point
* Rotating beyond this point usually breaks the small plastic tab

* This creates a continuous servo

## Controlling a Servo

* We can use a potentiometer to control a servo’s positioning
* Potentiometers have values 0 – 1023

* Have to scale that value to be 0 – 180 


* Use the map() function

## `map()` Function

```C++ 
map(value, fromLow, fromHigh, toLow, toHigh)

// value – value we want to convert
// fromLow – input low value
// fromHigh – input high value
// toLow – output low value
// toHigh – output high value
```

## `map()` Function

```c++
int potVal = analogRead(POTPIN);


int angleVal = map(potVal, 0, 1023, 0, 180);

```

## Credits

* Images created with [Fritzing](https://fritzing.org/home/)


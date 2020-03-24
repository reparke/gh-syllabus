---
marp: true
theme: itp

week: 10
category: lectures
title: Servo Motors

---

<!-- headingDivider: 2 -->

# Servo Motors

<img src="lecture_servo_motors.assets/image-20200323184116654.png" alt="image-20200323184116654" style="width:500px" />

## Goals

1. Discuss servos
2. Difference between servos and DC motors
3. Implement a servos
4. Combine DC motors and servos

## Servo

* Short for “**servomechanism**”
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

## Servo Code - Creating the Servo Object

```c++
const int SERVO_PIN = D2;
//Create the servo object
Servo servoObj;
void setup(){
    //attach the servo object to the servo pin 
    servoObj.attach(SERVO_ON);
}
```

## Servo Code - Turning the Physical Servo

```c++
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

## Reminder: Argon PWM Pin Groups

* PWM pins are assigned to one of three groups
* All pins in a group must produce the same PWM value

  * Pins D4, D5, D6, D8
  * Pins A0, A1, A2, A3
  * Pins D2, D3, A4, A5

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
* Original slides created by Ray Kim
* [Sparkfun](https://www.sparkfun.com/products/14760)


---
marp: true
theme: itp

week: 8
category: lectures
title: Multi Tasking
---

<!-- headingDivider: 2 -->

# Multi-Tasking: Delay
## Code: Blink LED

```c++
void setup() {
  pinMode(D7, OUTPUT);
}

void loop() {
  digitalWrite(D7, HIGH);   
  delay(1000);                       
  digitalWrite(D7, LOW);     
  delay(1000);                       
}
```

## Delay Problems

* `delay()` is **blocking**
  * This means the Argon is essentially paused and can't do anything else
* We need to be able to synchronize events and **multi-task** just like our computers and phones

## Step 1: Let's Use the Clock

* `millis()` is a function that returns the "relative current time" 
  * Number of **milliseconds** that have elapsed since the Argon last turned on / reset
* We can call `millis()` at different points in time to compare the passage of time
* When a specific time has elapsed, we can take an action



## Note about `millis()` and `long`

* The "on time" is returned as an `long`

* `long` is like an `int` but has a larger capacity

* Normally `long` stores 32 bit numbers (positive and negative)

* range of `long`: -2,147,483,648 to 2,147,483,647

  

## Note about `millis()` and `unsigned long`

  * However, the "on time" will never be negative

  * We can specify a variable as `unsigned` which means the lowest value is **0** 

  * range of `unsigned long`: 0 to 4,294,967,295

  * Syntax

    ```c++
    unsigned long currentTime = millis();
    ```

     

## Step 2: Track the Current State

* **State** represents any variables or relevant data about our device at the current moment
* For a single LED, the states are either **ON (HIGH)** or **OFF (LOW)**

## Our New Plan

* if *ledState* = **LOW** AND interval is over
  * then *ledState* = **HIGH**
  * update time
  * turn on LED
* if *ledState* = **HIGH** AND interval is over
  * *ledState* = **LOW**
  * update time
  * turn off LED

## Visual Representation

<img src="lecture_multi_tasking.assets/1570497035509.png" alt="1570497035509" style="width:800px;" />

## Code: Blink LED without Delay
```c++
unsigned long prevMillis = 0;	//last time we checked time
int ledState = LOW;					//initial state
int interval = 1000;
void loop() {
  unsigned long curMillis = millis();     //current time
  //check if (now - previous) is more than our interval
  if (curMillis - prevMillis >= interval) {   
    previousMillis = curMillis;      //if YES, update previous
    if (ledState == LOW) {           //if LED ON, now it is OFF
      ledState = HIGH;                                
    } else {						//if LED ON, now it is OFF
      ledState = LOW;
    }
    digitalWrite(LED_PIN, ledState);
  }
```



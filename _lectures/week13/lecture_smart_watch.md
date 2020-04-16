---
marp: true
theme: itp

week: 13
category: lectures
title: Smart Watch
---

<!-- headingDivider: 2 -->



# Smart Watch

<img src="lecture_smart_watch.assets/smart_watch.gif" alt="smart_watch" style="width:500px;" />

## Starting Project

  * For assembly and wiring, refer to [these instructions](guide_build_watch.md)
  * Download starting code: Go to [https://bit.ly/ProjectZip](https://bit.ly/ProjectZip)
    * Paste the following link into the top right
      https://github.com/reparke/ITP348-Physical-Computing/tree/master/_exercises/week13/smart_watch_start

  ## What's Included

  * Libraries
    * Micro OLED
    * MAX30102 heart rate sensor
  * Bitmaps byte arrays for heart rate, clock, and weather (`.h` files)
  * Heart rate BPM calculation

##  States

* Three states: `TIME`, `WEATHER`, `HEART`
* Need to design `getNextState()` function
* Need to support state transitions in `loop()`

##  

## Problem with Buttons
<img src="lecture_smart_watch.assets/Bouncy_Switch.png" alt="switch_bounce.png" style="width:900px;" />

## Problem with Buttons

<img src="lecture_smart_watch.assets/Bouncy_Switch.png" alt="switch_bounce.png" style="width:400px;" />

* Buttons and switches are mechanical and they tend to fluctuate briefly when pressed
* Leads to circuit "bounce" before the value stabilizes
* Argon typically goes through `loop()` multiple times before this stops so we can get false buttons presses or incorrect values

## Solving Debouncing

* This works by only considering input if the signal has been stable (*the same*) for a fixed amount of time 
* Everytime we see the signal is "bounce", we reset our `millis()` counter
* Once we verify the signal has been stable for long enough, we then check for a button press
* We need to distinguish **current button reading** (which may be noisy) from **current button state** (which we have confirmed is a legitimate HIGH / LOW value)

## Debouncing Algorithm

* If current button reading is **not** the same as last button state
  * Reset debounce counter
* If signal has been stable long enough (currentTime-lastDebounce > debounceDelay)
  * If current button reading is different from current button state
    * Update button state (legitimate button press)
    * **Here you execute desired code for button presses**
* Update previous button state with the reading value

##  

## Heart Rate Screen

<img src="lecture_smart_watch.assets/heart.jpg" style="width:500px;" />

## Detecting Heart Rate

<img src="lecture_smart_watch.assets/image-20200416155711370.png" alt="image-20200416155711370" style="width:500px" />

*MAX30105 and MAX30102 are similar sensors*

## MAX30102 Heart Rate / SpO2 Sensor

* Use red and infrared lights
* Measure 
  * heart rate
  * blood oxygen (SpO2 pulse oximetry)
  * temperature
* Best for use on finger or earlobe due to red / infrared light
* Wrist-based sensors typically use green light (like Apple Watch)

## MAX30102 Operation

* Uses built-in LEDs to pulse light onto skin
* Measures light reflecting back
* Operates at 3.3v
* Uses I2C communication
  * I2C is another protocol like SPI we used for OLED

## MAX30102 Wiring

| Sensor | Argon | Function              |
| ------ | ----- | --------------------- |
| GND    | GND   | Ground                |
| VCC    | 3V3   | Power (requires 3.3v) |
| SDA    | SDA   | I2C data              |
| SCL    | SCL   | I2C clock             |

## I2C for Serial, Synchronous Communication

<img src="../weekX/lecture_i2c_lcd.assets/52ddb2d8ce395fad638b4567.png" alt="Synchronous communication" style="width:1000px;" />

## I2C

* Inter-integrated Circuit  (I2C) is a protocol to allow a central device to communicate with multiple "peripheral" chips
* Serial
* Synchronous
* Only two pins
  * Data (```SDA```)
  * Clock (```SCK```)

## I2C vs SPI


| I2C                  | SPI                                              |
| -------------------- | ------------------------------------------------ |
| Uses 2 wires         | Uses 4 wires; more devices means even more wires |
| Uses more power      | Uses less power                                  |
| Lower transfer speed | Higher transfer speed                            |
| Standardized         | Multiple "versions"                              |



## Heart Rate Design Goals

* We want to always track heart beat so displayed as soon as heart screen loads (note: this is not power efficient)
* We want to eliminate "noisy-ness" (flucutations) in heart rate so we will average the last for approximation of the heart rate (**smoothing**)

## Heart Rate Requirements

* Reading of the sensor needs to be fast in order for Argon to properly identify beat
* Updating the OLED is display is (relatively) slow
* Calculating actual heart rate average is also slow (uses for loop)
* Solution
  * Make reading from the sensor on a timer

## Software Timers

* Software timers are another way to have code repeat at a specific time

```c++
//Step 1: Declare global timer
Timer timer(<<FUNCTION>>, <<delayInMS>>);

//Step 2: Create your own function to repeat
void <<FUNCTION>>() {}

void setup() {
    timer.start();		//Step 3: Start timer (repeats on its own)
}
```



## `millis()` vs Software Timers

| millis()                           | Software Timers                                              |
| ---------------------------------- | ------------------------------------------------------------ |
| no limit on timed actions          | limited to 10 timers                                         |
| repeat time can be less than 1ms   | 1 ms is smallest repeat                                      |
| need to execute action in `loop()` | timer runs on its own                                        |
| all actions are synchonous         | timers may execute out of order (this can be both good and bad) |



## Heart Rate Algorithm

* Calculate most recent heart BPM
* If heart rate is above a threshold
  * Display BPM
* Else display `---`
* Display body temperature

##  

## Time Screen

<img src="lecture_smart_watch.assets/time.jpg" style="width:500px;" />

## Time

* Figure out and set timezone `Time.zone(TIMEZONE)` ([guide](https://greenwichmeantime.com/time-zone/definition/))

* Enable DST `Time.beginDST()`

* Draw clock bitmap `clock_16x12`

* Figure out date format
  ```c++
  String dateFormat = "%a %d";
  oled.println(Time.format(dateFormat));
  ```
* Figure out time format
    ```c++
  String timeFormat = "%I:%M%p";
  oled.println(Time.format(timeFormat));
  ```

##  

## Weather Screen

<img src="lecture_smart_watch.assets/weather.jpg" style="width:500px;" />



## Weather Display

* Create Particle webhook
* Connect to weather API
* Parse JSON
* Display data
* Use bitmaps byte array in `bitmaps_weather.h`

## References

* [MAX30102 datasheet](https://datasheets.maximintegrated.com/en/ds/MAX30102.pdf)
* [Particle Argon reference - software timers](https://docs.particle.io/reference/device-os/firmware/argon/#software-timers)

## Credit

- [Measure Heart Rate Project](https://create.arduino.cc/projecthub/SurtrTech/measure-heart-rate-and-spo2-with-max30102-c2b4d8) 

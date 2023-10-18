---
marp: true
theme: itp

week: 9
category: lectures
title: Argon BLE Syntax
---

<!-- headingDivider: 2 -->

# Argon BLE Syntax

## Overview

* Present basic guide to **receiving** data from phone app to Argon
* To simplify some of the code, we will be using a custom-built BLE library
* For more in-depth information including **sending** from Argon and connecting to multiple devices
  * [Particle BLE Docs](https://docs.particle.io/reference/device-os/firmware/argon/#bluetooth-le-ble-)
  * [Particle BLE Tutorials](https://docs.particle.io/tutorials/device-os/bluetooth-le/)

## Receiving Data with Argon

```c++
void onDataReceived(const uint8_t* data, size_t len,
                    const BlePeerDevice& peer,void* context);
```

* After a BLE connection is made, `onDataReceived` is the event handler that is called when data is received by the Argon
* We are only concerned with the first two parameters: `data` and `len`

## Receiving Data with Argon

* `const uint8_t* data`
  * `uint_8` is the variable type for unsigned byte (8 bits)
  * `const uint8_t*` is a pointer, which in C++ indicates the start of an array
  * `data` represents an array of bytes
* `size_t len` represents the number of bytes that were received

## Handling Pointers

* Pointers are powerful, wonderful, and complex C++ tool
* However, we are just going to treat `data` as an array

## Example

* Let's say the `onDataReceived` parameter `len` equal 5

* We can then treat the `data` variable as an array of bytes

  ```c++
  Serial.println("First element: " + String(data[0]));
  
  uint8_t thirdByte = data[2];
  
  uint8_t sixthByte = data[5];  //ERROR! len = 5; arrays start at 0
  ```

  

## Bluefruit App 

* When sending data over Bluetooth, data will be packaged in **bytes**
* It is important to know ahead of time the **format** of the data
* We will be using Adafruit's Bluefruit app to communicate with Argon
* The data structure is specific to this app and doesn't apply to other apps
* For reference: [Adafruit Bluefruit Guide](https://learn.adafruit.com/bluefruit-le-connect/controller)

## Bluefruit App Commands

* Each command from the app is a series of bytes 
  * *IMPORTANT: `char` variables or single letters are also bytes*
* The first byte is the `char` of `!` 
* The second byte signals the type of command
* For example
  * `B` means a button on the control pad was pressed
  * `L` means that location data from the phone is being send

## Bluefruit App Control Pad

<img src="lecture_argon_ble_syntax.assets/bluefruit.png" alt="" style="width:400px" />



## Bluefruit App Control Pad

* Button presses send 5 bytes

```c++
[‘!’] [‘B’] [BUTTON_CODE] [BUTTON_STATE] [CRC]
```

* `BUTTON_CODE` represents the symbol pressed (e.g. button was would be `'1'`)
* `BUTTON_STATE` represents if the button was pressed (``'1'``) or released (`'0'`)
* `CRC` is an error-checking byte (*we won't worry about it for now*)

## Examples

* Pressing the **3** button means that the `data` "array" would have the values

```c++
[‘!’] [‘B’] ['3'] ['1'] [CRC]
```

* Releasing the **Up arrow** button means that the `data` "array" would have the values

```c++
[‘!’] [‘B’] ['5'] ['0'] [CRC]
```



## Lab: Control Fan (part 1)

<!-- skip buzzer and/or RGB LED and go straight to motor if short on time -->

* Use Bluefruit app to control a RGB LED and buzzer
* Download starting code
  * Go to [https://bit.ly/ProjectZip](https://bit.ly/ProjectZip)
  * Paste the following link into the top right
    https://github.com/reparke/ITP348-Physical-Computing/tree/main/_exercises/week09/ble_fan_start
* In Bluefruit app, connect to over UART (listed as "controller")

## Lab: Control Fan (part 1)

* Specifications
  * When "1" is pressed down, on-board LED D7 will blink twice
  * When "2" is pressed down, on-board LED D7 will turn on
  * When "2" is released, on-board LED D7 will turn off
* Reference:  [Adafruit Bluefruit Guide](https://learn.adafruit.com/bluefruit-le-connect/controller)

##  Lab: Wiring Guide

```
On-board LED    D7

```



## Lab: Control Fan (part 2)

* Specifications
  * When "RIGHT" is pressed down, rotate servo (by fixed amount) clockwise
  * When "LEFT" is pressed down, rotate servo (by fixed amount)  counter clockwise
  * When "UP" is pressed down, speed up motor (by fixed amount)
  * When "DOWN" is pressed down, slow motor(by fixed amount)
  * Optional challenge: 
    * When "3" is pressed down, change direction of fan
    * When "4" is pressed, turn on fan auto mode
* Reference:  [Adafruit Bluefruit Guide](https://learn.adafruit.com/bluefruit-le-connect/controller)

##  Lab: Wiring Guide (part 2)

```
Servo           D2

Motor Controller
 PWMA           D5 
 AIN2           D4 
 AIN1           D3 
 VCC            3v3
 GND            GND
 VM             3v3
 STBY           3v3
```

<img src="lecture_argon_ble_syntax.assets/servo_dc_fan_controller_bb.png" alt="servo_dc_fan_controller_bb" />



---



## Demo Projects

* The following two completed projects are provided
* Each involves using a phone app to communicate with Argon via Bluetooth
* The coding in these examples is much more complicated than the previous exercises

## Demo #1: Control RGB LED with Phone Accelerometers (part 1)

* Use Bluefruit app to send accelerometer data from phone to Argon
* Control RGB LED colors with accelerometer data
* Download starting code
  * Go to [https://bit.ly/ProjectZip](https://bit.ly/ProjectZip)
  * Paste the following link into the top right
    https://github.com/reparke/ITP348-Physical-Computing/tree/main/_exercises/week09/ble_uart_rgb_accel_example

## Demo #1: Control RGB LED with Phone Accelerometers (part 2)

* Using Bluefruit, connect to over UART (listed as "controller") in app
* Enable "accelerometer" in app
* Argon sketch will receive accelerometer data (X, Y, Z) from phone, convert readings to PWM (0-255), and change LED color
* Reference:  [Adafruit Bluefruit Guide](https://learn.adafruit.com/bluefruit-le-connect/controller)

##  

<img src="lecture_bluetooth.assets/ble_uart_rgb_accel_example_bb.png" alt="1571379857064" style="width:900px" />



## Demo #2: Read Health Thermometer Service (part 1)

* Send temperature data **from** Argon **to** phone via nRF Toolbox 

* Argon is using Bluetooth health thermometer service

* Download starting code

  * Go to [https://bit.ly/ProjectZip](https://bit.ly/ProjectZip)

  * Paste the following link into the top right
    https://github.com/reparke/ITP348-Physical-Computing/tree/main/_exercises/week09/ble_health_temp_final

## Demo #2: Read Health Thermometer Service (part 2)

* Using nRF Toolbox app, connect to over HTM ("health thermometer")
* Argon sketch will send temperature data to app
* Reference: [Particle Guide](https://docs.particle.io/tutorials/device-os/bluetooth-le/#body-temperature-thermometer)

##  

<img src="lecture_bluetooth.assets/1571379935995.png" alt="1571379935995" style="width:1000px" />




## References

* [Adafruit Bluefruit Guide](https://learn.adafruit.com/bluefruit-le-connect/controller)

## Credits

* Images created with [Fritzing](https://fritzing.org/home/)


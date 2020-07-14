---
marp: true
theme: itp

week: 8
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

## References

* [Adafruit Bluefruit Guide](https://learn.adafruit.com/bluefruit-le-connect/controller)

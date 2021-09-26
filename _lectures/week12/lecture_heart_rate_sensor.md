---
marp: true
theme: itp

week: 12
category: lectures
title: Heart Rate Sensor (MAX30101)
---

<!-- headingDivider: 2 -->



# Heart Rate Sensor

<img src="lecture_smart_watch.assets/smart_watch.gif" alt="smart_watch" style="width:500px;" />

## Detecting Heart Rate

<img src="lecture_heart_rate_sensor.assets/MAX30101.jpg" alt="image-20200416155711370" style="width:500px" />

## MAX30101 Heart Rate / SpO2 Sensor

* Measure 
  * heart rate
  * blood oxygen (SpO2 pulse oximetry)
  * temperature
* Red / infrared light useful on finger / earlobe
* Green light useful on wrist (like Apple Watch)
* Upgraded version 30105

## MAX30101 Operation

* Uses built-in LEDs to pulse light onto skin
* Measures light reflecting back
* Operates at 3.3v
* Uses I2C communication
  * Same protocol as OLED

## I2C for Serial, Synchronous Communication

<img src="../weekX/lecture_i2c_lcd.assets/52ddb2d8ce395fad638b4567.png" alt="Synchronous communication" style="width:1000px;" />

## I2C

* Inter-integrated Circuit  (I2C) is a protocol to allow a central device to communicate with multiple "peripheral" chips
* Serial
* Synchronous
* Only two pins
  * Data (```SDA```)
  * Clock (```SCK```)

## MAX30101 Wiring

| Sensor | Argon | Function              |
| ------ | ----- | --------------------- |
| GND    | GND   | Ground                |
| VCC    | 3V3   | Power (requires 3.3v) |
| SDA    | SDA   | I2C data              |
| SCL    | SCL   | I2C clock             |




## Library

- Argon-compatible library
  ```MAX30105```
- Configuration

```c++
#include "MAX30105.h"	//sensor library
#include <Wire.h>		//additional library required

MAX30105 heartRateSensor; // object  Definition  
```

## Initialization

```c++
void setup() {
  // Initialize sensor and stop program if sensor missing
  if (!heartRateSensor.begin(Wire, I2C_SPEED_FAST)) {  
    Serial.println("MAX30101 was not found");
    while (1)
      ;
  }
  // Configure sensor with default settings
  heartRateSensor.setup();  
  // Red LED low to show sensor on
  heartRateSensor.setPulseAmplitudeRed(0x0A);
  // enable temperature  
  heartRateSensor.enableDIETEMPRDY();	
  
```

## Sensor Readings

- Reflectivity of light (red, green, infrared) can be measured separately

```c++
long irValue = heartRateSensor.getIR();
long redValue = heartRateSensor.getRed();
long greenValue = heartRateSensor.getGreen();
```

- Temperature can be measured in Celcius or Fahrenheit

```c++
float temperature = particleSensor.readTemperature();
float temperatureF = particleSensor.readTemperatureF();
```

## Other Useful Methods

- The process of determining if / when a heart beat has occurred is complicated and the library provides a method

```c++
// fn: checkForBeat
long irValue = heartRateSensor.getIR();

bool didBeatOccur = checkForBeat(irValue);
```

## Credits

- [Sparkfun](https://www.sparkfun.com/products/16474)
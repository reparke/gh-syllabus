---
marp: true
theme: itp

week: 4
category: lectures
title: Cloud Communication - Accessing Variables
---

<!-- headingDivider: 2 -->

# Cloud Communication
<img src="lecture_particle_cloud_functions.assets/iot_cloud.jpg" alt="iot_cloud" style="width:800px;" />



## Review: Particle Cloud Features

* Update device code and firmware
* Receive status messages (like we do with Serial monitor)
* Read the values of variables
* Control device / execute function calls

## Review: Particle Cloud Does NOT

* Store data from device 
  * Ex. the hourly temperature for the past 6 months)
* Run analytics
  * Ex. how often does one of my 4,000 device fail)
* Manage device with publicly-accessible web/mobile 

## Review: Key operations in Particle Cloud

* **Accessing data (cloud variables)**
* Control device (cloud functions)
* Publishing (events part 1)
* Subscribing (events part 2)

## Review: Cloud Variable Example

```c++
double f;			//declare global variable
String lightValue;	//declare global variable

void setup() {
  Particle.variable("lightValue", photoSensor);	//register variable
  Particle.variable("tempFahr", f);				//register variable
```

## Review: Accessing Cloud Variables - App

<img src="lecture_particle_cloud_functions.assets/app_variables.jpg" alt="1569447605240" style="height:700px;" />

## Key operations in Particle Cloud

* Accessing data (cloud variables)
* **Control device (cloud functions)**
* Publishing (events part 1)
* Subscribing (events part 2)

## Cloud Functions

* Register / expose a C++ function in your Argon code so it can be called online
* Up to 15 functions may be registered

## Cloud Function Process

1. Create a regular C++ function to perform a task
   * Function must take **exactly one** parameter of type `String` 
2. Call `Particle.function` within `setup()` to register the function

## Cloud Function Syntax

```c++
Particle.function(<<REGISTERED_NAME>>, <<ACTUAL_FUNCTION_NAME>>);
```

Example

```c++
int ledStatus(String command) {...}	//actual C++ function
    
void setup() {
  Particle.function("ledStatus", ledStatus); //register func
```

Function must return an `int` (typically -1 for fail)

## Calling Cloud Functions - [Particle Console](https://console.particle.io)

<img src="lecture_particle_cloud_functions.assets/1569448280222.png" alt="1569447605240" style="width:1200px;" />

## Calling Cloud Functions - App

<img src="lecture_particle_cloud_functions.assets/app_functions.jpg" alt="1569447605240" style="width:800px;" />

## Calling Cloud Functions - REST

* Functions can be called by any device or service via REST

* REST is very common protocol for sharing data across the internet

* REST call syntax

  `POST /v1/devices/{DEVICE_ID}/{FUNCTION}`

## Lab

* Connect at RGB LED
* Create a cloud function called `changeLight`
* Function should allow you to remotely
  * Turn on the light
  * Turn off the light
  * Change the color (*it is easiest to create a few accepted light colors*)

## Documentation

* [Particle Cloud API](https://docs.particle.io/reference/device-os/firmware/argon/#cloud-functions)
* [Publishing Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-publish-)
* [Cloud Variables](https://docs.particle.io/reference/device-os/firmware/argon/#particle-variable-)
* [Cloud Functions](https://docs.particle.io/reference/device-os/firmware/argon/#particle-function-)
* [Subscribing to Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-subscribe-)

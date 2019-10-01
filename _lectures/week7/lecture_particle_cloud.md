---
marp: true
theme: itp

week: 7
category: lectures
title: Cloud Communication
---

<!-- headingDivider: 2 -->

# Cloud Communication
<img src="lecture_particle_cloud.assets/iot_cloud.jpg" alt="iot_cloud" style="width:900px;" />

## Review: What is the Cloud?

<!-- basically servers connected to the internet all around the world; not one single computer, but many different machines, services, and companies -->

## Internet of Things

- Things
  * "smart" devices that are programmed interact with environment 
- Internet
  * connect to the internet to send and receive data

## IoT Cloud Platforms

* Various services that allow you to enhance your device with internet capability

## Examples of IoT Cloud Services

* Update device code and firmware
* Receive status messages (like we do with Serial monitor)
* Read the values of variables
* Control device / execute function calls
* Store data from device (e.g. the hourly temperature for the past 6 months)
* Run analytics (e.g. how often does one of my 4,000 device fail)
* Manage device with publicly-accessible web/mobile 

## IoT Cloud Platform Companies

* Very competitive and growth space
* Established firms: Google Cloud Platform, Microsoft Azure, Amazon Web Services
* Startups: Particle, Losant, Ubidots
* Various: Thingspeak (Mathworks), IFTTT

## Particle Cloud Features

* Update device code and firmware
* Receive status messages (like we do with Serial monitor)
* Read the values of variables
* Control device / execute function calls

## Particle Cloud Does NOT

* Store data from device (e.g. the hourly temperature for the past 6 months)
* Run analytics (e.g. how often does one of my 4,000 device fail)
* Manage device with publicly-accessible web/mobile 

## Particle Cloud

* Argon has built in support for connecting to Particle Cloud
* Particle Cloud is essentially free (very generous free tier)
* Basically acts as a real-time communication system
  * i.e. the current temperature, but not temperature from last Tuesday
* For data storage and analysis, we will use a different service later in the course

## Quick Note

* All the features we will discuss are not unique to Particle Cloud
* It is possible to read variables and execute functions from most companies' platforms
* The syntax and mechanisms will vary from Particle Cloud, but the concepts are transferable

## Key operations in Particle Cloud

* Publishing (events part 1)
* Accessing data (cloud variables)
* Control device (cloud functions)
* Subscribing (events part 2)

## Events Part 1: Publishing Events

* Events are messages sent from an Argon to the cloud **as often as you choose**
* Events can private (viewable by only by you and devices in your account) 
* Events can be public (viewing by anyone in the world)
  * Public events should not include any confidential data
* Events can be accessed in [Particle console]([https://console.particle.io/](https://console.particle.io/)), app, or by other devices (subscribing)

## Events in Particle Console

<img src="lecture_particle_cloud.assets/1569446342143.png" alt="1569446342143" style="width:600px;" />



<img src="lecture_spi_oled.assets/OLED_Action.jpg" alt="Micro OLED" style="width:500px;" />

## Publish Syntax

```c++
Particle.publish(<<EVENT_NAME>>, <<EVENT_VALUE>>, <<FLAGS>>); 
```

Example

```c++
Particle.publish("lightValue", "bright", PUBLIC); 
Particle.publish("tempFahr", String(85.9), PRIVATE);
```

* Names and values must always be strings
* Should only publish 1 event / sec (or burst of 4 events in 1 sec)

##  

## Cloud Variables

* Register / expose a variable in your Argon code so it can be accessed online
* This does **not** publish the value of the variable automatically
* Cloud is notified variable exists, and it is retrieved only when requested
* Up to 20 variables may be registered

## Cloud Variables Process

1. Declare global variable (must be `int`, `double`, or `String`)
2. Call `Particle.variable` within `setup()` to register the variable

## Cloud Variable Syntax

```c++
Particle.variable(<<REGISTERED_NAME>>, <<ACTUAL_VARIABLE>>);
```

Example

```c++
double k;			//declare global variable
String lightValue;	//declare global variable
void setup() {
  Particle.variable("lightLevel", photoSensor);	//register variable
  Particle.variable("tempFahr", f);				//register variable
```

## Accessing Cloud Variables - [Particle Console](https://console.particle.io)

<img src="lecture_particle_cloud.assets/1569447605240.png" alt="1569447605240" style="width:700px;" />

## Accessing Cloud Variables - App

<img src="lecture_particle_cloud.assets/app_variables.jpg" alt="1569447605240" style="height:700px;" />

## Accessing Cloud Variables - REST

* Variables can be accessed by any device or service via REST

* REST is very common protocol for sharing data across the internet

* REST call syntax

  `GET /v1/devices/{DEVICE_ID}/{VARIABLE}`

##  

## Cloud Functions

* Register / expose a C++ function in your Argon code so it can be called online
* Up to 20 variables may be registered

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

<img src="lecture_particle_cloud.assets/1569448280222.png" alt="1569447605240" style="width:700px;" />

## Calling Cloud Functions - App

<img src="lecture_particle_cloud.assets/app_functions.jpg" alt="1569447605240" style="width:400px;" />

## Calling Cloud Functions - REST

* Functions can be called by any device or service via REST

* REST is very common protocol for sharing data across the internet

* REST call syntax

  `POST /v1/devices/{DEVICE_ID}/{FUNCTION}`

##  

## Events Part 2: Subscribing to Events 

* Argon can by specifically notified when a particular event published
  * This is called **subscribing** an event
* When the notification arrives, the Argon can execute an action / call a function
  * This is called an **event handler** (basically a special function) sent by other devices or by the cloud are messages sent from an Argon
* You subscribe to any public events, or any private event generated by devices in your account

## Quick Overview to Event-Driven Programming

* Argon is telling the cloud,  "I want to listen for something called an **event**"
* Cloud eventually tells Argon, "The **event** just happened, and here is the **data**"
* Argon then **automatically** executes the **event handler function**
  * This seems confusing--WE DO NOT call the event handler function
  * We just define the function body, and Argon calls it when the event arrives

## Event Subscribing Process

1. Create an event handler (regular C++ function) to be called when the event arrives 
2. Call `Particle.subscribe` within `setup()` to register the subscription

## Review: Publish Syntax

```c++
Particle.publish(<<EVENT_NAME>>, <<EVENT_VALUE>>, <<FLAGS>>); 
```

Example

```c++
Particle.publish("lightValue", "bright", PUBLIC); 
Particle.publish("tempFahr", String(85.9), PRIVATE);
```



## Event Subscribing Syntax: Event Handler

```C++
void <<EVENT_HANDLER>>(const char *event, const char *data) {
```

Example
```C++
void tempEventHandler(const char *event, const char *data) {
    Serial.println("Just received the event called " +
                   String(event) + " with the value " + 
                   String(data));
```

## Event Subscribing Syntax: Event Handler

```C++
void tempEventHandler(const char *event, const char *data) {
```

* `event` is the parameter that will be the event name
* `data` is the parameter that will be the data sent by the event
* Technically, these are pointers to C-style arrays. For our purposes, we will convert them to `String` 

## Event Subscribing Syntax: Subscribing to an Event 

```C++
Particle.subscribe(<<EVENT_NAME>>,
                   <<EVENT_HANDLER_C++_FUNCTION>>,
                   <<FLAGS>>);

```
Example
```C++
void setup() {
    Particle.subscribe("tempFahr", tempEventHandler,MY_DEVICES);
```

* `MY_DEVICES` subscribes to PRIVATE events
* `ALL_DEVICES` subscribes to PUBLIC events

## Documentation

* [Particle Cloud API](https://docs.particle.io/reference/device-os/firmware/argon/#cloud-functions)
* [Publishing Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-publish-)
* [Cloud Variables](https://docs.particle.io/reference/device-os/firmware/argon/#particle-variable-)
* [Cloud Functions](https://docs.particle.io/reference/device-os/firmware/argon/#particle-function-)
* [Subscribing to Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-subscribe-)

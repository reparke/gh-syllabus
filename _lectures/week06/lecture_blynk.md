---

marp: true
theme: itp

week: 6
category: lectures
title: Creating IoT Mobile Apps with Blynk
---

<!-- headingDivider: 2 -->

# Blynk

![bg opacity:.75](lecture_blynk.assets/blynk.jpg)

## What is Blynk?

* Blynk is a drag-and-drop, visual tool to build mobile apps
* Mobile apps can interact with, receive data from, and control IoT devices 
* You can develop add your own branding and package the app with your IoT device

## Blynk Functionality

- Data storage
- Display real-time sensor data and historical data
- Control IoT device from app
- Email / push notification when device is offline
- Custom webhooks

## Blynk Evaluation

| Advantages                                                   | Disadvantages                                    |
| ------------------------------------------------------------ | ------------------------------------------------ |
| Highly customizable                                          | Free version has limitations                     |
| Easier to integrate than other mobile dashboards (e.g. Losant) | Dashboard is limited (compared to Initial State) |
| Easy to design mobile app without coding                     | Requires modifying `loop()` logic                |
| Control IoT device better than with IFTTT                    | Mobile only (can't view on web)                  |

## Integrating

1. Download Blynk app on your phone
2. Install Blynk library in Workbench (`blynk`)
3. Create Blynk account in app and copy authorization token

## Creating a project

![bg](lecture_blynk.assets/blynk (3).png)

## Virtual Pins

- Use **virtual pins** to send and receive data from Argon
- These are not real hardware pins, but just a concept used by Blynk
- Virtual pins support `ints` and `Strings` (unlike hardware pins) 
- 32-128 pins are supported (label `V0`, `V1`, etc.)
- Note: You **can not** use `const int` to define virtual pins. If you want to define pin label, use `#define VPIN_LED V2` syntax

## Configuring Blynk

```c++
#include <blynk.h>

// From Blynk App: Go to the Project Settings (nut icon)
char auth[] = "YourAuthToken";

void setup(){
  delay(5000); // Allow board to settle
  Blynk.begin(auth);
  Blynk.syncAll(); //optional if you want the argon to be sent all app values when argon resets

}
```



## Three important rules about `loop()`

- `loop()` must include the following code

```c++
void loop(){
  Blynk.run();
}
```

- Do **not** use delay in `loop()` or it will interfere with cloud connection
- Must use a `millis()` or a timer to send data to app (limit to 10 values per second)

## App: Send data from Blynk App to Argon

![bg right:33%](lecture_blynk.assets/blynk (8).png)![blynk (8)](lecture_blynk.assets/blynk (2).png)


## Syntax: Send data from Blynk App to Argon

- To send data FROM **app** TO **argon**, create a `BLYNK_WRITE(vPin)` function 
- This event handler will be called automatically when the app changes

```c++
BLYNK_WRITE(<<VIRTUAL_PIN>>){
    //code
}
```
## Example: Send data from Blynk App to Argon

```c++
BLYNK_WRITE(V0){
  //assign incoming value from pin V0 to a variable
  int pinValue = param.asInt(); //or param.asStr() or .asDouble()
  Serial.println("V0 Slider value is: " + String(pinValue));
}
```

## Syntax: Send data from Argon to Blynk App

- To send data from Argon to Blynk App, use 

```c++
Blynk.virtualWrite(<<PIN>>, <<VALUE>>);
```

## Example: Send data from Argon to Blynk App

```c++
unsigned long blynkDelay = 10000; //change this as needed

void loop() {
  unsigned long curMillis = millis();
  if (curMillis - prevMillis > blynkDelay) {
    double tempF = ...; //read a sensor
    Blynk.virtualWrite(V1, tempFermF);
    prevMillis = curMillis;
  }
 
  Blynk.run();
}
```

## App: Send data from Argon to Blynk App

![blynk (4)](lecture_blynk.assets/blynk (4).png)
## Exercise

* Install Blynk app on your phone


- Connect RGB led and magnetic switch 

* Build Blynk with the following features
  * Use button to control onboard LED via pin `V5` (app --> argon)
  * Send random number (0-255) to app and display on pin `V6` (argon --> app)
  * Use virtual LED to show random number on pin `V6` (argon --> app)

## Lab

<img src="lecture_blynk.assets/switch-magnetic-door_and_rgb_led_bb.png" style="width:500px;" />

## Lab

* Work in teams and create the following functionality in Blynk app
  * Use ZeRGBa to control LED on pins `V0 V1 V2` (app --> argon)
  * Use display to show if switch is `open` or `closed` on pin `V3` (argon --> app)
  * Create a button on `V4` to display a random color from an enumerated list
  
  ```c++
  enum Color { WHITE = 1, GREEN, MAGENTA, BLUE, YELLOW, RED, ORANGE };
  ```
  
  * Create a menu to display a named color from the enum options `Color`on pin `V5` (app --> argon)
  * Create gauge display the random number on pin `V6` (argon --> app)
  
* What happens if you put `Blynk.syncAll();` at the end of `setup()`? 

## Lab Blynk App

|                                                              |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| <img src="lecture_blynk.assets/IMG_1618.png" alt="IMG_1618" style="zoom:50%;" /> | <img src="lecture_blynk.assets/IMG_1619.png" alt="IMG_1619" style="zoom:50%;" /> |





## Resources

- [Blynk example builder](https://examples.blynk.cc/?board=Particle%20Photon&shield=Particle%20WiFi&example=Widgets%2FTerminal)

## Credit

* Image from [Blynk](https://blynk.io/)
---
marp: true
theme: itp

category: reference
title: Pulse Width Modulation
show_in_list: true

---

<!-- headingDivider: 2 -->

# Pulse Width Modulation

## Main Idea

* PWM is a technique we use to simulate analog outputs
* Basically, we switch a digital output on/off very quickly *(modulate)*
* The result is the "effective" output voltage can be varied (since the signal is switching between high and low)
* The "effective" output voltage varies from 0 volts (always off) to 3.3v (always on)
* This is controlled by a parameter to `analogWrite` that varies from `0` to `255`
* Default frequency: 500 Hz (2 ms)


### Supported Pins

* Only certain pins support PWM
  * Pins `D2`-`D8` 
  * Pins `A0`-`A5` 

* PWM pins are assigned to one of three groups
* Each group can have different PWM values (duty cycles), but must share the same  frequency and resolution
  * Pins D4, D5, D6, D8
  * Pins A0, A1, A2, A3
  * Pins D2, D3, A4, A5

## Operation

- PWM can be used to control the brightness of an LED
  - `0` means LED is off (`0v`)
  - `127` means the LED is at half-brightness (`1.67v`)
  - `255` means LED is fully on (`3.3v`)
- PWM can be used to control motor speed

## Code

Consider an LED connected to pin `D2`

```c++
const int PIN_LED = D2;   //pin D2

void setup() {
  //initialize the pin mode
  pinMode(PIN_LED, OUTPUT);
}

void loop() { 
  analogWrite(LED_PIN, 0);	  //0% duty cycle, or 0v
  delay(100);				  //delay 100 ms
  analogWrite(LED_PIN, 127);  //50% duty cycle, or 1.67v
  delay(100);				  //delay 100 ms
  analogWrite(LED_PIN, 255);  //100% duty cycle, or 3.3v
}
```

## Credits

- [The Arduino.cc Team](https://commons.wikimedia.org/wiki/File:Pwm_5steps.gif)
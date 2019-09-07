---
marp: true
theme: itp

week: 3
category: lectures
title: Analog Input with Potentiometers

---

<!-- headingDivider: 2 -->

# Analog Input


## Analog vs. Digital
<img src="lecture_analog_input_potentiometers.assets/analog-clock-1295631_960_720-1565746786122.png" alt="analog clock" width=300 /><img src="lecture_analog_input_potentiometers.assets/clock-997589_960_720.jpg" alt="digital clock" style="width:300px" />

## Analog vs. Digital

* Analog: **infinite** variations / states
* Digital: **discrete** (or **finite**) states

## Potentiometer (Pot)

* Variable resistor with 3 pins
  - power, ground, **wiper**
* **Wiper** pin connect to circuit
  - As wiper moves, resistance varies from 0 Ohms to max (e.g. 10K Ohms)
<img src="assets/1565313560201.png" style="width:200px" alt="potentiometer schematic symbo" />
<img src="lecture_analog_input_potentiometers.assets/515deb26ce395f3959000000.png" style="width:300px" alt="potentiometers" />


## Where do we find pots?

## Where do we find pots?

<img src="assets/potentiometer-482082_960_720.jpg" style="width:350px" />

* Also car stereo knobs, dimming light switches, etc.



## How a Potentiometer Works

<img src="lecture_analog_input_potentiometers.assets/511ac8f5ce395f5846000000.png" alt="Schematic symbol for a potentiometer" style="width:200px" />

* **Vout** is the wiper (middle pin)
* Inside the potentiometer is a resistor
* As the knob moves, the wiper divides the resistor, and the ratio of resistance between Vin-Wiper and Wiper-Gnd varies
* This is called a **variable voltages divider** *(more on this later)* 

## Example

<img src="lecture_analog_input_potentiometers.assets/511ac8f5ce395f5846000000.png" alt="Schematic symbol for a potentiometer" style="width:200px" />

* Let's say potentiometer is 10K Ohms
* If the wiper is all the way to the top, what is the resistance between Vout and Gnd?
* If the wiper is exactly halfway, what is the resistance between Vout and Gnd?

<!-- top: 10K ohms; middle: 5K Ohms -->

## Voltage Dividers

<img src="lecture_analog_input_potentiometers.assets/511ac8f5ce395f5846000000.png" alt="Schematic symbol for a potentiometer" style="width:200px" />

* Argon input pins can measure **voltage**, not **resistance**
* By connecting **Vin** (3.3v), **Gnd**, and **Vout** (wiper), we can now vary the **voltage** difference Vin-Wiper and Wiper-Gnd
* If the wiper is all the way to the top, what is the voltage between Vout and Gnd?
* If the wiper is exactly halfway, what is the voltage between Vout and Gnd?

<!-- top: 3.3v because vout is connected to 3.3v, which is being dropped over 10K resisor; middle: 1.67v because the wiper is "seeing" halfway through the drop of 3.3v across the entire resistor; bottom: 0v because Vout and Gnd are directly connected -->



## Setting up Analog Input

Syntax

```c++
const int PIN_POT = A0;		//input pin
int potValue = 0;			//value from read

void setup() {
	pinMode(PIN_POT, INPUT);
}

```

* Pins A0-A5 are analog input
* *Technically, analog pins are **input by default** but I like to do this for clarity and consistency*

## Reading Analog Input

Syntax

```c++
void loop() {
    potValue = analogRead(PIN_POT);
}
```

* Using our example of Vin=3.3v and a 10k potentiometer, what do you expect for the range of values of **potValue**?



## Credit
- [Pixabay](https://pixabay.com/photos/potentiometer-guitar-electric-guitar-482082/)
- [Pixabay](https://pixabay.com/vectors/variable-resistance-resistors-36565/)
- [Sparkfun](https://learn.sparkfun.com/tutorials/resistors#types-of-resistors)
- [Sparkfun](https://learn.sparkfun.com/tutorials/voltage-dividers)
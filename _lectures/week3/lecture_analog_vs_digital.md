---
marp: true
theme: itp

week: 3
category: lectures
title: Analog vs. Digital

---

<!-- headingDivider: 2 -->

# Analog vs. Digital

## Questions

- What is an example of something that is analog?
- What is an example of stomething that is digital?

## Analog vs. Digital

==pic of clock and digital clock==

## Analog

- The world is analog!

- Paints blend smoothly together

- Violin notes increase smoothly in pitch

- There are can be **infinite** variations for these events


## Digital

- Instead of being infinite, digital signals are **discrete** (or **finite**)

- Think binary: the switch is either **on** or **off** (not "a little bit on")

- Digital values often have more than just two states--but they still have a fixed number of possible values (e.g. integer values 0-255)


## Setting input / output with `pinMode` 

Syntax

```c++
pinMode(PIN_NUMBER, MODE);
//MODE: OUTPUT or INPUT
```

- Most pins on the Argon can be configured to SEND output (e.g. to turn on a light) or to RECEIVE input (e.g. a button press)
- When you want to use a pin in your program, you should specify its mode in `setup()`

## Digital Output

- These are signals that are HIGH or LOW
  - **HIGH** / true is **5V** (pin VUSB) or **3.3V** (pin 3.3v)
  - **LOW** / false is **0V** (ground)
- What is an example of digital output we have seen so far?

<!-- LED -->

## Writing Digital Output with `digitalWrite` 

Syntax

```c++
digitalWrite(PIN_NUMBER, VALUE);
//VALUE: HIGH or LOW
```

- You can send an ON (HIGH) or OFF (LOW) signal at output on a pin
- This is writing a **digital** value
  - Digital values are like boolean values: 0/1, on/off, true/false

## What about input?

## Digital Input

- Pins D2-D8 can be used for digital input *(other pins can also be used)*
- Argon will "read" the voltage on a pin and return HIGH (3.3V) or LOW (0V)
- **Never exceed 3.3V on input**
  - Be careful of other components that operate at 5V

What types of things might we use as digital inputs?

## Reading Digital Input with `digitalRead` 

Syntax

```c++
int value = digitalRead(PIN_NUMBER);
//value is either HIGH or LOW (HIGH and LOW are defined as constants)
```


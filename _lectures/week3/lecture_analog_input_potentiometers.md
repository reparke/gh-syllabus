---
marp: true
theme: itp

week: 3
category: lectures
title: Analog Input and Potentiometers

---

<!-- headingDivider: 2 -->

# Analog Input

==pic of clock and digital clock==

## Analog vs. Digital

- Analog: **infinite** variations / states
- Digital: **discrete** (or **finite**) states
- How do we represent infinite variations in a system that has limited / finite values?

## Recall

![PWM Graph width:400px](lecture_analog_input_potentiometers.assets/pwm.gif)


## Setting input / output with `pinMode` 

Syntax

```c++
pinMode(PIN_NUMBER, MODE);
//MODE: OUTPUT or INPUT
```

- Most pins on the Argon can be configured to SEND output (e.g. to turn on a light) or to RECEIVE input (e.g. a button press)
- When you want to use a pin in your program, you should specify its mode in `setup()`



## Potentiometer

![width:200px](assets/potentiometer-482082_960_720.jpg)

![width:300px](assets/1565313673103.png)

![width:200px](assets/1565313560201.png)

## Credit

- https://www.flickr.com/photos/snazzyguy/4149940565/
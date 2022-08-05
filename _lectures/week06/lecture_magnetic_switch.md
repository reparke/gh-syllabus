---
marp: true
theme: itp

week: 6
category: lectures
title: Magnetic Switch

---

<!-- headingDivider: 2 -->

# Magnetic Switch

<img src="lecture_magnetic_switch.assets/magnetic_switch.jpg" style="width:600px;" />

##  Magnetic Switch

* Switch is "normally open" (open circuit)
* Switch is activated / closed (completing the circuit) when placed near a magnet
* Often used to check for open drawers, doors, etc.
* These are also called a *reed switch* 



## How Reed Switches Work

<img src="lecture_magnetic_switch.assets/Reed_switch_(aka).jpg" alt="image-20200716183944885" style="width:900px" />





## Wiring and Operation

* Connect one wire  
  * 3.3v with 10k pullup resistor
  * Argon digital input pin
* Connect other wire to ground
* Switch is **not polarized** so use either wire
* When reading signal from Argon
  * **HIGH** means open circuit (no magnet present) 
  * **LOW** means closed circuit (magnet present)

## Wiring Example

<img src="lecture_magnetic_switch.assets/switch-magnetic-door_bb.png" style="width:500px;" />

## Quick Note

* Wire ends are thin and twisted together so be careful inserting them into breadboard
* For greater durability, wire ends can be soldered

## Lab:

<img src="lecture_magnetic_switch.assets\switch-magnetic-door_and_rgb_led_bb.png" style="width:600px;" />



## Lab Part 1:

* When the magnetic switch is opened or closed, publish cloud event with the message `door was opened` or `door was closed` when `doorState` changes. Note **only one** publish should occur every time door is opened or closed *(Hint: Think about how this operation is similar to other things we've done. what variables would you need to this?)*
* Your name should be 
  `ITP348_Door`

* Change the RGB colors based on their door status
  * Red means "door is open"
  * White means "door is closed"


## Credit

- André Karwath ([image](https://en.wikipedia.org/wiki/Reed_switch#/media/File:Reed_switch_(aka).jpg), [license](https://creativecommons.org/licenses/by-sa/2.5/deed.en))
- [Sparkfun](https://www.sparkfun.com/products/13247)
- Images created with [Fritzing](https://fritzing.org/home/)




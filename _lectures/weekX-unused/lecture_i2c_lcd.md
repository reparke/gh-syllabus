---
marp: true
theme: itp

week: 
category: lectures
title: I2C LCDs

---

<!-- headingDivider: 2 -->

==Notes to self==

* SDA and SCL lines need pullup resistors (4.7k or 10k) to **3V3** (not VUSB)
* Connect power on LCD to VUSB (otherwise it will be very light and hard to read)
* recommend using M-F wires (each student will need 4 short wires)
* reference: https://docs.particle.io/support/particle-devices-faq/i2c-faq/#it-requires-pull-up-resistors

# I2C LCDs

## Improving Output
* Serial monitor is fine for debugging, but we need better output to build device

* Let's introduce the humble LCD

  

## Liquid Crystal Display (LCD)
<img src="lecture_i2c_lcd.assets/00709-action.jpg" alt="Basic 16x2 Character LCD - White on Black 5V" style="width:500px;" />



## LCDs

* Output device that display text in rows and columns
* Can be use for simple graphics, but primarily for text
* Relatively cheap
* Passive, low power

## LCD Pixels

<img src="lecture_i2c_lcd.assets/525dcd15757b7fee738b4567.jpg" alt="LCD Pixel" style="width: 500px" />



## LCD Come in Many Different Sizes and Colors

<img src="lecture_i2c_lcd.assets/1568248901429.png" alt="1568248901429" style="width:300px;" />

<img src="lecture_i2c_lcd.assets/1568248833760.png" alt="1568248833760" style="width:300px;" />

<img src="lecture_i2c_lcd.assets/1568248880705.png" alt="1568248880705" style="width:300px;" />



## Basic wiring

<img src="lecture_i2c_lcd.assets/LCD_pins.png" alt="Parallel LCD" style="width:400px;" />

## Basic Wiring

* The standard wiring of an LCD uses 16 wires (requiring 12 pins on the Argon)!
* The condensed wiring use 12 wires (requiring 8 pins on the Argon)!
* Writing code to communicate with the LCD is challenging (more on that later)

## Basic wiring

<img src="lecture_i2c_lcd.assets/LCD_pins.png" alt="Parallel LCD" style="width:400px;" />

* 4 pins for power (2 for LCD, 2 for backlight
* 4 pins for controlling LCD 
* 8 (or 4) pins for data (the text you want to display)

## Parallel LCD

* There are 8 pins for data when operating **in parallel**
* Let's say you want to display the letter **Q**

* The letter **Q** is represented on a computer by the binary string
  `01010001`

* Each bit will be transmitted on a separate data pin

  

* I2C explanation

* I2C backpack

* I2C wiring

* Library

* Help students install library; then have them work for a while on a project; then regroup and go over solution

## Credit

- [Sparkfun](https://learn.sparkfun.com/tutorials/basic-character-lcd-hookup-guide/all)
- [Sparkfun](https://www.sparkfun.com/categories/76)


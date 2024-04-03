---
marp: true
theme: itp

week: 16
category: lectures
title: Powering 5V Devices from a Battery

---

<!-- headingDivider: 2 -->

# Powering 5V Devices from a Battery



## Problem

* Some devices such as servos and ultrasonic sensor require 5V to operate
* LiPo (lithium ion) batteries provide 3.7V so these devices might have enough power to operate correctly
* *Note: generally the ultrasonic sensor will function with 3.7V if device power is connected to `Li+` in*

## Solution #1 - Use 5V USB Battery

* Any USB battery pack (like you would use to connect to your phone) with a **USB A** (the older, larger flat type) connecter should work
* Connect the battery pack to the Argon's USB port and the Argon will now have 5V
* Connect your 5V devices to `GND` and `VUSB` on the Argon
* Example: [Power Bank](https://www.amazon.com/10000mAh-Portable-Charger-External-Compatible/dp/B094Y1R46V)

## Solution #2 - Use a Step-Up 5V Voltage Regulator

* A step-up voltage regulator will "step-up" (increase) the 3.3V (or 3.7V) from the Argon to 5V
* Example 1: [Sparkfun Qwiic Boost](https://www.sparkfun.com/products/17238)
* Example 2: [Pololu 5V Step-Up Voltage Regulator](https://www.pololu.com/product/2564)

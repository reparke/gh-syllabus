---
week: 7
category: readings
title: Pre-Lecture Activities
---

## Week {{page.week}}

### switch and enum in C++ (already covered in class last week)

  {% include video id="W6uycVUrkm4" provider="youtube" %}

### State Machines

{% include video id="Wh8xGIYP1Dc" provider="youtube" %}

### Components Needed in Class

- RGB LED
- Magnetic switch
- 10K Ohm resistor
- 330 Ohm resistors
- Potentiometer
- MicroOLED

### Tuesday Wiring

| RGB LED                    | Argon Pins |
| -------------------------- | ---------- |
| NorthSouth RGB LED - Red   | D2         |
| NorthSouth RGB LED - Green | D3         |
| NorthSouth RGB LED - Blue  | D4         |

| MicroOLED (Qwiic cable) | Argon Pins |
| ----------------------- | ---------- |
| GND                     | GND        |
| 3V3                     | 3V3        |
| SDA (Blue)              | SDA        |
| SCL (Yellow)            | SCL        |



![stoplight_RGB_OLED_bb](week07.assets/stoplight_RGB_OLED_bb.png)





### Thursday Wiring

| LED             | Argon Pins |
| --------------- | ---------- |
| Magnetic Switch | D2         |
| RGB Red LED     | D3         |
| RGB Green LED   | D4         |
| RGB Blue LED    | D5         |
| Potentiometer   | A3         |

![image-20210227172856897](week07.assets/image-20210227172856897.png)

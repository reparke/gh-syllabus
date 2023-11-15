---
week: 13
category: readings
title: Pre-Lecture Activities
---

## Week {{page.week}}

### Watch before class this week

* Accelerometer
  {% include video id="ZiEiEboxAHk" provider="youtube" %}

### Bring to class all this week

- Smart watch
- Argon, breadboard, resistors, push buttons, LEDs, RGB LEDS, wires potentiometer
- Accelerometer
- *You can see what parts look like visually by checking out the [kit page](https://reparke.github.io/ITP348-Physical-Computing/kit)*

### Build before class Wed / Thurs

- We will continue with the smart watch from last week

### Build before class Wed / Thurs 

| Sensor | Argon        | Function                        |
| ------ | ------------ | ------------------------------- |
| GND    | GND          | Ground                          |
| VCC    | 3V3          | Power (requires 3.3v)           |
| CS     | 3V3          | Need for I2C mode               |
| SDO    | GND          | Need for I2C mode               |
| SDA    | SDA          | I2C data (no resistors needed)  |
| SCL    | SCL          | I2C clock (no resistors needed) |
| INT1   | Any GPIO Pin | Optional (if using interrupts)  |
| INT2   | Any GPIO Pin | Optional (if using interrupts)  |

![accelerometer_rgb_led_bb](week13.assets/accelerometer_rgb_led_bb.png)

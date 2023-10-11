---
week: 9
category: readings
title: Pre-Lecture Activities
---

## Week {{page.week}}

### Watch before class this week

* Bluetooth

  {% include video id="a56EeVg3z_s" provider="youtube" %}

* Lithium Ion Batteries
  {% include video id="_XG_fL9DO78" provider="youtube" %}

### Bring to class all this week

- Argon, breadboard, resistors, push buttons, LEDs, RGB LEDS, wires potentiometer
- Lithium ion battery
- *You can see what parts look like visually by checking out the [kit page](https://reparke.github.io/ITP348-Physical-Computing/kit)*

### Install before class all week 

- Install Bluetooth apps on your phone
  - [Adafruit Bluefruit](https://learn.adafruit.com/bluefruit-le-connect)
  - [Nordic Semiconductor nRF Toolbox](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Toolbox)

### Build before class all week

The goal is to build a rotating fan. Here is the circuit wiring, and photos are below 

![servo_dc_fan_controller_bb](week09.assets/servo_dc_fan_controller_bb.png)


#### Wiring for Motor Controller

| Motor Controller | Argon | DC Motor            |
| ---------------- | ----- | ------------------- |
| PWMA             | D5    | -                   |
| AI2              | D4    | -                   |
| AI1              | D3    | -                   |
| AO1              | -     | Motor wire (either) |
| AO2              | -     | Motor wire (either) |
| VCC              | 3v3   | -                   |
| GND              | GND   | -                   |
| VM               | 3v3   | -                   |
| STBY             | 3v3   | -                   |

#### Wiring for Potentiometer

- 3.3v
- `A0`
- GND

#### Wiring for Servo

* The wiring colors vary with different servos so look carefully at your documentation
* Many servos will require **5V** not **3.3V** so use `VUSB` 

<img  src="week09.assets/image-20210310115209181.png" alt="image-20210310115209181" style="width:400px" />

#### Photos

<img src="week09.assets/fan1.jpg" alt="fan1" style="width:400px;" />

<img src="week09.assets/fan2.jpg" alt="fan2" style="width:400px" />

<img src="week09.assets/fan3.jpg" alt="fan3" style="width:400px" />

### Optional: Bluetooth Reference

* [Motors Reference Notes](https://www.electronicproducts.com/Electromechanical_Components/Motors_and_Controllers/Motor_control_design_an_introduction_to_motors_and_controllers.aspx)
* [Bluetooth Basics](https://learn.sparkfun.com/tutorials/bluetooth-basics/all)
* [Introduction to Bluetooth Low Energy](https://learn.adafruit.com/introduction-to-bluetooth-low-energy/)

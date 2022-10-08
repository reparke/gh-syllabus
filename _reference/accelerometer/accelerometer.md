---
marp: true
theme: itp

category: reference
title: ِ(Reference) Accelerometer
show_in_list: true

---

<!-- headingDivider: 2 -->

# Accelerometers



<img src="accelerometer.assets/image-20221008015904600.png" alt="1574364327550" style="width:600px;" />



## Wiring

| Sensor | Argon        | Function                        |
| ------ | ------------ | ------------------------------- |
| GND    | GND          | Ground                          |
| VCC    | 3V3          | Power (requires 3.3v)           |
| CS     | --           | no connection                   |
| SDO    | --           | no connection                   |
| SDA    | SDA          | I2C data (no resistors needed)  |
| SCL    | SCL          | I2C clock (no resistors needed) |
| INT1   | Any GPIO Pin | Optional (if using interrupts)  |
| INT2   | Any GPIO Pin | Optional (if using interrupts)  |

## Wiring Diagram

<img src="accelerometer.assets/accelerometer_bb.png" style="width:800px;" />

## Operation

### `ADXL345_Sparkfun_Particle` Library

* Initialize accelerometer object

```c++
ADXL345 adxl; 		//accelerometer object

void setup() {
  accel.powerOn(); // Power on the ADXL345
```

* There are other additional settings to configure tap, etc.
* These can be found in the example files in the library

### Library Operations

* Recommended library for Argon

  * ```ADXL345_Sparkfun_Particle```

* Check for vibrations

  * `accel.readTap()` greater than 0 is a vibration

* Measure acceleration

  * `accel.cx` int value for force of gravity in the X direction
  * `accel.cy` int value for force of gravity in the Y direction

  * `accel.cz` int value for force of gravity in the Z direction

  

## Credit

- [Sparkfun](https://www.sparkfun.com/products/13926)
- [Sensor Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Accelerometers/MMA8452Q-rev8.1.pdf)
- [Accelerometers, Gyros, IMUs](https://www.sparkfun.com/pages/accel_gyro_guide)
- Diagrams created with [Frizting](https://fritzing.org)


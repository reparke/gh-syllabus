---
marp: true
theme: itp

week: 3
category: lectures
title: Analog to Digital Conversion

---

<!-- headingDivider: 2 -->

# Analog to Digital Conversion

## Analog vs. Digital

* Analog: **infinite** variations / states
* Digital: **discrete** (or **finite**) states
* How do we represent infinite variations in a system that has limited / finite values?

## Analog to Digital Conversion

* Argon is a digital system so we need to convert the infinite analog input to a discrete values
* At regular intervals, the pin samples ("reads") voltage it sees 
  - This is called the **sampling frequency** (samples per second)
* The resolution is how many bits are used to store the voltage

## Understanding Resolution

<img src="lecture_adc.assets/2-bit_resolution_analog_comparison.png" style="width:300px" /><img src="lecture_adc.assets/3-bit_resolution_analog_comparison.png" style="width:300px" />

* Red line is analog input voltage (in volts)
* Blue line is the sampling value (just a number with no units)

<!-- red line is the analog input; blue line is the sampling
left: 2 bit resolution; 2^2 = 4 buckets
right: 3 bit resolution; 2^3 = 8 buckets
-->

## Argon ADC Resolution is 12-bits

* When we read the analog input voltage, ADC converts the voltage to a number
* There 2^12=4096 possible values (think "buckets")

## Argon ADC

* The possible analog voltage range is 0v to 3.3v
* The possible digital conversion range is 0 to 4095
* Q: How many digital values per 1v?
* Q: How many volts per each digital value?
* Q: If there is 3.3v on an analog input, what is the value of `analogRead()`?
* Q: If there is 1.67v on an analog input, what is the value of `analogRead()`?

<!-- 3.3v = 4095 so 1v spans 1240 units
or 1 unit = 4095/3.3 -> so 1 unit is 0.8 mV
1.67v is 2047 
-->

## Exercise

* Connect potentiometer to analog pin A0
* Connect LED to digital pin D2 (do we a pin with PWM?)
* Control LED brightness with potetiometer

## Credit

- [Hyacinth](https://commons.wikimedia.org/wiki/File:3-bit_resolution_analog_comparison.png)
- [Hyacinth](https://commons.wikimedia.org/wiki/File:2-bit_resolution_analog_comparison.png)
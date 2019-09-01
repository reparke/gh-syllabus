---
marp: true
theme: itp
paginate: true

week: 2
category: lectures
title: Argon Microcontroller

footer: 'ITP 348 - Rob Parke - USC'
---

<!-- headingDivider: 2 -->

# Argon Microcontroller

## Microcontroller

* Microcontrollers (MCU) are **embedded** computers
* They are often designed for a specific purpose 
  - Ex: a microwave, an RC car, TV remote'
* Like your laptop, microcontrollers can take input, process it, store a value, and produce output
* Unlike your laptop (or even your phone), a microcontroller has very limited processing power and storage 
* Ex: The newer smartphones have 100,000 times more storage than the Argon

## Particle Argon

* In this class, we will develop projects for a microcontroller called an **Argon** made by **Particle**
* The Argon is able to wirelessly connect to the internet and to Bluetooth 
* Particle also has a cloud communication system we will explore later in the semester

## Datasheet

* One important skill of building smart devices is learning to understand a datasheet
* A datasheet explains how a component functions, how to use it, what conditions it will operate, etc.
* Don't worry about understanding everything in a datasheet, but learn to pull out key information

- [Argon Datasheet](https://docs.particle.io/datasheets/wi-fi/argon-datasheet/)

## Work in pairs and answer the following

1. What voltage does the Argon operate at?
2. Which IC (integrated circuit) is the "main" processor?
3. Which IC controls the Wifi module?
4. What is the difference between pins `3v3` and `VUSB`?
5. How many digital input pins are there? 
6. How many analog output pins are there?
7. How many ground pins are there?
8. What is the voltage that the input pins can handle?
9. Can we power the Argon with battery?

## Datasheet 


- [Argon Pinouts](https://docs.particle.io/assets/images/argon/argon-top.png)

- [Argon Datasheet](https://docs.particle.io/datasheets/wi-fi/argon-datasheet/)

<!-- operating voltage: 3.3v -->

<!-- main: nRF52840; wifi: ESP32 -->

<!-- 3v3 is always 3.3v; VUSB is 5v when connected to USB-->

<!-- 20 digital GPIO; 6 analog IN; 0 analog out; 1 ground pin -->

<!-- GPIO can operate at 3.3V max so be caution with higher voltage devices -->

<!-- show other communication pins -->        
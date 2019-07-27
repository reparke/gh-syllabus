---
title: Lectures
layout: page
menuItem: Lectures
menuPosition: 5
marp: true
theme: gaia

---

<style>
h1, h2, h3, h4, h5, h6 {
  color: #990000;
  font-family: 'Adobe Caslon Pro', Cambria, Georgia, serif;
  text-transform: capitalize; 
}
td {
  background: rgba(0, 0, 0, 0);
}

</style>

<!-- headingDivider: 2 -->

# Introduction to IoT

Post Reading: Enabling the Internet of Things https://web.eecs.umich.edu/~prabal/teaching/resources/eecs582/want15iot.pdf


## What is physical computing?


## What are smart devices?

## Physical computing
- "Physical Computing is an approach to learning how humans communicate through computers that starts by considering how humans express themselves physically" --Tom Igoe
- Interacting with "smart" devices in the environment
- Involves programming, electronics, 3d printing, wearables, networking, interaction design

## Why learn this? 

- Jobs
  - 2020: 26 billion Internet nodes (excl. phones, tablets, and computers)
    - 30 fold increase from 2009
  - 2020: 4.5 million Internet of Things (IoT) developers
    - 57% annual growth rate
- Cross-discipline
  - CS, EE, data analytics, product design, entrepreneurship, making

## Why learn this?

- Hardware entrepreneurship
  - Cost of manufacturing is within reach of small amount of funding
  - Tools and open-source platforms mean you can build a prototype without an engineering degree
- Empowering and fun
  - "We are on the verge of machines that can think, and we are carrying magic wands in our pocket but most people see them as read-only" -- Jeff Branson, educator and engineer

## Examples: Gadgets
- Mi.Mu / Imogen Heap (https://youtu.be/3QtklTXbKUQ?t=660)
- Form - AR swim googles

![width:500px](assets/form_googles.png?classes=float-left`)

## Examples: Education
  - Lumi - teach piano
  - Cubertto - learn programming without a screen
![width:500px](assets\lumi.jpg) ![width:500px](assets/cubertto.jpg)


## Examples: Gadgets- Health
  - UFO - beauty mask
  - Jolt - concussion sensor for athletes
![width:500px](assets/ufo_facemask.jpg) ![width:500px](assets/jolt.jpg)

## Examples: Gadgets- Social Good
  - Grillo - early earthquake warnings in rural Mexico and Chile
  - ReWalk - exoskeleton to help people with spinal cord injuries
![width:200px](assets/re_walk.jpg)![width:300px](assets\earthquake_monitor.png)

## What is IoT?

## Internet of Things

![width:700px](assets/iot_cloud.jpg)

## Internet of Things

- Internet
  - connect to the internet to send and receive data
- Things
  - "smart" devices that are programmed interact with environment 


## Hardware


   |                                          |                                              |
   | ---------------------------------------- | --------------------------------------------: |
   | 1. Basic prototype                       | 3. Manufacturing                             |
   | ![height:200px](assets/1564253817153.png) | ![height:200px](assets/pcb_manufacturing.jpg) |
   | 2. PCB prototype                         |                                              |
   | ![height:200px](assets/1564253746864.png) |                                              |

   

## Communication 

- WiFi and Cellular
- Bluetooth Low Energy (BLE)
  - Ex: Communication between smart watch and phone; wireless headphones
  - Range: ~1200+ ft
- Near-Field Communication (NFC) 
  - Ex: Contact-less payment like Apple Pay
  - Range: 4 inches

## Our focus in this class

- building electronic prototype
- creating the software code
- communicating with / controlling device via internet  

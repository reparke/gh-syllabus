---
marp: true
theme: itp

week: 10
category: lectures
title: Cloud Platform and Interface
---

<!-- headingDivider: 2 -->

# Cloud Platform and Interface

## Losant IoT Platform

* What is it? 
* Overview of component parts
* Integrate MCU with virtual device
* Build a workflow for storing data
* Build a dashboard
* Deploy a web app
* Control device from platform



## Key Terms

## Applications

* Includes all your IoT devices and workflow related to a project
* Ex: All the connected devices in your home such as temperature sensors, garage door openers, pet feeder

## Devices

* Device or sensor that communicates with Losant
* Ex: One Argon that monitors the temperature and humidity in your living room

### Device attribute

* A piece of data associated with a device
* Ex: The temperature in your living room

## Integration

* Connection between Losant and external data source that allows data to securely from a web service to Losant
* Ex. Connect Particle Cloud to Losant. Data will flow from Argon --> Particle Cloud --> Losant

### Integration Events

* Events that trigger Losant
* Ex. Particle.publish() events

## Workflows

* The "brains" of your app
* Allow you to specify where data (device attributes) go and are used
* Ex: Store temperature data

## Workflow Elements

* Trigger: event that causes an action
* Logic: code elements (e.g. conditions, functions)
* Data
* Outputs

## Dashboards

* Allow you to view stats, graphs, events and devices across multiple applications
* Ex. Visualize the temperature and light level in your home 

## Lab

##  

Steps

* Create account at [Losant](https://accounts.losant.com/signin)
* Create application (up to 20 in free version)
* Create device for each Argon
  * Go to Particle console > select device > copy device id (==not be necessary for a single device==)
  * Go to Losant and create standalone device
    * For tag: particle_device_id = <<ID>> ==(not be necessary for single device)==
  * Attributes
    * define **temperature_fahr** as **number**
    * define **location** as **string**

* Create integration

  * Go to [particle web console](https://build.particle.io/build/new) > settings > personal access token
  * Go to Losant and create new integration
    * Integration type: **particle**
    * Paste access token
    * Leave configuration blank
    * Event name: **temperature** and **light** (must be same name as Particle.publish())

* Create publish event in firmware code

  <!-- Particle.publish("readings", String(f, 1) + ":" + lightLevel); -->

* Create workflow

  * Add trigger: **Particle**
    * set integration to Particle integration you made
  * Need to extract data from payload --> connect debug node and demonstrate
  * Create function to split data
  * Add output: **device state**
    * individual fields: {{data.lightLevel}} and {{data.tempFahr}}
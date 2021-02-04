---
marp: true
theme: itp

week: 4
category: lectures
title: Cloud Communication - Publish
---

<!-- headingDivider: 2 -->

# Cloud Communication
<img src="lecture_particle_cloud_publish.assets/iot_cloud.jpg" alt="iot_cloud" style="width:800px;" />



## Events Part 1: Publishing Events

* Events are messages sent from an Argon to the cloud **as often as you choose**
* Events can private (viewable by only by you and devices in your account) 
* Events can be public (viewing by anyone in the world)
  * Public events should not include any confidential data
* Events can be accessed in [Particle console]([https://console.particle.io/](https://console.particle.io/)), app, or by other devices (subscribing)

## Events in Particle Console

<img src="lecture_particle_cloud_publish.assets/1569446342143.png" alt="1569446342143" style="width:800px;" />



## Publish Syntax

```c++
Particle.publish(<<EVENT_NAME>>, <<EVENT_VALUE>>, <<FLAGS>>); 
```

Example

```c++
Particle.publish("lightValue", "bright", PUBLIC); 
Particle.publish("tempFahr", String(85.9), PRIVATE);
```

* Names and values must always be strings
* Should only publish 1 event / sec (or burst of 4 events in 1 sec)

## Lab

* Wire diagram with switch and RGB LED
* Create cloud variable state (make `isDoorOpen` variable)
  * What kind of variable should this be?
* Publish cloud event with state if `isDoorOpen`
  * Event name should be 
    `ITP348/Door/<<YOUR_INITIALS>>`

## Lab

<img src="lecture_particle_cloud_publish.assets/switch-magnetic-door_and_rgb_led_bb-1594972874666.png" style="width:600px;" />



## Documentation

* [Particle Cloud API](https://docs.particle.io/reference/device-os/firmware/argon/#cloud-functions)
* [Publishing Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-publish-)
* [Cloud Variables](https://docs.particle.io/reference/device-os/firmware/argon/#particle-variable-)
* [Cloud Functions](https://docs.particle.io/reference/device-os/firmware/argon/#particle-function-)
* [Subscribing to Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-subscribe-)

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
* Events are private (viewable by only by you and devices in your account) 
* Events can be accessed in [Particle console]([https://console.particle.io/](https://console.particle.io/)), app, or by other devices (subscribing)

## Events in Particle Console

<img src="lecture_particle_cloud_publish.assets/1569446342143.png" alt="1569446342143" style="width:800px;" />



## Publish Syntax

```c++
Particle.publish(<<EVENT_NAME>>, <<EVENT_VALUE>>); 
```

Example

```c++
Particle.publish("lightValue", "bright"); 
Particle.publish("tempFahr", String(85.9));
```

* Names and values must always be strings
* Should only publish 1 event / sec (or burst of 4 events in 1 sec)

<!-- public event were removed Aug 2020 -->



## Documentation

* [Particle Cloud API](https://docs.particle.io/reference/device-os/firmware/argon/#cloud-functions)
* [Publishing Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-publish-)
* [Cloud Variables](https://docs.particle.io/reference/device-os/firmware/argon/#particle-variable-)
* [Cloud Functions](https://docs.particle.io/reference/device-os/firmware/argon/#particle-function-)
* [Subscribing to Events](https://docs.particle.io/reference/device-os/firmware/argon/#particle-subscribe-)

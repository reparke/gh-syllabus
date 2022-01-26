---
title: Resources
layout: single
category: Resources
toc: true
toc_label: "Quick Links"
toc_icon: "bookmark"  # corresponding Font Awesome icon name (without fa prefix)
toc_sticky: true

---



## References

### Debugging Tips

- [Using captive wifi networks](captive_wifi/captive_wifi.html)

### Books

- [Practical Electronics for Inventors](https://www.accessengineeringlibrary.com/content/book/9781259587542) available to USC students through USC library subscription



### Particle Documentation

- [Argon datasheet](https://docs.particle.io/datasheets/wi-fi/argon-datasheet/)
- [Argon pin close-up](https://docs.particle.io/assets/images/argon/argon-dimensions.png)
- [Language reference](https://docs.particle.io/reference/device-os/firmware/argon/#language-syntax)
- [Cloud functions refenence](https://docs.particle.io/reference/device-os/firmware/argon/)



### Particle Quicklinks

- [Console](https://console.particle.io/devices)
- [Community / forum](https://community.particle.io/)
- [Web IDE](https://build.particle.io/build)



### Fritzing

* [Fritzing Software](http://fritzing.org/home/)
* Particle Library Parts: [Direct download](https://github.com/reparke/Fritzing-Parts/raw/master/Particle_Mesh_Parts.fzbz) and [GitHub repository](https://reparke.github.io/Fritzing-Parts/)
* AdaFruit Library Parts (useful for OLEDs): [Direct download](https://github.com/adafruit/Fritzing-Library/raw/master/AdaFruit.fzbz) and [GitHub repository](https://github.com/adafruit/Fritzing-Library)
* RFID MFC522 Part: [Fritzing page](https://fritzing.org/projects/mfrc522)



### Arduino

- [Documentation](https://www.arduino.cc/reference/en/)
- [Multi-tasking](https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all) (from Adafruit)



### C++ Language 

- [C plus plus](http://www.cplusplus.com/)
- [C++ Reference](https://en.cppreference.com/w/)



### Losant IoT Platform

- [Getting Started](https://docs.losant.com/getting-started/what-is-losant/)
- [Main app configuration](https://app.losant.com/)

### Bluetooth

* [Particle BLE Documentation](https://docs.particle.io/tutorials/device-os/bluetooth-le/#introduction) (very detailed explanation and example projects)
* [Adafruit BLE Overview](https://learn.adafruit.com/introduction-to-bluetooth-low-energy/gap)
* [Adafruit Bluefruit Guide](https://learn.adafruit.com/bluefruit-le-connect/controller) (instructions on using Adafruit Bluefruit App)
* [List of Official Bluetooth Services](https://www.bluetooth.com/specifications/gatt/services/)
* [List of Official Bluetooth Characteristics](https://www.bluetooth.com/specifications/gatt/characteristics/)
* [Connecting Nintendo Wii Nunchuck](https://www.partsnotincluded.com/arduino/using-wii-nunchuk/)

### Miscellaneous

- [Extensive IoT resources](https://github.com/michaelshiloh/resourcesForClasses) (from Michael Shiloh). This is one of the most comprehensive, helpful lists of tips and links.

   
---



## Project and Sensor Ideas

*[top](#top)*

Note that I can not vouch for most of these projects or sensors personally.

### Inspiration

* [Particle Projects on Hackster.io](https://particle.hackster.io/)
* [Hackster.io](https://hackster.io/) (general)
* [HackADay](https://hackaday.com/)
* [Arduino Project Hub](https://create.arduino.cc/projecthub/)
* [Sparkfun Project Blog](https://www.sparkfun.com/news/tags/projects)

### Biometric Sensors

* [Simple heart rate sensor]( https://www.sparkfun.com/products/11574)
* [Multi-sensor heart rate monitor]( https://www.sparkfun.com/products/12650)
* [Pulse oximeter and heart rate sensor](https://www.sparkfun.com/products/15219)
* [Muscle sensor (control inputs)](https://www.sparkfun.com/products/13723)
* [Blood gas (blood alcohol)](https://www.sparkfun.com/products/8880)

###  Earthquake Monitor

* [Sample project](https://microcontrollerslab.com/earthquake-detector-arduino/)

### Air Quality and Environment Sensors

* [Great resource on Seeed air sensors](http://wiki.seeedstudio.com/Seeed_Gas_Sensor_Selection_Guide/CCS811) 
* [Sample Argon project](https://community.particle.io/t/argon-powered-air-quality-monitor/48932)
* [HPM particle sensor](https://www.sparkfun.com/products/14959) ($40)
  * This sensor is challenging to physically connect and to code for 
* [Grove dust sensor](https://www.seeedstudio.com/Grove-Dust-Sensor-PPD42NS.html) ($12)
  * [Sample code / project](https://airquality406.wordpress.com/code/)
  * Seems Particle compatible
* [Air quality sensor breakout - VOC and eCO2](https://www.adafruit.com/product/3566)
* [Adafruit SGP30 air quality sensor breakout - VOC and eCO2](https://www.adafruit.com/product/3709) ($15)
  * Seems this is more reliable than 811
* [Grove air quality sensor](https://www.seeedstudio.com/Grove-Air-quality-sensor-v1-3-p-2439.html)
* [Carbon monoxide](https://www.sparkfun.com/products/9403)

### Pet Treat Dispenser 

* [Project](https://www.hackster.io/edr1924/arduino-uno-based-easy-to-build-pet-feeder-86c1ef): Sophisticated pet food dispenser
* [Project](https://www.hackster.io/circuito-io-team/iot-pet-feeder-10a4f3): Simple pet food dispenser

### Sound Detection

* [Sound detector](https://www.sparkfun.com/products/14262)

### Guitar Effects Pedal

* [Project](https://www.metamorphsoftware.com/photon-guitar-pedal#): Particle-based guitar compression / distortion pedal
* [Project](https://community.particle.io/t/heres-how-to-build-a-fretless-guitar-powered-by-a-particle-argon/48553): Argon-powered fretless guitar
* [Project](https://www.electrosmash.com/pedalshield-uno): DIY Arduino guitar effects pedal

### Wearables / E-Textiles

* [Flora](https://www.adafruit.com/product/659) - sewable microcontroller with an ecosystem of sensors
* [Lilypad](https://www.sparkfun.com/products/14631) - another sewable microcontroller
* [Conductive velcro](https://www.adafruit.com/product/1324)
* [Conductive thread](https://www.adafruit.com/product/640)
* [Project](https://particle.hackster.io/4189/magoo-e4ff24): Obstacle-detection and GPS-navigation headset for visually-impaired users
* [Project](https://www.hackster.io/news/diy-google-glass-for-under-10-1abea579ccf5): A cool but rather involved pair of DIY smart glasses



### NFC and RFID on Argon

* Argon can only emulate NFC tags--currently supports turning on, turning off, and being notified if tag has been read
* Argon can't communicate / read NFC tags or support payments
* There is a $50 [RFID sensor](https://www.sparkfun.com/products/13198) that enables the Argon to read RFID tags
  * Note that you need to match RFID frequency and tags



---



## Other Courses Materials

*[top](#top)*

- [Computación Física](https://jguerra91.wixsite.com/compfisica20191) - Jorge Guerra Guerra (San Marcos University in Lim, Peru) (in Spanish)
- [IoT](https://classes.engineering.wustl.edu/cse222s/schedule/) - Bill Siever (Washington University in St. Louis)
- [Introduction to Embedded Systems](https://bytes.usc.edu/ee109/) (University of Southern California)
- [Distributed Systems and the Internet of Things](http://bytes.usc.edu/ee250/) - Mark Redekopp (University of Southern California)

- [Network Everything](https://github.com/michaelshiloh/NetworkEverything) - Michael Shiloh (NYU Abu Dhabi)
- [Physical Computing](https://itp.nyu.edu/physcomp/) - Tom Igoe (NYU)
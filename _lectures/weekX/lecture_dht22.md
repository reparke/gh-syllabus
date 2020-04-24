---
marp: true
theme: itp

week: 16
category: lectures
title: DHT 22 - Temperature and Humidity Sensor
---

<!-- headingDivider: 2 -->

# DHT 22 - Temperature and Humidity Sensor

 <img src="lecture_dht22.assets/10167-01.jpg" alt="DHT 22" style="width:800px;" /> 



## Digital Temperature and Humidity Sensor

* DHT 22 (also DHT 11, RHT 03) measure temperature and relative humidity
* Unlike TMP36, this has a digital interface and no calculation or conversion is needed

## Wiring Guide

 <img src="lecture_dht22.assets/10167-02_pinout.jpg" alt="Annotated RHT03" style="width:400px;" /> 

1. 3.3V
2. Digital input (needs 10k pull-up resistor)
3. No connection
4. Ground

## Wiring

<img src="lecture_dht22.assets/dht22_bb.png" alt="dht22_bb" style="width:500px;" />

## Software Library

* The DHT22 uses a protocol called **1Wire** to send data
* In order to communicate with the device, we will need to use a special library 
* The Argon-compatible library we will use is
  ```PietteTech_DHT```



## Library Setup

```c++
#include "PietteTech_DHT.h"
```



```c++
#define DHTPIN D3		//DHT connected pin
#define DHTTYPE DHT22	//specific DHT model we have
PietteTech_DHT dht(DHTPIN, DHTTYPE); //DHT software object
```

## ```setup()```

```c++
//initialize DHT software object
dht.begin();
```

## Wait for Data and Error Checking

```c++
int result = dht.acquireAndWait(1000);  // wait up to 1 sec
if (result == DHTLIB_OK) {
	//read values here
}
```

## Reading Values

```c++
// Read humidity
float h = dht.getHumidity();
// Read temperature as Celsius
float t = dht.getCelcius();
// Read temperature as Farenheit
float f = dht.getFarenheit();
```

## Other Methods

```c++
float dp = dht.getDewPoint();
float k = dht.getTempKelvin();
```

## Notes

* Always include a delay of about 2.5 seconds in between measurements

## Credit

* [Sparkfun](https://www.sparkfun.com/products/10167)
* Diagrams created with [Frizting](https://fritzing.org)






























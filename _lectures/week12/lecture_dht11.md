---
marp: true
theme: itp

week: 12
category: lectures
title: DHT 11 - Temperature and Humidity Sensor
---

<!-- headingDivider: 2 -->

# DHT 11 - Temperature and Humidity Sensor

 <img src="lecture_dht11.assets/10167-01.jpg" alt="https://cdn.sparkfun.com//assets/parts/4/4/7/2/10167-01.jpg" style="width:800px;" /> 



## Digital Temperature and Humidity Sensor

* DHT 11 (also DHT 22, RHT 03) measure temperature and relative humidity
* Unlike TM36, this has a digital interface and no calculation or conversion is needed

## Wiring Guide

 <img src="lecture_dht11.assets/10167-02_pinout.jpg" alt="Annotated RHT03" style="width:400px;" /> 

1. 3.3V
2. Digital input
3. No connection
4. Ground



## Software Library

* The DHT 11 uses a protocol called **1Wire** to send data
* In order to communicate with the device, we will need to use a special library 
* The Argon-compatible library we will use is
  ```Adafruit_DHT_Particle```



## Library Setup

```c++
#include "Adafruit_DHT_Particle.h"
```



```c++
#define DHTPIN D3		//DHT connected pin
#define DHTTYPE DHT11	//specific DHT model we have
DHT dht(DHTPIN, DHTTYPE);	//DHT software object
```

## ```setup()```

```c++
//initialize DHT software object
dht.begin();
```

## Reading Values

```c++
// Read humidity
float h = dht.getHumidity();
// Read temperature as Celsius
float t = dht.getTempCelcius();
// Read temperature as Farenheit
float f = dht.getTempFarenheit();
```

## Error Checking

```c++
// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t) || isnan(f)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}
```

* ```isnan(X)``` checks if function is a number

## Other Methods

```c++
float hi = dht.getHeatIndex();
float dp = dht.getDewPoint();
float k = dht.getTempKelvin();
```

## Notes

* Always include a delay of about 2 seconds in between measurements

## Credit

* [Sparkfun](https://www.sparkfun.com/products/10167)






























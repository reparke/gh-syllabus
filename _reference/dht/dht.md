---
marp: true
theme: itp

category: reference
title:  DHT - Temperature and Humidity Sensor
show_in_list: true

---



<!-- headingDivider: 2 -->

# DHT - Temperature and Humidity Sensor

<img src="dht.assets/dht22.jpg" alt="DHT 22" style="width:300px;" /> <img src="dht.assets/dht11.png" alt="DHT 11" style="width:300px;" /> 



## Wiring Guide - 4 Pins
![bg right](dht.assets/10167-02_pinout.jpg) 

1. 3.3V
2. Digital input (needs 10k pull-up resistor)
3. No connection
4. Ground


## Wiring Guide - 3 Pins

![bg right](dht.assets/10167-02_pinout_3pin.jpg) 

1. 3.3V
2. Digital input (needs 10k pull-up resistor)
3. Ground
## Wiring Guide

<img src="dht.assets/dht22_bb.png" alt="dht22_bb" style="width:500px;" />

## Operation

- Always wait about 2.5 seconds in between measurements (use `millis` preferably for this instead of `delay`)

### Library

* We need a library to handle much of the complex communication with the OLED 
* To install a library, go to the command palette and type `Install Library`
* Install the OLED library: `PietteTech_DHT`

### Examples

- There are extensive examples in the library folder under `lib/examples`

## Code 

- The following code example will read the temperature and humidity at 2500 millisecond intervals

```c++
#include "PietteTech_DHT.h"

#define DHTTYPE DHT11  // DHT model you have
#define DHTPIN D2      // DHT data pin

PietteTech_DHT dht(DHTPIN, DHTTYPE);

float h;
float c;
float f;

unsigned long prevMillis = 0;
unsigned long updateDelay = 2500;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
    unsigned long currMillis = millis();
    if (currMillis - prevMillis > updateDelay) {
        prevMillis = currMillis;
		
		int result =
			dht.acquireAndWait(1000);  // wait up to 1 sec 
		if (result == DHTLIB_OK) {
		  h = dht.getHumidity();
		  c = dht.getCelsius();
		  f = dht.getFahrenheit();
		  Serial.println("Humidity: " + String(h, 1) + " %");
		  Serial.println("Temp (F): " + String(f, 1) + " deg F");
		  Serial.println("Temp (C): " + String(c, 1) + " deg C");
		} else {
		  Serial.println("Invalid reading");
		}
	}
}


```



## Credit

* [Sparkfun](https://www.sparkfun.com/products/10167)
* Diagrams created with [Frizting](https://fritzing.org)






























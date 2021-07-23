#include "PietteTech_DHT.h"

#define DHTTYPE DHT11  // Sensor type DHT11/21/22/AM2301/AM2302
#define DHTPIN D2      // Digital pin for communications

PietteTech_DHT dht(DHTPIN, DHTTYPE);

float h;
float c;
float f;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
    int result =
        dht.acquireAndWait(1000);  // wait up to 1 sec (default indefinitely)
    if (result == DHTLIB_OK) {
      h = dht.getHumidity();
      c = dht.getCelsius();
      f = dht.getFahrenheit();
      Serial.println("Humidity: " + String(h, 1) + " %");
      Serial.println("Temp (F): " + String(f, 1) + " deg F");
      Serial.println("Temp (C): " + String(c, 1) + " deg C");
      publishEvents();
    } else {
      Serial.println("Invalid reading");
    }
  }
}

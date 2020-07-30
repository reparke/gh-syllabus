#include "PietteTech_DHT.h"

#define DHTTYPE DHT22  // Sensor type DHT11/21/22/AM2301/AM2302
#define DHTPIN D3      // Digital pin for communications

// Lib instantiate
PietteTech_DHT DHT(DHTPIN, DHTTYPE);
unsigned long publishDelayMS = 2000;
unsigned long prevTime = 0;

void setup() {
  Serial.begin(9600);

  Serial.println("DHT Simple program using DHT.acquireAndWait");
  Serial.print("LIB version: ");
  Serial.println(DHTLIB_VERSION);
  Serial.println("---------------");
  DHT.begin();
}
// loop() runs over and over again, as quickly as it can execute.
void loop() {
  unsigned long curTime = millis();
  if (curTime - prevTime > publishDelayMS) {
    prevTime = curTime;

    int dhtResult = DHT.acquireAndWait(1000);
    float c;
    float h;
    float f;
    // int is a response value
    if (dhtResult == DHTLIB_OK) {
      c = DHT.getCelsius();
      f = DHT.getFahrenheit();
      h = DHT.getHumidity();
      Serial.println("Humidity: " + String(h, 1) + " %");
      Serial.println("Temp (F): " + String(f, 1) + " deg F");
      Serial.println("Temp (C): " + String(c, 1) + " deg C");
    } else {
      Serial.println("Invalid reading");
    }
  }
}
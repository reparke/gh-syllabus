#include "PietteTech_DHT.h"

#define DHTTYPE DHT22  // Sensor type DHT11/21/22/AM2301/AM2302
#define DHTPIN D2      // Digital pin for communications

PietteTech_DHT dht(DHTPIN, DHTTYPE);

const int PIN_LED = D7;
const String LIGHT_STRING_VALUES[] = {"dark", "ambient", "bright"};

String lightLevel;

unsigned long publishDelayMS = 2000;
unsigned long prevTime = 0;
float h;
float c;
float f;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
  Particle.function("ledChange", ledChange);
  dht.begin();
}

void loop() {
  unsigned long curTime = millis();
  if (curTime - prevTime > publishDelayMS) {
    prevTime = curTime;
    // f = random(720, 760) / 10.0;  // random temp as double from 72.0 - 76.0
    lightLevel = LIGHT_STRING_VALUES[random(0, 3)];
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

// we will send TEMP:LIGHT
void publishEvents() {
  Particle.publish("readingDHT", String(f, 2) + ":" + lightLevel);
}

int ledChange(String command) {
  if (command.equalsIgnoreCase("blink")) {
    digitalWrite(PIN_LED, HIGH);
    delay(1000);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
    return 0;
  } else {
    return -1;
  }
}
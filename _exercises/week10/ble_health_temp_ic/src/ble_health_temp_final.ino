#include "argon_ble_setup.h"

/*
  CONFIGURATION
  TMP36 Analog voltage connected to Argon
    TMP36 - A3

  PWR - power pin: 1 = USB power; 0 = battery power

*/

const unsigned long UPDATE_INTERVAL = 2000;
float prevTemp = 0;
uint8_t batteryLevel = 0;
unsigned long prevUpdate = 0;

void setup() {
  /* === START BLE SETUP === */
  argon_ble_setup();
  /* === END BLE SETUP === */

  pinMode(A3, INPUT);
  pinMode(PWR, INPUT);

  Serial.begin(9600);
}

void loop() {
  if ((millis() - prevUpdate) >= UPDATE_INTERVAL) {
      prevUpdate = millis();
      prevTemp = getTemp();

    // is the blue tooth connected
    if (BLE.connected()) {

      prevTemp = getTemp();

      update_ble_temperature("f", 6, prevTemp);

      update_ble_battery_level(batteryLevel);
    }
  }
}

float getTemp() {
  float voltage = analogRead(A3) * 3.3 / 4095;
  float cel = (voltage - 0.5) * 100;
  float fahr = (9.0 / 5) * cel + 32;
  return fahr;
}
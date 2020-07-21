#include "argon_ble_setup.h"

/*
  CONFIGURATION
  TMP36 Analog voltage connected to Argon
    TMP36 - A3

  PWR - power pin: 1 = USB power; 0 = battery power

*/

const unsigned long UPDATE_INTERVAL_MS =
    2000;  // delay for update of temperature

unsigned long prevUpdate = 0;  // time of last update in millis()
float prevTempF = -1.0;        // previous temperature in Fahr
uint8_t batteryLevel = -1;     // battery level percentage [0-100]

void setup() {
  /* === START BLE SETUP === */
  argon_ble_setup();
  /* === END BLE SETUP === */

  pinMode(A3, INPUT);
  pinMode(PWR, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (millis() - prevUpdate >= UPDATE_INTERVAL_MS) {
    prevUpdate = millis();

    if (BLE.connected()) {
      prevTempF = getTempF();
      update_ble_temperature("f", 6, prevTempF);

      batteryLevel = getBatteryLevel();
      update_ble_battery_level(batteryLevel);
    }
  }
}

float getTempF() {
  float voltage = analogRead(A3) * 3.3 / 4095;
  float tempC = (voltage - 0.5) * 100;
  float tempF =
      tempC * (9.0 / 5) + 32;  // NOTE: C++ division of ints truncates decimal

  /* === UNCOMMENT FOR DEBUGGING WITHOUT TMP36 === */
  if (rand() > (RAND_MAX / 2)) {
    tempF = 98.7;
  } else {
    tempF = 98.5;
  }
  /* === UNCOMMENT FOR DEBUGGING WITHOUT TMP36 === */

  return tempF;
}

uint8_t getBatteryLevel() {
  // read battery voltage
  // https://docs.particle.io/reference/device-os/firmware/argon/#battery-voltage
  float batteryVoltage = analogRead(BATT) * 0.0011224;
  uint8_t batLevel = -1;
  if (digitalRead(PWR) == 1) {  // PWR == 1 means USB power
    batLevel = 100;
  } else {
    batLevel = batteryVoltage / 3.7 * 100;  // convert battery voltage to %
  }
  return batLevel;
}
#include "argon_ble_setup.h"

/*
  CONFIGURATION
  TMP36 Analog voltage connected to Argon
    TMP36 - A3

  PWR - power pin: 1 = USB power; 0 = battery power

*/

void setup() {
  /* === START BLE SETUP === */
  argon_ble_setup();
  /* === END BLE SETUP === */

  pinMode(A3, INPUT);
  pinMode(PWR, INPUT);

  Serial.begin(9600);
}

void loop() {}

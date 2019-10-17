#include "argon_ble_setup.h"


void setup() {
  /* === START BLE SETUP === */
  argon_ble_setup();
  /* === END BLE SETUP === */

  pinMode(D7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
//BLE - This section needed for communication from Argon to Phone
  if (BLE.connected()) {
        // Serial.println("BT Connected");
    uint8_t txBuf[UART_TX_BUF_SIZE];
    size_t txLen = 0;
    
    //these two lines SEND data from ARGON to PHONE (endlessly show 'f')
    txBuf[0] = 'f'; 
    txLen = 1;

    // Serial.println("Serial available: " + String(Serial.available()) + ", txLen: " + String(txLen));
    // delay(3000);
    while (Serial.available() && txLen < UART_TX_BUF_SIZE) {
      Serial.println("In while");
      txBuf[txLen++] = Serial.read();
      Serial.write(txBuf[txLen - 1]);
    }
    if (txLen > 0) {
      txCharacteristic.setValue(txBuf, txLen);
    }
  }
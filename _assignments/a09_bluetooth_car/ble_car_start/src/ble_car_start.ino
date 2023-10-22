// based on
// https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40

#include "argon_ble_setup.h"
/*
  Use Adafruit Bluefruit app
  (https://learn.adafruit.com/bluefruit-le-connect/controller)
  Connect to Argon -> controller

  CONFIGURATION
  Motor Controller
    PWMA    - D8
    AIN2    - D7
    AIN1    - D6
    BIN1    - D5
    BIN2    - D4
    PWMB    - D3

    VCC     - 3v3
    Standby - 3v3
    VM      - Li+
    Enable  - connect to switch

*/

// SYSTEM_MODE(MANUAL);  /* uncomment to disable wifi and use BT only */

/* onDataReceived()
    Event handler for incoming data via RX characteristic
    When the RXCharacteristic receives data, the event handler is called
    Note: uint8_t is a byte ("unsigned integer of length 8 bits")

    The command scheme is from the Adafruit Bluefruit app
    https://learn.adafruit.com/bluefruit-le-connect/controller

    ex: [‘!’] [‘B’] [‘4’] [‘1’] [CRC]
*/
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
    // bluetoothSerialDebug(data, len); // uncomment for serial monitor debug
}

void setup() {
    argon_ble_setup();

    Serial.begin(9600);  // begin serial communication
}

void loop() {}

/********************************************************************************/

/*
  bluetoothSerialDebug
      used for printing debug info to serial monitor ===
*/
void bluetoothSerialDebug(const uint8_t* data, size_t len) {
    for (size_t index = 0; index < len; index++) {
        Serial.print((char)data[index]);
        Serial.print(" ");
    }
    Serial.println();
}

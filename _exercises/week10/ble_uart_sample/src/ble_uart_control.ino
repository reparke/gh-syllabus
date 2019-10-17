#include "argon_ble_setup.h"

// onDataReceived() is event handler for incoming data via RX characteristic
// When the RXCharacteristic receives data, the event handler is called

/*  Sample Code to communicate from Argon to Adafruit Bluefruit app
  When "1" is pressed down on Bluefruit app, on-board LED D7 will blink twice
  When "UP" is pressed down on Bluefruit app, on-board LED D7 will turn on
  When "UP" is released on Bluefruit app, on-board LED D7 will turn off

  The command scheme is from the Adafruit Bluefruit app
    ex: [‘!’] [‘B’] [‘4’] [‘1’] [CRC]
    https://learn.adafruit.com/bluefruit-le-connect/controller
*/

void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
  /* === START DEBUG PRINTING ===
           uncomment following loop to see commands being sent by app ==
   */
  for (size_t ii = 0; ii < len; ii++) {
    // Serial.write((int) data[ii]);
    Serial.print((int)data[ii]);
    Serial.print(" ");
  }
  Serial.println();
  /* === END DEBUG PRINTING === */

  if (len > 4) {  // make sure there at least four bytes
    if (data[0] == '!' && data[1] == 'B' && data[2] == '1' &&
        data[3] == '1') {  // button 1 pressed -> blink
      digitalWrite(D7, HIGH);
      delay(200);
      digitalWrite(D7, LOW);
      delay(200);
    } else if (data[0] == '!' && data[1] == 'B' && data[2] == '5' &&
               data[3] == '1') {  // button UP pressed -> LED on
      digitalWrite(D7, HIGH);
    } else if (data[0] == '!' && data[1] == 'B' && data[2] == '5' &&
               data[3] == '0') {  // button UP released -> LED off
      digitalWrite(D7, LOW);
    }
  }
}

void setup() {
  /* === START BLE SETUP === */
  argon_ble_setup();
  /* === END BLE SETUP === */

  pinMode(D7, OUTPUT);
  Serial.begin(9600);
}

void loop() {}
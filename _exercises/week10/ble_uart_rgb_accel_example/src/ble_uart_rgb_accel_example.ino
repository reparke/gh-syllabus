#include "Particle.h"

// This example does not require the cloud so you can run it in manual mode or
// normal cloud-connected mode
// SYSTEM_MODE(MANUAL);

const size_t UART_TX_BUF_SIZE = 20;

void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context);

// These UUIDs were defined by Nordic Semiconductor and are now the defacto
// standard for UART-like services over BLE. Many apps support the UUIDs now,
// like the Adafruit Bluefruit app.
const BleUuid serviceUuid("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid rxUuid("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid txUuid("6E400003-B5A3-F393-E0A9-E50E24DCCA9E");

BleCharacteristic txCharacteristic("tx", BleCharacteristicProperty::NOTIFY,
                                   txUuid, serviceUuid);
BleCharacteristic rxCharacteristic("rx",
                                   BleCharacteristicProperty::WRITE_WO_RSP,
                                   rxUuid, serviceUuid, onDataReceived, NULL);

void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
  // Log.trace("Received data from: %02X:%02X:%02X:%02X:%02X:%02X:",
  // peer.address()[0], peer.address()[1], peer.address()[2], peer.address()[3],
  // peer.address()[4], peer.address()[5]);

  for (size_t ii = 0; ii < len; ii++) {
    // Serial.println("LED Data received");
    // Serial.write(data[ii]);
    // Serial.println(data[ii]);
  }
  uint8_t x = *((uint8_t *)(data+2));
  Serial.print("x = " + String(x));
  uint8_t y = *((uint8_t *)(data+3));
  Serial.print(", y = " + String(y));
  uint8_t z = *((uint8_t *)(data+4));
  Serial.println(", z = " + String(z));
}

void setup() {
  Serial.begin(9600);

  BLE.addCharacteristic(txCharacteristic);
  BLE.addCharacteristic(rxCharacteristic);

  BleAdvertisingData data;
  data.appendServiceUUID(serviceUuid);
  BLE.advertise(&data);
}

void loop() {
  if (BLE.connected()) {
    // Serial.println("BLE LED connected");

    uint8_t txBuf[UART_TX_BUF_SIZE];
    size_t txLen = 0;

    while (Serial.available() && txLen < UART_TX_BUF_SIZE) {
      txBuf[txLen++] = Serial.read();
      Serial.write(txBuf[txLen - 1]);
    }
    if (txLen > 0) {
      txCharacteristic.setValue(txBuf, txLen);
    }
  }
}

// // ref: https://github.com/CollinCunningham/BLE_UART_Controller_Test

// #include "argon_ble_setup.h"
// /*
//   Use Adafruit Bluefruit app
//   (https://learn.adafruit.com/bluefruit-le-connect/controller) Connect to
//   Argon
//   -> controller -> enable accelerometer

//   X Y Z acceleration will modulate RGB LED color

//   Uses smoothing filter (average)

//   CONFIGURATION
//   RGB LED (common cathode) connected to Argon
//     R - A2
//     G - A1
//     B - A0

// */

// const int AVERAGING_LENGTH = 2;  // smoothing

// float phoneAccel[3][AVERAGING_LENGTH];  // x, y, z with averaging of 20
// int rgb[3];                             // r, g, b

// void setup() {
//   /* === START BLE SETUP === */
//   argon_ble_setup();
//   /* === END BLE SETUP === */

//   pinMode(D7, OUTPUT);
//   pinMode(A0, OUTPUT);
//   pinMode(A1, OUTPUT);
//   pinMode(A2, OUTPUT);
//   Serial.begin(9600);
// }

// const unsigned long UPDATE_INTERVAL_MS =
//     100;                       // delay for update of temperature
// unsigned long prevUpdate = 0;  // time of last update in millis()
// int curIndex = 0;

// void loop() {
//   if (millis() - prevUpdate >= UPDATE_INTERVAL_MS) {
//     prevUpdate = millis();

//     updateRgbValues();
//     changeRgbLight(rgb[0], rgb[1], rgb[2]);

//     /* === DEBUG PRINTING === */
//     Serial.print("(r,g,b): (" + String(rgb[0]) + ", " + String(rgb[1]) + ", "
//     +
//                  String(rgb[2]) + ")");
//     Serial.println(" -- (x,y,z): (" + String(phoneAccel[0][0],2) + ", " +
//                    String(phoneAccel[1][0],2) + ", " +
//                    String(phoneAccel[2][0],2) +
//                    ")");
//   }
// }

// void updateRgbValues() {
//   float x = avg(phoneAccel[0]);
//   float y = avg(phoneAccel[1]);
//   float z = avg(phoneAccel[2]);
//   rgb[0] = (x - (-1)) * (float)(255 - 0) / (1 - (-1)) + 0;
//   rgb[1] = (y - (-1)) * (float)(255 - 0) / (1 - (-1)) + 0;
//   rgb[2] = (z - (-1)) * (float)(255 - 0) / (1 - (-1)) + 0;
// }

// float avg(const float *accel) {
//   float sum = 0;
//   for (int i = 0; i < AVERAGING_LENGTH; i++) {
//     sum += accel[i];
//   }
//   return sum / AVERAGING_LENGTH;
// }

// // void changeRgbLight(uint8_t r, uint8_t g, uint8_t b) {
// void changeRgbLight(int r, int g, int b) {
//   analogWrite(A2, r);
//   analogWrite(A1, g);
//   analogWrite(A0, b);
// }

// // onDataReceived() is event handler for incoming data via RX characteristic
// // When the RXCharacteristic receives data, the event handler is called

// // Note: uint8_t is a byte ("unsigned integer of length 8 bits")
// void onDataReceived(const uint8_t *buffer, size_t len,
//                     const BlePeerDevice &peer, void *context) {
//   /* === START DEBUG PRINTING ===
//            uncomment following loop to see commands being sent by app ==
//    */
//   // for (size_t ii = 0; ii < len; ii++) {
//   //   Serial.print(buffer[ii]);
//   //   Serial.print(" ");
//   // }
//   // Serial.println();
//   // for (size_t ii = 0; ii < len; ii++) {
//   //   Serial.write(buffer[ii]);
//   //   Serial.print(" ");
//   // }
//   // Serial.println();
//   /* === END DEBUG PRINTING === */

//   //  char pfx[2] = { (char)buffer[0], (char)buffer[1] };
//   if ((char)buffer[0] == '!') {  // Sensor data flag
//     switch ((char)buffer[1]) {
//       case 'Q':
//         if (checkCRC(buffer) == false) {
//           break;
//         }
//         Serial.println("Quaternion Data:");
//         printQuaternionData(buffer);
//         break;
//       case 'A':
//         if (checkCRC(buffer) == false) {
//           break;
//         }
//         // Serial.println("Accelerometer Data:");
//         // printSensorDataXYZ(buffer);
//         updateSensorDataXYZ(buffer);
//         break;
//       case 'G':
//         if (checkCRC(buffer) == false) {
//           break;
//         }
//         Serial.println("Gyro Data:");
//         printSensorDataXYZ(buffer);
//         break;
//       case 'M':
//         if (checkCRC(buffer) == false) {
//           break;
//         }
//         Serial.println("Magnetometer Data:");
//         printSensorDataXYZ(buffer);
//         break;
//       case 'L':
//         if (checkCRC(buffer) == false) {
//           break;
//         }
//         Serial.println("Location Data:");
//         printLocationData(buffer);
//         break;
//       case 'B':
//         if (checkCRC(buffer) == false) {
//           break;
//         }
//         Serial.print("Button ");
//         Serial.print((char)buffer[2]);
//         Serial.print(" ");
//         printButtonState((char)buffer[3]);
//         break;
//       case 'C':
//         if (checkCRC(buffer) == false) {
//           break;
//         }
//         Serial.println("Color ");
//         printColorData(buffer);
//         break;
//       default:
//         Serial.println("Unknown Data Type");
//         break;
//     }
//     // Serial.println("");
//   }
// }

// // ================ ADAFRUIT ==============

// void printSensorDataXYZ(const uint8_t *buffer) {
//   float x = *((float *)(buffer + 2));
//   Serial.print("x = ");
//   Serial.println(x, 7);

//   float y = *((float *)(buffer + 6));
//   Serial.print("y = ");
//   Serial.println(y, 7);

//   float z = *((float *)(buffer + 10));
//   Serial.print("z = ");
//   Serial.println(z, 7);
// }
// void updateSensorDataXYZ(const uint8_t *buffer) {
//   float x = *((float *)(buffer + 2));

//   float y = *((float *)(buffer + 6));

//   float z = *((float *)(buffer + 10));

//   phoneAccel[0][curIndex] = x;
//   phoneAccel[1][curIndex] = y;
//   phoneAccel[2][curIndex] = z;

//   curIndex++;
//   if (curIndex >= AVERAGING_LENGTH) {
//     curIndex = 0;
//   }
// }

// void printLocationData(const uint8_t *buffer) {
//   float x = *((float *)(buffer + 2));
//   Serial.print("lat = ");
//   Serial.println(x, 7);

//   float y = *((float *)(buffer + 6));
//   Serial.print("lng = ");
//   Serial.println(y, 7);

//   float z = *((float *)(buffer + 10));
//   Serial.print("alt = ");
//   Serial.println(z, 7);
// }

// void printColorData(const uint8_t *buffer) {
//   byte r = *(buffer + 2);
//   Serial.print("r = ");
//   Serial.println(r, DEC);

//   byte g = *(buffer + 3);
//   Serial.print("g = ");
//   Serial.println(g, DEC);

//   byte b = *(buffer + 4);
//   Serial.print("b = ");
//   Serial.println(b, DEC);
// }

// void printQuaternionData(const uint8_t *buffer) {
//   float x = *((float *)(buffer + 2));
//   Serial.print("x = ");
//   Serial.println(x, 7);

//   float y = *((float *)(buffer + 6));
//   Serial.print("y = ");
//   Serial.println(y, 7);

//   float z = *((float *)(buffer + 10));
//   Serial.print("z = ");
//   Serial.println(z, 7);

//   float w = *((float *)(buffer + 14));
//   Serial.print("w = ");
//   Serial.println(w, 7);
// }

// void printButtonState(char buttonState) {
//   if (buttonState == '0') {
//     Serial.println("released");
//   } else if (buttonState == '1') {
//     Serial.println("pressed");
//   } else {
//     Serial.println("unknown state");
//   }
// }

// /*RP 10/17/19
// After porting from Arduino to Argon, this CRC check always fails even
// the reported values are correct.
// This function could be error-check and re-enabled */
// boolean checkCRC(const uint8_t *buffer) {
//   //   uint8_t len = sizeof(buffer);
//   //   uint8_t crc = buffer[len - 2];
//   //   uint8_t sum = 0;

//   //   for (int i = 0; i < (len - 1); i++) {
//   //     sum += buffer[i];
//   //   }

//   //   Serial.print("CRC ");

//   //   if ((crc & ~sum) == 0) {
//   //     Serial.println("PASS");
//   //     return true;
//   //   }

//   //   else {
//   //     Serial.println("FAIL");
//   //     return false;
//   //   }
//   return true;
// }

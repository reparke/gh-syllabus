#include "Particle.h"
/* === START BLE SETUP === */


/*  1) ADD BLUETOOTH SERVICES ===============================
  see https://www.bluetooth.com/specifications/gatt/services/
  ===========================================================    
*/

// The "Health Thermometer" service is 0x1809.
// See https://www.bluetooth.com/specifications/gatt/services/
BleUuid healthThermometerService(0x1809);


/*  2) ADD BLUETOOTH CHARACTERISTICS================================
  see https://www.bluetooth.com/specifications/gatt/characteristics/
  ==================================================================
*/


// The temperature-measurement is 16-bit UUID 0x2A1C
BleCharacteristic temperatureMeasurementCharacteristic(
    "temp", BleCharacteristicProperty::NOTIFY, BleUuid(0x2A1C),
    healthThermometerService);

/* ================== */

// set max buffer size
const size_t UART_TX_BUF_SIZE = 20;

// These UUIDs are standard for serial / UART over BLE
// Supported by many mobiles apps including Adafruit Bluefruit app

// service UUID is used for the peripheral device to advertise it supports UART
const BleUuid serviceUuid("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");

// RX and TX characteristics necessary for serial UART communicaiton
const BleUuid rxUuid("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid txUuid("6E400003-B5A3-F393-E0A9-E50E24DCCA9E");

// onDataReceived() is event handler for incoming data via RX characteristic
// When the RXCharacteristic receives data, the event handler is called

void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context);

// create BLE TX characteristic object
BleCharacteristic txCharacteristic("tx", BleCharacteristicProperty::NOTIFY,
                                   txUuid, serviceUuid);

// create BLE RX characteristic object; connect to onDataReceived handler
BleCharacteristic rxCharacteristic("rx",
                                   BleCharacteristicProperty::WRITE_WO_RSP,
                                   rxUuid, serviceUuid, onDataReceived, NULL);

// call this function from within SETUP
void argon_ble_setup() {
  BLE.addCharacteristic(txCharacteristic);
  BLE.addCharacteristic(rxCharacteristic);

  BleAdvertisingData data;              // build peripheral's advertising data
  data.appendServiceUUID(serviceUuid);  // advertise serial / UART service
  data.appendLocalName("dev1");  // include custom name visible in mobile app
  BLE.advertise(&data);          // advertise to mobile app (central device)
}
// ref:
// https://docs.particle.io/tutorials/device-os/bluetooth-le/#body-temperature-thermometer

#include "Particle.h"

const String DEVICE_NAME = "dev1";  // CHANGE THIS

/*
1) ADD BLUETOOTH SERVICES ===============================
  see https://www.bluetooth.com/specifications/gatt/services/
  ===========================================================
*/
// The "Health Thermometer" service is 0x1809
BleUuid healthThermometerService(0x1809);

// The "Battery Service" service is 0x180F
BleUuid batteryLevelService(0x180F);

/*
2) ADD BLUETOOTH CHARACTERISTICS====================================
  see https://www.bluetooth.com/specifications/gatt/characteristics/
  ==================================================================
*/
// The temperature-measurement is UUID 0x2A1C
BleCharacteristic temperatureMeasurementCharacteristic(
    "temp", BleCharacteristicProperty::NOTIFY, BleUuid( ),
    healthThermometerService);

// The battery_level characteristic is UUID 0x2A19
// Shows the battery level to be monitored
BleCharacteristic batteryLevelCharacteristic("bat",
                                             BleCharacteristicProperty::NOTIFY,
                                             BleUuid(0x2A19),
                                             batteryLevelService);

/*
3) Functions ====================================
   ==================================================================
*/

/*   ========== fn: argon_ble_setup ==========
    description: setup for temperature and battery service to argon over BLE
        call this from setup()
    input: none
    output: none
    side-effect: none
*/
void argon_ble_setup() {
  BLE.addCharacteristic(temperatureMeasurementCharacteristic);

  BLE.addCharacteristic(batteryLevelCharacteristic);

  BleAdvertisingData data;  // build peripheral's advertising data
  data.appendServiceUUID(healthThermometerService);  // advertise thermometer
  data.appendLocalName(
      DEVICE_NAME);      // include custom name visible in mobile app
  BLE.advertise(&data);  // advertise to mobile app (central device)
}

/*   ========== fn: ieee11073_from_float ==========
    description: converts float into 32bit int-represented floating point number
        This code is from the ARM mbed temperature demo:
        https://github.com/ARMmbed/ble/blob/master/ble/services/HealthThermometerService.h
        only works for positive values of temperature, but fine for the health
   thermometer input: float point number output: uint32_t int-represented
   floating point number side-effect: none
*/
uint32_t ieee11073_from_float(float temperature) {
  uint8_t exponent = 0xFE;  // Exponent is -2
  uint32_t mantissa = (uint32_t)(temperature * 100);

  return (((uint32_t)exponent) << 24) | mantissa;
}

/*  ========== fn: update_ble_temperature ==========
    description: sends a temperature to argon over BLE
        The Temperature Measurement characteristic data is defined here:
        https://www.bluetooth.com/wp-content/uploads/Sitecore-Media-Library/Gatt/Xml/Characteristics/org.bluetooth.characteristic.temperature_measurement.xml
    input:
        String tempMeasure: "f" for fahr, or "c" for celsius
        int tempType:
            1 - Armpit
            2 - Body (general)"
            3 - Ear
            4 - Finger
            5 - Gastro-intestinal Tract
            6 - Mouth
            7 - Rectum
            8 - Toe
            9 - Tympanum (ear drum)
        float temp: temperature
    output: none
    side-effect: none
*/
void update_ble_temperature(String tempMeasure, int tempType, float temp) {
  uint8_t buf[6];

  if (tempMeasure.equalsIgnoreCase("c")) {
    // First byte is flags. We're using Fahrenheit (bit 0b001 == 1), no
    // timestamp (bit 0b010 == 0), with temperature type (bit 0b100 = 0), so
    // the flags are so 0b00000100 = 0x04.
    buf[0] = 0x04;
  } else {  // Fahrenheit
    // First byte is flags. We're using Fahrenheit (bit 0b001 == 1), no
    // timestamp (bit 0b010 == 0), with temperature type (bit 0b100 = 1), so
    // the flags are so 0b00000101 = 0x05.
    buf[0] = 0x05;
  }

  uint32_t value = ieee11073_from_float(temp);  // ieee11073 floating point num
  memcpy(&buf[1], &value, 4);

  buf[5] = tempType;

  temperatureMeasurementCharacteristic.setValue(buf, sizeof(buf));
}

/*   ========== fn: update_ble_battery_level ==========
    input:
        uint8_t batteryLevel: battery level 0-100
    output: none
    side-effect: none
*/
void update_ble_battery_level(uint8_t batteryLevel) {
  batteryLevelCharacteristic.setValue(&batteryLevel, 1);
}
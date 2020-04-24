// FILE:        PietteTech_DHT.h
// VERSION:     0.0.12
// PURPOSE:     Particle Interrupt driven lib for DHT sensors
// LICENSE:     GPL v3 (http://www.gnu.org/licenses/gpl.html)
// 
// S Piette (Piette Technologies) scott.piette@gmail.com
//      January 2014        Original Spark Port
//      October 2014        Added support for DHT21/22 sensors
//                          Improved timing, moved FP math out of ISR
//      September 2016      Updated for Particle and removed dependency
//                          on callback_wrapper.  Use of callback_wrapper
//                          is still for backward compatibility but not used
// ScruffR
//      February 2017       Migrated for Libraries 2.0
//                          Fixed blocking acquireAndWait()
//                          and previously ignored timeout setting
//      January  2019       Updated timing for Particle Mesh devices
//                          issue: https://github.com/particle-iot/device-os/issues/1654
//      November 2019       Incorporate workaround for SOS+14 bug
//                          https://github.com/eliteio/PietteTech_DHT/issues/1
// 
// Based on adaptation by niesteszeck (github/niesteszeck)
// Based on original DHT11 library (http://playgroudn.adruino.cc/Main/DHT11Lib)
// 
// With this library connect the DHT sensor to the interrupt enabled pins
// See docs for more background
//   https://docs.particle.io/reference/firmware/photon/#attachinterrupt-

#include "PietteTech_DHT.h"  

 // system defines
#define DHTTYPE  DHT22              // Sensor type DHT11/21/22/AM2301/AM2302
#define DHTVcc   D2                 // Digital pin to power the sensor
#define DHTPIN   D3                 // Digital pin for communications
#define DHTGnd   D4                 // Digital pin for sensor GND
#define DHT_SAMPLE_INTERVAL   2000  // Sample every two seconds

SerialLogHandler logger(LOG_LEVEL_ERROR, {{ "app", LOG_LEVEL_TRACE }});

// 
// NOTE: Use of callback_wrapper has been deprecated but left in this example
//       to confirm backwards compabibility.  Look at DHT_2sensor for how
//       to write code without the callback_wrapper
// 

void dht_wrapper();                 // must be declared before the lib initialization
PietteTech_DHT DHT(DHTPIN, DHTTYPE, dht_wrapper);
void dht_wrapper() {
  DHT.isrCallback();
}

bool bDHTstarted;		                // flag to indicate we started acquisition
int n;                              // counter

void setup()
{
  Serial.begin(115200);

  pinMode(DHTGnd, OUTPUT);
  pinResetFast(DHTGnd);
  pinMode(DHTVcc, OUTPUT);
  pinSetFast(DHTVcc);
  
  delay(100);

  Serial.println("DHT Simple program using DHT.acquire");
  Serial.printlnf("LIB version: %s", (const char*)DHTLIB_VERSION);
  Serial.println("---------------");

  DHT.begin();
}

void loop()
{
  static uint32_t msLastSample = 0;
  if (millis() - msLastSample <  DHT_SAMPLE_INTERVAL) return;

  if (!bDHTstarted) {               // start the sample
    Serial.printlnf("\r\n%d: Retrieving information from sensor: ", n);
    DHT.acquire();
    bDHTstarted = true;
  }

  if (!DHT.acquiring()) {           // has sample completed?
    int result = DHT.getStatus();

    Serial.print("Read sensor: ");
    switch (result) {
      case DHTLIB_OK:
        Serial.println("OK");
        break;
      case DHTLIB_ERROR_CHECKSUM:
        Serial.println("Error\n\r\tChecksum error");
        break;
      case DHTLIB_ERROR_ISR_TIMEOUT:
        Serial.println("Error\n\r\tISR time out error");
        break;
      case DHTLIB_ERROR_RESPONSE_TIMEOUT:
        Serial.println("Error\n\r\tResponse time out error");
        break;
      case DHTLIB_ERROR_DATA_TIMEOUT:
        Serial.println("Error\n\r\tData time out error");
        break;
      case DHTLIB_ERROR_ACQUIRING:
        Serial.println("Error\n\r\tAcquiring");
        break;
      case DHTLIB_ERROR_DELTA:
        Serial.println("Error\n\r\tDelta time to small");
        break;
      case DHTLIB_ERROR_NOTSTARTED:
        Serial.println("Error\n\r\tNot started");
        break;
      default:
        Serial.println("Unknown error");
        break;
    }

    Serial.printlnf("Humidity (%): %.2f", DHT.getHumidity());
    Serial.printlnf("Temperature (oC): %.2f", DHT.getCelsius());
    Serial.printlnf("Temperature (oF): %.2f", DHT.getFahrenheit());
    Serial.printlnf("Temperature (K): %.2f", DHT.getKelvin());
    Serial.printlnf("Dew Point (oC): %.2f", DHT.getDewPoint());
    Serial.printlnf("Dew Point Slow (oC): %.2f", DHT.getDewPointSlow());

    n++;  
    bDHTstarted = false;  // reset the sample flag so we can take another
    msLastSample = millis();
  }
}

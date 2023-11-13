/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

const int pulseSignalPin = A4;

#include <PulseSensorAmped.h>

void setup() {
    // initialize serial communication at 9600 bits per second:
    // hack / workaround until this library is updated
    analogRead(pulseSignalPin);

    Serial.begin(9600);
    Serial.println("Starting");
    PulseSensorAmped.attach(pulseSignalPin);
    PulseSensorAmped.start();
}

void loop() {
    delay(100);
    // Must process Pulse Sensor updates in main event loop
    PulseSensorAmped.process();
}

// An optional function to recieve the Beats Per Minute (BPM) and Interbeat
// Interval (IBI) in mS
void PulseSensorAmped_data(int BPM, int IBI) {
    Serial.print("BPM:");
    Serial.print(BPM);
    Serial.print(" IBI: ");
    Serial.println(IBI);
}

// An optional function to indicate that the pulse signal has been lost
// (Due to the nature of pulse detection via reflected light, spurios signals
// are possible.
//  i.e. received data may not be valid)
void PulseSensorAmped_lost(void) { Serial.println("Pulse Lost"); }

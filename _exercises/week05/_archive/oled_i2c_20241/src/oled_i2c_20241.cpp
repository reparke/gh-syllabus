#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler(LOG_LEVEL_WARN);
#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "math.h"

MicroOLED oled(MODE_I2C, 9, 1);  // Example I2C declaration RST=D7, DC=LOW (0)

void setup() {
    Serial.begin(9600);
    oled.begin();     // Initialize the OLED
    oled.clear(ALL);  // Clear the display's internal memory
    oled.display();   // Display what's in the buffer (splashscreen)
    delay(1000);      // Delay 1000 ms
    randomSeed(analogRead(A0) + analogRead(A1));
}

void loop() {
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.println("hello");
    Serial.println("In loop");
    oled.display();
}
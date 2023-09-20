#include "SparkFunMicroOLED.h"  // Include MicroOLED library

/*  Wiring

  OLED
  ----
    MicroOLED -------------  Argon
      GND ------------------- GND
      VDD ------------------- 3.3V (VCC)
      SDA ------------------- SDA
      SCL ------------------- SCL

  Button
  ------
Pin D2 (pullup)

*/
//#define PIN_OLED_RST D6  // Connect RST to pin 6
//#define PIN_OLED_DC D5   // Connect DC to pin 5 (required for SPI)
//#define PIN_OLED_CS D4   // Connect CS to pin A2 (required for SPI)
//MicroOLED oled(MODE_SPI, PIN_OLED_RST, PIN_OLED_DC, PIN_OLED_CS);

MicroOLED oled(MODE_I2C, 9, 1);  // Example I2C declaration RST=D7, DC=LOW
// (0)

const int PIN_BUTTON = D2;
const int PIN_POT0 = A0;
const int PIN_POT1 = A1;
int buttonVal;

int xPos = 0;
int yPos = 0;

const int X_MAX = oled.getLCDWidth();
const int Y_MAX = oled.getLCDHeight();

void setup() {
    Serial.begin(9600);  // begin serial communication with the computer
    oled.begin();        // Initialize the OLED
    oled.clear(ALL);     // Clear the display's internal memory
    oled.display();      // Display what's in the buffer (splashscreen)
    delay(1000);         // Delay 1000 ms
    oled.clear(PAGE);

    // delay(1000);         // Delay 1000 ms

    xPos = oled.getLCDWidth() / 2;
    yPos = oled.getLCDHeight() / 2;
    Serial.println("x MAX = " + String(X_MAX) + ", y MAX = " + String(Y_MAX));

    pinMode(PIN_BUTTON, INPUT);
}

void loop() {
    int xValue = analogRead(PIN_POT0);
    int yValue = analogRead(PIN_POT1);
    xPos = map(xValue, 0, 4095, 0, X_MAX);
    yPos = map(yValue, 0, 4095, 0, Y_MAX);
    // Serial.print("(x val, y value) = (" + String(xValue) + "," + String(yValue)
    // +
    //              ")");
    // Serial.println("\t(x pos, y pos) = (" + String(xPos) + "," + String(yPos) +
    //                ")");

    //  keep from going off screen
    if (xPos > X_MAX) {
        xPos = X_MAX;
    }
    if (xPos < 0) {
        xPos = 0;
    }
    if (yPos > Y_MAX) {
        yPos = Y_MAX;
    }
    if (yPos < 0) {
        yPos = 0;
    }
    oled.pixel(xPos, yPos);
    oled.display();

    // reset
    buttonVal = digitalRead(PIN_BUTTON);
    if (buttonVal == LOW) {
        Serial.println("=== button click - RESET");
        oled.clear(PAGE);
    }
}
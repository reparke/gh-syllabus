/*  Wiring

  OLED
  ----
      MicroOLED ------------- Argon
        GND ------------------- GND
        3.3 ------------------- 3.3V (VCC)
      D1/MOSI ----------------- MO (don't change)
      D0/SCK ------------------ SCK (don't change)
        D2  ------------------- unused
        D/C ------------------- D5 (can be any digital pin)
		RST ------------------- D6 (can be any digital pin)
		CS  ------------------- D4 (can be any digital pin)
  Button
  ------
Pin D2 (pullup)

  gnd
  3v3
  d1
  sck
  d2
  d/c
  rst
  cs
*/
#include "SparkFunMicroOLED.h"  // Include MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_OLED_RST D6  // Connect RST to pin 6
#define PIN_OLED_DC D5   // Connect DC to pin 5 (required for SPI)
#define PIN_OLED_CS D4   // Connect CS to pin A2 (required for SPI)
MicroOLED oled(MODE_SPI, PIN_OLED_RST, PIN_OLED_DC, PIN_OLED_CS);

// SYSTEM_MODE(MANUAL);

void setup() {
  Serial.begin(9600);  // begin serial communication with the computer
  oled.begin();        // Initialize the OLED
  oled.clear(ALL);     // Clear the display's internal memory
  oled.display();      // Display what's in the buffer (splashscreen)
  delay(1000);         // Delay 1000 ms
}

/********************************************************************************/
void loop() {
  Serial.println("Looping Test");
  oled.clear(PAGE);      // Clear the display
  oled.setFontType(1);   // Switch to the large-number font
  oled.setCursor(0, 0);  // Set the cursor to top-left
  oled.print("Hi world!");
  oled.display();  // Update the display

  delay(4000);
  Serial.println("--Starting code that works--");
  // Demonstrate font 1. 8x16. Let's use the print function
  // to display every character defined in this font.
  oled.setFontType(1);   // Set font to type 1
  oled.clear(PAGE);      // Clear the page
  oled.setCursor(0, 0);  // Set cursor to top-left
  // Print can be used to print a string to the screen:
  oled.print(" !\"#$%&'()*+,-./01234");
  oled.display();  // Refresh the display
  delay(1000);     // Delay a second and repeat
  oled.clear(PAGE);
  oled.setCursor(0, 0);
  oled.print("56789:;<=>?@ABCDEFGHI");
  oled.display();
  delay(1000);
  oled.clear(PAGE);
  oled.setCursor(0, 0);
  oled.print("JKLMNOPQRSTUVWXYZ[\\]^");
  oled.display();
  delay(1000);
  oled.clear(PAGE);
  oled.setCursor(0, 0);
  oled.print("_`abcdefghijklmnopqrs");
  oled.display();
  delay(1000);
  oled.clear(PAGE);
  oled.setCursor(0, 0);
  oled.print("tuvwxyz{|}~");
  oled.display();
  delay(1000);
}
// Global constant
const int PIN_LED = D2;

// global variable
int brightness = 0;
bool isIncreasing = true;

// many of our variables will be created globally

// setup() runs once, when the device is first turned on.
void setup() {
    pinMode(PIN_LED, OUTPUT);
    // set up serial monitor
    Serial.begin(9600);
}

void loop() {
    // brightness goes from 0 - 255
    for (int level = 0; level <= 255; level++) {
        analogWrite(PIN_LED, level);
        delay(5);
    }
    for (int level = 255; level >= 0; level) {
        analogWrite(PIN_LED, level);
        delay(5);
    }
}

// void loop() {
//   Serial.println("Brightness level: " + String(brightness));
//   analogWrite(PIN_LED, brightness);
//   if (isIncreasing == true) {   //we should be increasing the value
//       brightness = brightness + 1;
//   }
//   else {
//     brightness = brightness - 1;  //decreasing
//   }
//   if (brightness > 255) {
//     isIncreasing = false;
//   }
//   if (brightness < 0) {
//     isIncreasing = true;
//   }
//   delay(50);
// }

/* variable scope
  ----------------
  Where a variable exists (in which parts of the code can you access)
*/

// increase the brightness from 0 to 255 slowly, and then set back to 0
// use the loop() function, without while or for

/*
  1 - use "counter" variable to adjust brightness during each loop
  2 - for loop to adjust the brightness
  3 - use a while loop (TRY HARD TO AVOID THIS)

  4 - use the clock timer
*/
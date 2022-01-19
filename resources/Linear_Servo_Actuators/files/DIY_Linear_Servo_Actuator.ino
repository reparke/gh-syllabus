/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop() {
    myservo.write(180);              // 180 tells the continuous rotation servo (CRS) to move forward  
    delay(800);                       // waits X ms for the servo to reach the desired position
    myservo.write(90);              // 90 tells the CRS to stop (use potentiometer on servo to tune to full stop if there is jitter)

    delay(500);                     // Arbitrary wait time before moving actuator backward

    myservo.write(0);              // 0 tells the continuous rotation servo (CRS) to move backward
    delay(800);                       // waits X ms for the servo to reach the original position
    myservo.write(90); 

    // To loop only once.  Use push button on Uno to trigger sketch again.
    while(1){}

}


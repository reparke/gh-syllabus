/*
 * Created by Ray Kim (USC)
 * modified by Rob Parke
 */
/*
| Motor Controller | Argon |
| ---------------- | ----- |
| PWMA             | D5    |
| AIN2             | D4    |
| AIN1             | D3    |
| VCC              | 3v3   |
| GND              | GND   |
| VM               | 3v3   |
| STBY             | 3v3   |
*/

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int PIN_SERVO = D2;
int pos = 0;  // variable to store the servo position

const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(PIN_SERVO, OUTPUT);
  myservo.attach(PIN_SERVO);  // attaches the servo on pin 9 to the servo object
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  // set the direction one HIGH, one LOW
  // digitalWrite(AIN1, HIGH);
  // digitalWrite(AIN2, LOW);
  // analogWrite(PWMA, 255);  // full speed one way
  // delay(1000);             // run for 1 second

  // analogWrite(PWMA, 0);  // stop
  delay(1000);

  // change direction
  // digitalWrite(AIN1, LOW);
  // digitalWrite(AIN2, HIGH);
  // analogWrite(PWMA, 255);  // full speed opposite way
  // delay(1000);

  // analogWrite(PWMA, 0);  // stop
  // delay(1000);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 255);  // full speed opposite way


  for (pos = 15; pos <= 165; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15ms for the servo to reach the position
  }
  for (pos = 165; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15ms for the servo to reach the position
  }
}
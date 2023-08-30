
// Turn on LED

//step 1: we create a pin label
//create a global variable--var declared outside of functions
const int PIN_LED1 = D2;
const int PIN_LED2 = D5;

//often (not always) we define some variables GLOBALLY 
//    at the top of the file OUTSIDE any functions

int pwmValue = 0;

//any variable you define in setup() or loop() is a LOCAL VARIABLE
void setup() {
  //pinModes always goes in setup()

//step 2: declare pin mode
  pinMode(PIN_LED1, OUTPUT);    //other option: INPUT which we use for buttons, pots
  pinMode(PIN_LED2, OUTPUT);


}

void loop() {
    // digitalWrite(PIN_LED1, HIGH);  //other option: LOW = GND; HIGH = 3.3v
    // digitalWrite(PIN_LED2, LOW);
    // delay(1000);  // "pause" for 1000 ms (or 1 sec)
    // digitalWrite(PIN_LED1, LOW);
    // digitalWrite(PIN_LED2, HIGH);
    // delay(250);

  //now--add second LED that is on when the first is off, and vice versa


  //digitalWrite(D4, HIGH) means put 3.3v on D4 forever
  //analogWrite(D4, 127)   put 3.3v on D4 for half the time, and then 0v for the other half, cycle again

  // analogWrite(PIN_LED2, 0);   //off
  // delay(500);
  // analogWrite(PIN_LED2, 63);    //63 is 25% of 255
  // delay(500);
  // analogWrite(PIN_LED2, 127);
  // delay(500);
  // analogWrite(PIN_LED2, 189);    //189 is 75% of 255
  // delay(500);
  // analogWrite(PIN_LED2, 255);    //255 is our MAX PWM value
  // delay(500);


  // to get the LED To gradually increase brightness
  //1 for loop
  //2 increase value each tiem

  // let's never EVER use while loops in this class

  analogWrite(PIN_LED1, pwmValue);
  pwmValue = pwmValue + 10;
  delay(100);

  if (pwmValue >= 255) {
    pwmValue = 0;
  }

/* A DIFFERENT WAY TO INCREASE USING A FOR LOOP */

  //in C++, a for loop is built differently than python
  // think of a for loop in c++ as a"range-based forloop"

  for (int val = 0; val <= 255; val = val + 10) {
    analogWrite(PIN_LED1, val);
    delay(100);
  }
 for (int val = 255; val >= 0; val = val - 5) {
   analogWrite(PIN_LED, val);
   delay(100);
}

}
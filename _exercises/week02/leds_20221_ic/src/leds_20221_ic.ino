SYSTEM_MODE(MANUAL);
/*
  typical: python, matlab, c++
  main()  - starts at main, runs, and then stop at the end of main

  microcontrollers are different
    setup runs once when devices turns on

    loop is an infinite loop that runs forever
*/

//refer to pins with int constants
const int PIN_LED = D2;   
const int PIN_LED2 = D3;

void setup() {
  //runs once
  //initialize my pins (are they input or output?)
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  //when we send a high voltage(3.3v), LED turns on
  //when we send 0v, LED turns off
  //blink example
  // digitalWrite(PIN_LED, HIGH);
  // digitalWrite(PIN_LED2, LOW);
  // delay(500); //pause the program for 500 ms (half a sec)
  // digitalWrite(PIN_LED, LOW);
  // digitalWrite(PIN_LED2, HIGH);
  // delay(500);

  //to vary LED brightness, use analog write
  analogWrite(PIN_LED, 255);
  analogWrite(PIN_LED2, 50);

}
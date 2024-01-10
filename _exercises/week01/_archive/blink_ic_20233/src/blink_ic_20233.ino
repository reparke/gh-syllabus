
// comments
/* stuff

*/

// good style and practice

// create labels for our pins by declaring const
// step 1:
const int PIN_LED1 = D7;
const int PIN_LED2 = D3;

int pwmValue = 0;

void setup() {
    // every time we use a pin, we need to set the pin mode
    // step 2: pin mode
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
}

void loop() {  // runs forever
    // turn on LED1 and off LED2
     digitalWrite(PIN_LED1, HIGH);
     digitalWrite(PIN_LED2, LOW);
     delay(1000); //"pause" for X milliseconds (1000 ms = 1 sec)
     digitalWrite(PIN_LED1, LOW);  // 0v aka turn off
     digitalWrite(PIN_LED2, HIGH);
     delay(500);

    // now use PWM
    // digitalWrite(PIN_LED1, HIGH);

    // analogWrite(PIN_LED2, 255);     //255 means MAX 3.3v
    // delay(1000);
    // analogWrite(PIN_LED2, 127);   //127 is half bright or 1.67v
    // delay(1000);
    // analogWrite(PIN_LED2, 0);
    // delay(1000);

    // we're going to make a value for PWM, and increase everytime through the
    // loop int pwmValue = 0;   //this doesn't work because the variable gets
    // reset to 0 each looop
    // solution: create a global variable
    // analogWrite(PIN_LED2, pwmValue);
    // delay(1000);
    // pwmValue = pwmValue + 20; //20 is a arbitrary amount to increase

    // // //problem 2: pwmValue will increase beyond 255

    // if (pwmValue >= 255) {
    //     pwmValue = 0;  // reset
    // }

    // for (int led1PWM = 0; led1PWM <= 255; led1PWM = led1PWM + 5) {
    //     analogWrite(PIN_LED1, led1PWM);
    //     delay(10);
    // }
}
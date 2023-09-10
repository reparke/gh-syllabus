/*
  - configure device
  - global pins
  - setup pin modes
  - begin serial
*/

/* using functions:

  step 1) define the function -
  step 2) execute the function
*/

const int PIN_BUTTON = D5;
const int PIN_RGB_R = D2;
const int PIN_RGB_G = D3;
const int PIN_RGB_B = D4;
const int PIN_ONBOARD_LED = D7;  // on board LED is ALWAYS D7

int counter = 0;

// when we need "state" variable, we need global variables
int prevButtonVal = 1;  // starts at HIGH aka unpressed

// define our function above setup()
void changeRgbColor(int r, int g, int b) {
    analogWrite(PIN_RGB_R, r);
    analogWrite(PIN_RGB_G, g);
    analogWrite(PIN_RGB_B, b);
}

void changeRgbRandom() {
    int randR = random(0, 256);  // random number from 0-255
    int randG = random(0, 256);
    int randB = random(0, 256);

    changeRgbColor(randR, randG, randB);  // we are using the function we
                                          // created
}

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_RGB_R, OUTPUT);
    pinMode(PIN_RGB_G, OUTPUT);
    pinMode(PIN_RGB_B, OUTPUT);
    pinMode(PIN_ONBOARD_LED, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // build a latch with the button so the counter only increases once when you
    // prsss button

    // version 1
    //  int buttonVal = digitalRead(PIN_BUTTON); //HIGH or LOW

    // if (buttonVal == HIGH) {                //LOW is unpressed
    //   digitalWrite(PIN_ONBOARD_LED, LOW);
    // }
    // else {                                    //HIGH is pressed
    //   digitalWrite(PIN_ONBOARD_LED, HIGH);
    //   counter = counter + 1;
    //   Serial.println("counter = " + String(counter));
    // }

    // // version 2 - latch
    // int currButtonVal = digitalRead(PIN_BUTTON);
    // if (currButtonVal == LOW && prevButtonVal == HIGH) {
    //     // put code that you want to execute ONLY once when button is pressed
    //     counter = counter + 1;
    //     Serial.println("counter = " + String(counter));
    // }

    // //the last thing through the loop, update prev
    // prevButtonVal = currButtonVal;

    // // version 3
    // int currButtonVal = digitalRead(PIN_BUTTON);
    // if (currButtonVal == LOW && prevButtonVal == HIGH) {
    //     // show red for 500ms, orange for 500, white for 500 ms
    //         // analogWrite(PIN_RGB_R, 255);
    //         // analogWrite(PIN_RGB_G, 0);
    //         // analogWrite(PIN_RGB_B, 0);
    //         changeRgbColor(255, 0, 0);
    //         delay(500);

    //         // analogWrite(PIN_RGB_R, 255);
    //         // analogWrite(PIN_RGB_G, 155);
    //         // analogWrite(PIN_RGB_B, 0);
    //         changeRgbColor(255, 155, 0);
    //         delay(500);

    //         // analogWrite(PIN_RGB_R, 255);
    //         // analogWrite(PIN_RGB_G, 255);
    //         // analogWrite(PIN_RGB_B, 255);
    //         changeRgbColor(255, 255, 255);
    //         delay(500);
    // }

    // // the last thing through the loop, update prev
    // prevButtonVal = currButtonVal;

    // // version 4
    // int currButtonVal = digitalRead(PIN_BUTTON);
    // if (currButtonVal == LOW && prevButtonVal == HIGH) {
    //   changeRgbRandom();
    // }

    // // the last thing through the loop, update prev
    // prevButtonVal = currButtonVal;

    // version 5 -- how could we get a sequence
    //   one press - red
    //   second press - blue
    //   third press - magenta
    //   fourth press - repeats again with red
    int currButtonVal = digitalRead(PIN_BUTTON);
    if (currButtonVal == LOW && prevButtonVal == HIGH) {
        counter = counter + 1;
        if (counter == 0) {
            changeRgbColor(255, 0, 0);  //red
        } else if (counter == 1) {
            changeRgbColor(0, 0, 255);  //blue
        } else {
            changeRgbColor(255, 0, 255); //magenta

        }
        if (counter >= 3) {
            counter = -1;
        }
    }

    // the last thing through the loop, update prev
    prevButtonVal = currButtonVal;
}
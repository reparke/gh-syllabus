const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;
const int PIN_POT = A0;

//function defintion
void changeRgbColor(int r, int g, int b) {
    analogWrite(PIN_RED, r);  
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);  
}


void changeRgbColorString(String color) {
    if (color.toLowerCase() == "red") {
        changeRgbColor(255, 0, 0);  //OR use three digital or analogWrite functions
    }
    else if (color == "green") {
        changeRgbColor(0, 255, 0);  // green

    }
    else if (color == "blue") {
        changeRgbColor(0,0,255);  // 
    }
    else if (color == "orange") {
        changeRgbColor(255, 130, 0);  // orange
    }
    else  {    //
        changeRgbColor(255, 255, 255);  // orange
    }

}

void setup() {
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_POT, INPUT);
    Serial.begin(9600);
}
void loop() {
    //read the potentiometer
    //show the color white
    //use the pot to change the brightness
    //input ADC: 0-4095
    //output PWM: 0-255

    int potVal = analogRead(PIN_POT); //ADC val 0-4095
    // float voltage = float(potVal) / 4095 * 3.3;
    int pwmVal = float(potVal) / 4095 * 255;

    analogWrite(PIN_RED, pwmVal);
    analogWrite(PIN_GREEN, pwmVal);
    analogWrite(PIN_BLUE, pwmVal);

    // CONTINUE
    /*
    red, green, blue
    magenta, white, yellow, orange
    */

    // changeRgbColorString("red");      // red
    // delay(500);                     // 500 ms or 1/2 sec
    // changeRgbColorString("green");      // green
    // delay(1000);                    // 500 ms or 1/2 sec
    // changeRgbColorString("blue");      // blue
    // delay(250);                     // 500 ms or 1/2 sec
    // changeRgbColorString("orange");  // white
    // delay(500);                     // 500 ms or 1/2 sec

    // changeRgbColor(255,0,0); //red
    // delay(500);  // 500 ms or 1/2 sec
    // changeRgbColor(0, 255, 0);  // green
    // delay(1000);                 // 500 ms or 1/2 sec
    // changeRgbColor(0, 0, 255);  // blue
    // delay(250);                 // 500 ms or 1/2 sec
    // changeRgbColor(255, 255, 255);  // white
    // delay(500);                 // 500 ms or 1/2 sec
    // changeRgbColor(255, 130, 0);  // orange
    // delay(500);                 // 500 ms or 1/2 sec
}


/*
const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;
const int PIN_POT = A0;

void setup() {
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_POT, INPUT);
    Serial.begin(9600);
}
void loop() {
    //CONTINUE
      //  red, green, blue
    //magenta, white, yellow, orange
    


    // first time: R G B - LOW LOW LOW
    // show red on the LED for 1/2 sec
    digitalWrite(PIN_RED, HIGH);  // digitalWrite(PIN, HIGH or LOW)
    digitalWrite(PIN_GREEN, LOW);
    digitalWrite(PIN_BLUE, LOW);
    // high is 3.3V, and 0 is ground
    delay(500);  // 500 ms or 1/2 sec
    // first time: R G B - HIGH LOW LOW

    digitalWrite(PIN_RED, LOW);
    digitalWrite(PIN_GREEN, HIGH);  // digitalWrite(PIN, HIGH or LOW)
    digitalWrite(PIN_BLUE, LOW);
    // high is 3.3V, and 0 is ground
    delay(500);  // 500 ms or 1/2 sec
    // first time: R G B - HIGH HIGH LOW

    digitalWrite(PIN_RED, LOW);
    digitalWrite(PIN_GREEN, LOW);
    digitalWrite(PIN_BLUE, HIGH);  // digitalWrite(PIN, HIGH or LOW)
    // high is 3.3V, and 0 is ground
    delay(500);  // 500 ms or 1/2 sec
    // first time: R G B - HIGH HIGH HIGH
    
    //white
    digitalWrite(PIN_RED, HIGH);
    digitalWrite(PIN_GREEN, HIGH);
    digitalWrite(PIN_BLUE, HIGH);  // digitalWrite(PIN, HIGH or LOW)
    // high is 3.3V, and 0 is ground
    delay(500);  // 500 ms or 1/2 sec
    // first time: R G B - HIGH HIGH HIGH

    // orange  RGB 255, 130, 0
    analogWrite(PIN_RED, 255); // also ok is digitalWrite(PIN_RED, HIGH)
    analogWrite(PIN_GREEN, 130); 
    analogWrite(PIN_BLUE, 0);  //OR digitalWrite(PIN_BLUE, LOW)

    // high is 3.3V, and 0 is ground
    delay(500);  // 500 ms or 1/2 sec
    // first time: R G B - HIGH HIGH HIGH
}

*/
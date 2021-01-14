/*
* 10 mV / deg Celsius with a 500 mV offset
* Try this: if **Vout** is 1.2V, what is the temperature in Celsius? in
Fahrenheit?
* *Remember:*
  * T(fahr) = T(cel) * (9/5) + 32
  * T(cel) = (T(fahr) - 32 ) * (5/9)

1.2v - 500mv = 1.2V - 0.5V = 0.7V
now handle conversion
 0.7 V * degC / 10mV = 0.7V * degC / 0.01V
=0.7V * degC * 100 = 70 degC
Now to fahrenheit
158 degF
*/

// Part 1 - TMP36
const int PIN_TMP36 = A5;
double tempC = 0;
double tempF = 0;

const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;

void setup() {
    // Part 1 - TMP36
    pinMode(PIN_TMP36, INPUT);
    Serial.begin(9600);

    // Part 2 - Cloud functions
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);

    Particle.function("Change LED Color", changeLedColor);
    Particle.variable("Temperature (F)", tempF);
}

void loop() {
    // Part 1 - TMP36
    int val = analogRead(PIN_TMP36);
    Serial.println("TMP36 ADC val: " + String(val));

    double tmp36Voltage = val * 3.3 / 4095;
    Serial.println("TMP36 voltage: " + String(tmp36Voltage));

    tempC = (tmp36Voltage - 0.5) * 100;  // divide 0.01 mv
    Serial.println("TMP36 tempC: " + String(tempC));

    tempF =
        tempC * (9.0 / 5) + 32;  // NOTE: C++ division of ints truncates decimal
    Serial.println("TMP36 tempF: " + String(tempF));

    Serial.println();

    delay(2000);
}

// Part 2 - Cloud functions
int changeLedColor(String color) {
    if (color.equalsIgnoreCase("red")) {
        analogWrite(PIN_RED, 255);
        analogWrite(PIN_GREEN, 0);
        analogWrite(PIN_BLUE, 0);
        Serial.print("red");
        return 0;
    } else if (color.equalsIgnoreCase("green")) {
        analogWrite(PIN_RED, 0);
        analogWrite(PIN_GREEN, 255);
        analogWrite(PIN_BLUE, 0);
        return 0;
    } else if (color.equalsIgnoreCase("blue")) {
        analogWrite(PIN_RED, 0);
        analogWrite(PIN_GREEN, 0);
        analogWrite(PIN_BLUE, 255);
        return 0;
    } else if (color.equalsIgnoreCase("magenta")) {
        analogWrite(PIN_RED, 255);
        analogWrite(PIN_GREEN, 0);
        analogWrite(PIN_BLUE, 255);
        return 0;
    } else if (color.equalsIgnoreCase("yellow")) {
        analogWrite(PIN_RED, 255);
        analogWrite(PIN_GREEN, 255);
        analogWrite(PIN_BLUE, 0);
        return 0;
    } else if (color.equalsIgnoreCase("cyan")) {
        analogWrite(PIN_RED, 0);
        analogWrite(PIN_GREEN, 255);
        analogWrite(PIN_BLUE, 255);
        return 0;
    } else if (color.equalsIgnoreCase("white")) {
        analogWrite(PIN_RED, 255);
        analogWrite(PIN_GREEN, 255);
        analogWrite(PIN_BLUE, 255);
        return 0;
    } else if (color.equalsIgnoreCase("off")) {
        analogWrite(PIN_RED, 0);
        analogWrite(PIN_GREEN, 255);
        analogWrite(PIN_BLUE, 0);
        return 0;
    } else if (color.equalsIgnoreCase("random")) {
        int r = random(0, 256);
        int b = random(0, 256);
        int g = random(0, 256);
        analogWrite(PIN_RED, r);
        analogWrite(PIN_GREEN, g);
        analogWrite(PIN_BLUE, b);
        Serial.print("random");
        digitalWrite(D7, HIGH);
        delay(1000);
        digitalWrite(D7, LOW);

        return 0;
    } else {
        Serial.print("error");
        return -1;
    }
}
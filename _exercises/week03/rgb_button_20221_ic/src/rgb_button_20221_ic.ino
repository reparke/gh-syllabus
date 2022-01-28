const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;
const int PIN_BUTTON = D5;

int prevButtonState = HIGH;
int counter = 0;

// define the function
// returnType functionName (type1 paramName1, type2 paramName2,...)
void changeLedColor(int red, int green, int blue) {
    analogWrite(PIN_RED, red);
    analogWrite(PIN_GREEN, green);
    analogWrite(PIN_BLUE, blue);
}

void displayRandomColor() {
    int r = random(0, 255);
    int g = random(0, 255);
    int b = random(0, 255);
    analogWrite(PIN_RED, r);
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);
}

void setup() {
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    int currButtonState = digitalRead(PIN_BUTTON);
    if (currButtonState == LOW && prevButtonState == HIGH) {
        displayRandomColor();
    }
    prevButtonState = currButtonState;
}

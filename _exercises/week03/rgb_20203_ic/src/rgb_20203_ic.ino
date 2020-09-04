const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_BUTTON = D2;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  // analogWrite(PIN_RED, 0);
  // analogWrite(PIN_GREEN, 0);
  // analogWrite(PIN_BLUE, 0);
  displayColor(0,0,0);
}

void loop() {
  int val = digitalRead(PIN_BUTTON);
  if (val == LOW) {
    // analogWrite(PIN_RED, 140);
    // analogWrite(PIN_GREEN, 17);
    // analogWrite(PIN_BLUE, 252);
    //displayColor(140, 17, 252)
    displayRandomColor();
  }
}

// display color
// display a color
// input: 3 int for R, G, B
// return: none
// side-effect: change LED color
void displayColor(int red, int green, int blue) {
    analogWrite(PIN_RED, red);
    analogWrite(PIN_GREEN, green);
    analogWrite(PIN_BLUE, blue);
}

void displayRandomColor() {
  //generate a random number 0-255
  int r = random(0, 256);   //0-255 (don't include the endpoint)
  int g = random(0, 256);
  int b = random(0,256);

  displayColor(r, g, b);
}

  // //test red
  // analogWrite(PIN_RED, 255);
  // analogWrite(PIN_GREEN, 0);
  // analogWrite(PIN_BLUE, 0);
  // delay(2000);
  // //test green
  // analogWrite(PIN_RED, 0);
  // analogWrite(PIN_GREEN, 255);
  // analogWrite(PIN_BLUE, 0);
  // delay(2000);
  // //test blue
  // analogWrite(PIN_RED, 0);
  // analogWrite(PIN_GREEN, 0);
  // analogWrite(PIN_BLUE, 255);
  // delay(2000);


const int PIN_LED = D2;
const int PIN_ONBOARD_LED = D7;
const int PIN_BUTTON = D3;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_ONBOARD_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT); //button is DIGITAL INPUT
  Serial.begin(9600);         //always what you type   -- starts the serial object that allows us to print to the screen
}

void loop()
{
  int buttonValue = digitalRead(PIN_BUTTON);
  Serial.println("Button: " + String(buttonValue));
  digitalWrite(PIN_ONBOARD_LED, buttonValue);
  digitalWrite(PIN_LED, buttonValue);

  //just we don't get an error, we need to slow the loop
  delay(250);
}

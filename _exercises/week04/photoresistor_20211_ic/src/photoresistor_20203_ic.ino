//Particle cloud publish
// sending a message with some statsu to the cloud
// almost like "cloud serial monitor"

// Particle.publish(EVENT NAME, EVENT MESSAGE, PUBLIC or PRIVATE)
/*
  bright 3800
  ambient 1200
  dark 200

  */

//global constants
const int THRESHOLD_DARK = 1200;     //0-400 is dark
const int THRESHOLD_AMBIENT = 2500; // 400-2000 is ambient light
const int PIN_PHOTORESISTOR = A5;
const int PIN_RGB_RED = D2;
const int PIN_RGB_GREEN = D3;
const int PIN_RGB_BLUE = D4;


//bright is 2000-4095
//global variables
int lightReading;   //global
String lightString; //global

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_PHOTORESISTOR, INPUT);
  pinMode(PIN_RGB_RED, OUTPUT);
  pinMode(PIN_RGB_GREEN, OUTPUT);
  pinMode(PIN_RGB_BLUE, OUTPUT);

}

void loop()
{
  lightReading = analogRead(PIN_PHOTORESISTOR);
  if (0 < lightReading && lightReading < THRESHOLD_DARK)
  {
    lightString = "dark";
    // analogWrite(PIN_RGB_RED, 0);
    // analogWrite(PIN_RGB_GREEN, 0);
    // analogWrite(PIN_RGB_BLUE, 0);
    displayColorRGB(0,0,0);
    displayColorString("black");
  }
  else if (THRESHOLD_DARK <= lightReading && lightReading < THRESHOLD_AMBIENT)
  {
    lightString = "ambient";
    // analogWrite(PIN_RGB_RED, 255);
    // analogWrite(PIN_RGB_GREEN, 255);
    // analogWrite(PIN_RGB_BLUE, 0);
    // displayColorRGB(255, 255, 0);
    displayColorString("yellow");
  }
  else
  {
    lightString = "bright";
    // analogWrite(PIN_RGB_RED, 255);
    // analogWrite(PIN_RGB_GREEN, 255);
    // analogWrite(PIN_RGB_BLUE, 255);
    // displayColorRGB(255, 255, 255);
    displayColorString("white");
  }
  //ADC will never be negative
  //ADC from 0 to 4095

  Serial.println("Photoresitor value = " + String(lightReading));
  Serial.println("LightString  = " + lightString);

  Particle.publish("Light Reading", "Room is " + lightString, PRIVATE);


  delay(1000); //do this so we don't crash our serial monitor
}

//display a color in RGB
void displayColorRGB(int r, int g, int b)
{
  analogWrite(PIN_RGB_RED, r);
  analogWrite(PIN_RGB_GREEN, g);
  analogWrite(PIN_RGB_BLUE, b);

  //no return so it is void
}

void displayColorString(String color) {
  if (color == "red") {
    displayColorRGB(255,0,0);
  }
  else if (color == "yellow") {
    displayColorRGB(255, 255, 0);
  }
  //keep going
  else {
    displayColorRGB(255, 255, 255);
  }
}

/*
  Publish
    * Names and values must always be strings
    * Should only publish 1 event / sec (or burst of 4 events in 1 sec)
*/

/* 
  Most of our microcontroller 
  void means no return
  returnType name (parameterType1 parameterNAme1, parametertype2 paramNAme2) {

  }
*/



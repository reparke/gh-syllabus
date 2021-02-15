// /*
// install Blynk app on your phone

// connect RGB led to argon (D2, D3, D4)

// connect switch (Gnd - A0 - 3.3v)
// */
// #include <blynk.h>    //library
// char auth[] = "nrfFtX1ekx8jkb5cK0ZwrlZxKf3s7ARN";  //this is a array of characters with our token

// //if you're sending values to from ARGON to APP (push), we MUST use millis()
// //limit is 10 values per sec
// //in loop(), we MUST NOT use delay
// unsigned long blynkDelay = 1000;
// unsigned long prevMillis = 0;

// const int PIN_RED = D2;
// const int PIN_GREEN = D3;
// const int PIN_BLUE = D4;
// const int PIN_SWITCH = A0;

// //virtual pin headers
// const int VPIN_RED = V0;
// const int VPIN_GREEN = V1;
// const int VPIN_BLUE = V2;
// const int VPIN_SWITCH = V3;
// //you do NOT need to set PINMODE for these virtual pins

// //retrieve from app
// // app ==> argon
// //  create a special function called BLYNK_WRITE(<<PIN>>)

// BLYNK_WRITE(V0) {
//   //event handler for when the user moves the sliders on the app
//   //we have a slider that send an integer value from 0-255
//   //lets read the value on the slider
//   int sliderValue = param.asInt();      //represents slider value
//   analogWrite(PIN_RED, sliderValue);
// }
// BLYNK_WRITE(V1) {
//     int sliderValue = param.asInt();  //represents slider value
//     analogWrite(PIN_GREEN, sliderValue);
// }
// BLYNK_WRITE(V2) {
//     int sliderValue = param.asInt();  //represents slider value
//     analogWrite(PIN_BLUE, sliderValue);
// }

// void setup() {
//   pinMode(PIN_RED, OUTPUT);
//   pinMode(PIN_GREEN, OUTPUT);
//   pinMode(PIN_BLUE, OUTPUT);
//   pinMode(PIN_SWITCH, INPUT);
//   //1. have delay
//   delay(5000);    //needs to be delay, not millis

//   //2. connect to blynk
//   Blynk.begin(auth);
// }

// void loop() {
//   Blynk.run(); // do NOT put in millis timer

//   unsigned long currMillis = millis();
//   if (currMillis - prevMillis > blynkDelay) {
//     prevMillis = currMillis;

//     // NOW we send value
//     // Blynk.virtualWrite(<<PIN>>, <<VALUE>>)
//     Blynk.virtualWrite(VPIN_SWITCH, digitalRead(A0)); //send data from argon ===> app
//   }
// }
#include <blynk.h>                                //library
char auth[] = "_Ce745Lvb6anFEDvGggMSYvZCwIF8b6i"; //this is a array of characters with our token

//if you're sending values to from ARGON to APP (push), we MUST use millis()
//limit is 10 values per sec
//in loop(), we MUST NOT use delay
unsigned long blynkDelay = 1000;
unsigned long prevMillis = 0;

const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

int switchRead; //magnetic switch
bool isDoorOpen = false;

//virtual pin headers
const int VPIN_RED = V0;
const int VPIN_GREEN = V1;
const int VPIN_BLUE = V2;
const int VPIN_SWITCH = V3;
const int VPIN_TEXT = V4;
//you do NOT need to set PINMODE for these virtual pins

//retrieve from app
// app ==> argon
//  create a special function called BLYNK_WRITE(<<PIN>>)

BLYNK_WRITE(V0)
{
  //event handler for when the user moves the sliders on the app
  //we have a slider that send an integer value from 0-255
  //lets read the value on the slider
  int sliderValue = param.asInt(); //represents slider value
  analogWrite(PIN_RED, sliderValue);
  Serial.println("Red: " + String(sliderValue));
}
BLYNK_WRITE(V1)
{
  int sliderValue = param.asInt(); //represents slider value
  if ()
  analogWrite(PIN_GREEN, sliderValue);
  Serial.println("Green: " + String(sliderValue));
}
BLYNK_WRITE(V2)
{
  int sliderValue = param.asInt(); //represents slider value
  analogWrite(PIN_BLUE, sliderValue);
  Serial.println("Blue: " + String(sliderValue));
}
BLYNK_WRITE(V4)
{
  String command = param.asString(); //represents slider value
  if (command == "on") {
    Serial.println("Blink sent!");
  }
  else if (command == "off") {

  }
}

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_SWITCH, INPUT);
  Serial.begin(9600);

  //1. have delay
  delay(5000); //needs to be delay, not millis

  //2. connect to blynk
  // Blynk.begin(auth);
  Blynk.begin(auth, IPAddress(192, 168, 0, 131), 8080);

}

void loop()
{
  Blynk.run(); // do NOT put in millis timer

  unsigned long currMillis = millis();
  if (currMillis - prevMillis > blynkDelay)
  {
    prevMillis = currMillis;

    // NOW we send value
    // Blynk.virtualWrite(<<PIN>>, <<VALUE>>)
    Blynk.virtualWrite(VPIN_SWITCH, digitalRead(PIN_SWITCH)); //send data from argon ===> app
                                                              // switchRead = digitalRead(PIN_SWITCH);
  }
}
  // if (switchRead == HIGH)
  // { // just read that switch is open
  //   if (isDoorOpen == false)
  //   {
  //     isDoorOpen = true;
  //     Blynk.virtualWrite(VPIN_SWITCH, isDoorOpen); //send data from argon ===> app
  //     Serial.println("closed --> open");
  //   }
  // }
  // else
  // { // just read that switch is closed
  //   if (isDoorOpen == true)
  //   {
  //     isDoorOpen = false;
  //     Blynk.virtualWrite(VPIN_SWITCH, isDoorOpen); //send data from argon ===> app

  //     Serial.println("open --> closed");
  //   }
  // }
// }

// void switchEventHandler(const char *event, const char *data)
// {
//   String eventName = String(event);
//   String eventData = String(data); //convert the pointer to be string

//   if (eventName.equalsIgnoreCase("ITP348/Door/NH"))
//   {
//     if (eventData.equalsIgnoreCase("closed --> open"))
//     {
//       analogWrite(PIN_RED, 255);
//       analogWrite(PIN_GREEN, 0);
//       analogWrite(PIN_BLUE, 0);
//     } //open to close
//     else
//     {
//       analogWrite(PIN_RED, 255);
//       analogWrite(PIN_GREEN, 255);
//       analogWrite(PIN_BLUE, 255);
//     }
//   }
// }
// //this is a particle function
// int blinkLed(String cmd)
// {
//   Serial.println(cmd);
//   if (cmd.equals("twice"))
//   {
//     analogWrite(PIN_RED, 255);
//     analogWrite(PIN_GREEN, 255);
//     analogWrite(PIN_BLUE, 255);
//     delay(500);
//     analogWrite(PIN_RED, 0);
//     analogWrite(PIN_GREEN, 0);
//     analogWrite(PIN_BLUE, 0);
//     delay(500);
//     analogWrite(PIN_RED, 255);
//     analogWrite(PIN_GREEN, 255);
//     analogWrite(PIN_BLUE, 255);
//     delay(500);
//     analogWrite(PIN_RED, 0);
//     analogWrite(PIN_GREEN, 0);
//     analogWrite(PIN_BLUE, 0);
//     delay(500);
//   }
//   else if (cmd.equals("once"))
//   {
//     analogWrite(PIN_RED, 255);
//     analogWrite(PIN_GREEN, 255);
//     analogWrite(PIN_BLUE, 255);
//     delay(500);
//     analogWrite(PIN_RED, 0);
//     analogWrite(PIN_GREEN, 0);
//     analogWrite(PIN_BLUE, 0);
//     delay(500);
//   }
//   return 0;
// }

// int blinkLed(String cmd) {
//     Serial.println("IFTTT function input: " + cmd);
//     if (cmd.equalsIgnoreCase("twice")) {
//         digitalWrite(PIN_LED, HIGH);
//         delay(1000);
//         digitalWrite(PIN_LED, LOW);
//         delay(1000);
//     }
//     digitalWrite(PIN_LED, HIGH);
//     delay(1000);
//     digitalWrite(PIN_LED, LOW);
//     delay(1000);
// }
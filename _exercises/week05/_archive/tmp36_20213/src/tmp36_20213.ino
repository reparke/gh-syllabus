
const int PIN_TMP = A5;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TMP, INPUT);
}

// void loop() {
//   int val = analogRead(PIN_TMP);    //Analog val: 0-4095 ADC

//   //need volt
//   float voltage = (float) val / 4095 * 3.3; //volt 0-3.3 v; ADC 0-4095

//   //10 mV per deg C; also 0.5 v offset 
//   //(voltage - 0.5) / 0.01
//   float tempC = (voltage - 0.5) / 0.01;
//   float tempF = tempC * (9.0 / 5) + 32;
//   Serial.println("Temp F: " + String(tempF));

//   //publish event name should the same as the webhook event name
//   Particle.publish("room_temperature", String(tempF, 1)); //{{{PARTICLE_EVENT_VALUE}}} is 
//                                                           //2nd param in your publish
  
//   //VERY VERY VERY important
//   //limited number of times we can use particle cloud and initial state per month
//   //  
//   delay(10000);
// }

void loop() {
    // The core of your code will likely live here.
    int val = analogRead(pin_temp);  // 4095 ADC
    float voltage = (float)val / 4095 * 3.3;
    // Voltage - 0.5)/0.01
    float tempC = (voltage - 0.5) / 0.01;
    float tempF = tempC * (9.0 / 5) + 32;
    Serial.println("TempF" + String(tempF) + "Temp C" + String(tempC));
    Particle.publish("room_temperature", String(tempF, 1));
    // limited number of times particle cloud and initial state
    delay(10000);
}
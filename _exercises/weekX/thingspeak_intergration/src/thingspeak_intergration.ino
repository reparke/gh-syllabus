
double temp;
double humidity;  // both doubles
int rainfall;
String weather;

void setup() {
  Serial.begin(9600);
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/Environment", myHandler, MY_DEVICES);
}

void myHandler(const char *event, const char *data) {
  // Handle the integration response
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  temp = random(70.0, 80.0);
  humidity = random(20.0, 50.0);
  rainfall = random(0, 20);
  weather = "sunny";
  // thingspeakSingleValue();
  thingspeakMultipleValues();
  // Wait 60 seconds
  delay(5000);
}

void thingspeakSingleValue() {
  // Trigger the integration
  Particle.publish("TS_SingleWrite", String(temp), PRIVATE);
}

void thingspeakMultipleValues() {
  String data = "{ \"weather\": \"" + weather + "\"" +
                ", \"temp\": " + temp +
                ", \"humidity\": " + humidity +
                ",\"rainfall\": " + rainfall +
                "}";

  // String data = String::format(
  //     "{ \"weather\": \"%s\", \"temp\": %f, \"humidity\": %f, \"rainfall\": %d "
  //     "}",
  //     weather.c_str(), temp, humidity, rainfall);
  // Trigger the integration
  Particle.publish("TS_MultiWrite", String(data), PRIVATE);
}

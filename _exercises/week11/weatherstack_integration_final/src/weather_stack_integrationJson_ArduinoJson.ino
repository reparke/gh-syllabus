/* Connects to WeatherStack to receive current focus as JSON

requires ArduinoJson library
requires account at https://weatherstack.com/

*/
#include <Arduino.h>
#define ARDUINOJSON_ENABLE_PROGMEM 0
#include <ArduinoJson.h>

// responses will be sent
String payload;
String response;
// double temp;
// double humidity;
// int precipation;
// String description;
// String city;

void setup() {
    // Subscribe to the integration response event
    Particle.subscribe("hook-response/WeatherStackJSON",
                       jsonSubscriptionHandler);
}
// DynamicJsonDocument doc(2048);
void jsonSubscriptionHandler(const char *event, const char *data) {
    StaticJsonDocument<2048> doc;
    int responseIndex = 0;
    const char *slashOffset = strrchr(event, '/');
    if (slashOffset) {
        responseIndex = atoi(slashOffset + 1);
    }

    if (responseIndex == 0) {
        response = "";
        doc.clear();
    }
    response += String(data);

    DeserializationError error = deserializeJson(doc, response);

    if (error == false) {
        // JsonObject location = doc["location"];
        // String city = location["name"];  // "Fullerton"
        String city = doc["location"]["name"];

        JsonObject current = doc["current"];
        float temp = current["temperature"];  // 68

        String description = current["weather_descriptions"][0];  // "Sunny"

        float precipation = current["precip"];  // 0
        float humidity = current["humidity"];   // 40

        Serial.println(city + "\n  " + description +
                       "\n  temperature: " + String(temp, 1) +
                       " F\n  humidity: " + String(humidity, 1) +
                       "%\n  rainfall: " + String(precipation, 1) + " in");
    }
    // else {
    //   Serial.println(String(responseIndex) + " Error: " + String
    //   (error.c_str())); Serial.println("\t"+payload);
    // }
}

void loop() {
    // Get some data
    String data = "92807";

    // Trigger the integration
    Particle.publish("WeatherStackJSON", data);
    // Wait 60 seconds
    delay(10000);
}

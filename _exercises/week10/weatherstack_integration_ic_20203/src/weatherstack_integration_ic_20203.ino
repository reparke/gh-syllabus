#include "JsonParserGeneratorRK.h"

JsonParser jsonParser;

void loop() {
    // Get some data
    Serial.begin(9600);
    String data = "90089";
    // Trigger the integration
    Particle.publish("WeatherStackJSON", data, PRIVATE);
    // Wait 60 seconds
    delay(20000);
}

void setup() {
    // Subscribe to the integration response event
    Particle.subscribe("hook-response/WeatherStackJSON", myHandler, MY_DEVICES);
}

void myHandler(const char *event, const char *data) {

    int responseIndex = 0;

    const char *slashOffset = strrchr(event, '/');
    if (slashOffset) {
        responseIndex = atoi(slashOffset + 1);
    }

    if (responseIndex == 0) {
        jsonParser.clear();
    }
    jsonParser.addString(data);

    /*
  "location": {
    "name": "Los Angeles",
    "country": "USA",
    "region": "California",
    "lat": "34.018",
    "lon": "-118.284",
    "timezone_id": "America/Los_Angeles",
    "localtime": "2020-10-22 16:47",
    "localtime_epoch": 1603385220,
    "utc_offset": "-7.0"
  },
*/

    //this is where we start coding
    if (jsonParser.parse()) {
      String city = jsonParser.getReference().key("location").key("name").valueString();

      Serial.println("Weather for " + city);

      //temperarture, humidity, precipitation, descritpion
    }
}
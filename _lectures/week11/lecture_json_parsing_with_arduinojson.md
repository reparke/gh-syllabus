---
marp: true
theme: itp

week: 11
category: lectures
title: Parsing JSON with ArduinoJson Library
---

<!-- headingDivider: 2 -->

# Parsing JSON with `ArduinoJson` Library

## JSON Example Data

- Consider the following JSON data is being received by the Argon

```json
{
  "location": {
    "name": "Los Angeles",
    "country": "USA",
    "region": "California",
    "lat": "34.018",
    "lon": "-118.284",
  },
  "current": {
    "observation_time": "01:56 AM",
    "temperature": 63,
    "weather_descriptions": [
      "Partly cloudy"
    ],
    "humidity": 56,
  }
}
```



## Parsing JSON with a Library:  `ArduinoJson` 

- `ArduinoJson` is a popular library for parsing JSON code and can be installed from **Workbench**
* Use the sample code below for your event handler
* The first part allows for responses from the webhook that come in multiple parts (you don't need to change this)
* The second part is where you can adapt your own code

## Publishing and Subscribing

```c++
void setup() {
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/JSONWeatherStack", jsonSubscriptionHandler,
                     MY_DEVICES);
}

void loop() {
  // Get some data
  String data = "92807";
  // Trigger the integration
  Particle.publish("JSONWeatherStack", data, PRIVATE);
  // Wait 60 seconds
  delay(60000);
}
```



## Parsing with `ArduinoJson`

```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
  //Part 1 allows for webhook responses to be delivered in multple "chunks"; you don't need to change this
  int responseIndex = 0;
  StaticJsonDocument<2048> doc;
  const char *slashOffset = strrchr(event, '/');
  if (slashOffset)
    responseIndex = atoi(slashOffset + 1);
  if (responseIndex == 0) {
     response = "";
     doc.clear();
   }
   response += String(data);

  //Part 2 is where you can parse the actual data; you code goes in the IF
  DeserializationError error = deserializeJson(doc, response);
  if (error == false) {

  	/****** YOUR PARSING CODE GOES HERE ********/
  
  }
}
```

## Example: Consider the following JSON

```json
{
  "place": {
    "city": "los angeles",
    "state": "california"
  }
}
```

### Configuration of `ArduinoJson`

- Import library and set up Arduino compatibility
```c++
#include <Arduino.h>
#define ARDUINOJSON_ENABLE_PROGMEM 0
#include <ArduinoJson.h>
```



### Configuration of Event Handler
- The JSON will be passed to the `data` parameter of event handler 
```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
```
- The first part of our event handler accounts for a single JSON broken up into multiple events
- This code is complete and you don't need to modify it
- The part we are interested is the actual JSON parsing



Here is an example

```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
  /* ... rest of function code */
  if (error == false) {
    String city = doc["place"]["city"]; // "los angeles"
    Serial.println("The city " + city);
  }
}
```
## Useful Links

- [ArduinoJson Library](https://arduinojson.org/)
- [JsonParserGeneratorRK library](https://github.com/rickkas7/JsonParserGeneratorRK)
- [JSON Online Formatter](https://jsonformatter.org/json-pretty-print)
- [Mustache Tester](http://rickkas7.github.io/mustache/) for identifying JSON values

## Credit

- [Webhooks by DioT Labs](https://diotlabs.daraghbyrne.me/docs/working-with-data/webhooks)

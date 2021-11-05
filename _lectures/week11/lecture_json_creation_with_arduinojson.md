---
marp: true
theme: itp

week: 11
category: lectures
title: Creating JSON with ArduinoJson Library
---

<!-- headingDivider: 2 -->

# Creating JSON with `ArduinoJson` Library

## JSON Example Data

- Consider we want to send the following JSON data to a website

```json
[
 {"key":"temperature", "value":79.000000},
 {"key":"humidity", "value":22.000000},
 {"key":"weather", "value": "sunny"}
]
```

##  Creating JSON with a Library:  `ArduinoJson` 

- `ArduinoJson` is a popular library for parsing JSON code and can be installed from **Workbench**

* Use the sample code below

### Configuration of `ArduinoJson`

- Import library and set up Arduino compatibility

```c++
#include <Arduino.h>
#define ARDUINOJSON_ENABLE_PROGMEM 0
#include <ArduinoJson.h> 
```

### Argon code

```c++
void loop() {
  String output;
    
  JsonObject doc_0 = doc.createNestedObject();
  doc_0["key"] = "temperature";
  doc_0["value"] = 79.000000;

  JsonObject doc_1 = doc.createNestedObject();
  doc_1["key"] = "humidity";
  doc_1["value"] = 22.000000;

  JsonObject doc_2 = doc.createNestedObject();
  doc_2["key"] = "weather";
  doc_2["value"] = "sunny";

  serializeJson(doc, output);
  
  //make sure to change the event name below to match the webhook you created  
  Particle.publish("inital_state_json", output);
  delay(60000);	//use delay or millis to avoid publishing too frequently
}
```
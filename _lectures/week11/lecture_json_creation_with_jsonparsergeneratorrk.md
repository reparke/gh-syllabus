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

## Creating JSON with a Library:  `JsonParserGeneratorRK` 

- `JsonParserGeneratorRK` is a popular library for creating JSON data and can be installed from **Workbench**

* Use the sample code below

### Configuration of `JsonParserGeneratorRK`

- Import library and set up Arduino compatibility

```c++
#include "JsonParserGeneratorRK.h"  
```

### Argon code

**Important:** The `{...}` around the `JsonWriteAutoArray` are required for the library. It ensures that all JSON values are in either an valid object or arrays

```c++
void loop() {
    
  JsonWriterStatic<622> jw;
  jw.init();  // empty buffer for reuse (since jw is static)

  {
    JsonWriterAutoArray obj(&jw);

    jw.startObject();
    jw.insertKeyValue("key", "temperature");
    jw.insertKeyValue("value", 79.000000);
    jw.finishObjectOrArray();

    jw.startObject();
    jw.insertKeyValue("key", "humidity");
    jw.insertKeyValue("value", 22.000000);
    jw.finishObjectOrArray();

    jw.startObject();
    jw.insertKeyValue("key", "weather");
    jw.insertKeyValue("value", sunny);
    jw.finishObjectOrArray();

    jw.finishObjectOrArray();
  }

  //make sure to change the event name below to match the webhook you created  
  Particle.publish("inital_state_json", jw.getBuffer());
}
```


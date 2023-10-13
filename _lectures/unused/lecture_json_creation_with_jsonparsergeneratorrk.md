<!-- headingDivider: 2 -->

# Creating JSON with `JsonParserGeneratorRK` Library

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

### Argon code - Template

**Important:** The `{...}` around the `JsonWriteAutoArray` are required for the library. It ensures that all JSON values are in either an valid object or arrays

```c++
void loop() {
    
  JsonWriterStatic<622> jw;
  jw.init();  // empty buffer for reuse (since jw is static)

  {
    JsonWriterAutoArray obj(&jw);

    // Start of code for one data value
    jw.startObject();
    jw.insertKeyValue("key", <<add your name for data>>);
    jw.insertKeyValue("value", <<add value for data>> );
    jw.finishObjectOrArray();
	// End of code for one data value
      
 	// Include more data values at needed
	// ...
      
    jw.finishObjectOrArray();
  }


  Particle.publish(<<add your webhook name>>, jw.getBuffer());
}
```

### Argon code - Example

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


  Particle.publish("inital_state_json", jw.getBuffer());
}
```

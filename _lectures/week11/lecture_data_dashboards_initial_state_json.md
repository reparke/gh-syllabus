---
marp: true
theme: itp

week: 11
category: lectures
title: Sending Multiple Values to Initial State using JSON
---

<!-- headingDivider: 2 -->

# Data Visualization and Dashboards with Initial State 

![bg opacity:.75](lecture_data_dashboards_initial_state_json.assets/Infruid's_Self-Service_BI_Tool_Dashboard.jpg)

## Review: Uses of Dashboards

* View real-time sensor data

* Compare data to historical trends
* Monitor IoT devices for errors or network issues
* Map devices GPS location
* Remote control (execute functions) on devices
* We will use Initial State ([https://initialstate.com](https://initialstate.com)) but others are listed at the end

## Goal: Use JSON to send Multiple Values to Initial State at Once 

* It is faster and uses less bandwidth to send multiple sensor in a single package
* We will use JSON to package all the data and send to Initial State
* The following examples are provided as a quick reference
* More detailed steps are described in the lecture 

## Reminder: Steps to Connect Argon and Initial State 

1. Create account at  [https://initialstate.com](https://initialstate.com) 
2. Create **stream bucket** at [https://initialstate.com](https://initialstate.com)  
3. Create an integration -> webhook on [Particle console](https://console.particle.io/integrations) 
4. Write firmware sketch and flash Argon

## Configure Initial State to Receive JSON 

**Initial State Settings**

<img src="lecture_data_dashboards_initial_state_json.assets/image-20200703180348874.png" alt="image-20200703180348874" style="width:500px;" />

## Configure Particle Cloud to Pass JSON

**Particle integration settings**

<img src="lecture_data_dashboards_initial_state_json.assets/image-20200703160032339.png" alt="image-20200703160032339" style="width:600px;" />

## Configure Particle Cloud to Pass JSON  

**Particle integration settings**

{% comment %} This code below is because Liquid breaks with the triple brackets {% endcomment %}
{% assign liquid_code_block = '{{{PARTICLE_EVENT_VALUE}}}' %}

JSON Data: `{{ liquid_code_block }}`

URL: `https://groker.init.st/api/events`

<img src="lecture_data_dashboards_initial_state_json.assets/image-20200703180944077.png" alt="image-20200703180944077" style="width:500px;" />

## Configure Particle Cloud to Pass JSON

**Particle integration settings**

<img src="lecture_data_dashboards_initial_state_json.assets/SNAGHTML22743719.PNG" alt="img" style="width:500px;" />



## Configure Particle Cloud to Pass JSON

**Particle integration setting: HTTP Headers**

`Accept-Version`	>	`~0`      ***note: this is a tilde ~, NOT a hyphen -***

`X-IS-AccessKey`	>	*<<USE YOUR OWN API KEY>>>*

`X-IS-BucketKey`	>	*<<USE YOUR OWN BUCKET KEY>>>*




## JSON Format  

* Initial State expects data to be entered in JSON format

```json
{"key": "temp", "value": 32}
```

*Where `temp` is the your chosen data label, and `32` is the current value*

* Each time we send data to Initial State, we sent one single data point

*We will cover JSON in-depth later.*

## Recall: Escape Characters

* Initial State value contains quotation marks `"` in the value

```json
{"key": "temp", "value": 32}
```

* Since `"` marks the beginning and end of `String`, we need to tell the Argon specifically when we want to include `"` in the value
* We use the **escape character ** `\"` to tell the Argon to ignore the `"` and consider it as part of the `String`
* Thus we have our `String` would become

```json
"{\"key\": \"temp\", \"value\": 32}"
```

## JSON Format  

* Sending one data point at a time is valid, but is tedious if there are many values to send
* Instead, we can send a JSON array with many data point

```json
[
 {"key":"temperature", "value":79.000000},
 {"key":"humidity", "value":22.000000},
 {"key":"weather", "value": "sunny"}
]
```

* We just need to change the formatting of the data we send

## Aside: Creating JSON Automatically 

```json
[
 {"key":"temperature", "value":79.000000},
 {"key":"humidity", "value":22.000000},
 {"key":"weather", "value": "sunny"}
]
```

* Generating this value as a `String` is going to be messy
* There are libraries you can use for creating complex JSON messages
* First we'll walk through creating JSON manually, and then we'll look at a library

## Creating JSON

There are two ways we can generate the JSON value to send to Initial State. Both are shown below

1. Create JSON manually as a String variable
2. Using a library (popular libraries are [JsonParserGeneratorRK](https://github.com/rickkas7/JsonParserGeneratorRK) and [ArduinoJson](https://arduinojson.org/))

## Creating JSON Manually

### Argon code

```c++
void loop() {
  temp = 89;		//just example; temp should come from sensor
    
  String data = "[{ \"key\":\"temperature\", \"value\":" + 			
  String(temp) + "},{\"key\":\"humidity\", \"value\":" +
  String(humidity)+ "},{\"key\":\"weather\", \"value\": \"" +
  String(weather)+ "\"}]";
    
  Particle.publish("inital_state_json", String(temp), PRIVATE);
  delay(60000);	//use delay or millis to avoid publishing too frequently
}
```

## Creating JSON with a Library:  `JsonParserGeneratorRK` 

- `JsonParserGeneratorRK` is a popular library for parsing JSON code and can be installed from **Workbench**

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

  Particle.publish("week10_20203", jw.getBuffer());
}
```

 

## Creating JSON with a Library:  `ArduinoJson` 

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
  temp = 89;	//just example; temp should come from sensor
  String output;
    
  JsonObject doc_0 = doc.createNestedObject();
  doc_0["key"] = "temperature";
  doc_0["value"] = 79;

  JsonObject doc_1 = doc.createNestedObject();
  doc_1["key"] = "humidity";
  doc_1["value"] = 22;

  JsonObject doc_2 = doc.createNestedObject();
  doc_2["key"] = "weather";
  doc_2["value"] = "sunny";

  serializeJson(doc, output);
    
  Particle.publish("inital_state_json", output);
  delay(60000);	//use delay or millis to avoid publishing too frequently
}
```

## Lab - Send Photoresistor Value to Initial State

* Connect photoresistor to Argon
* Read photoresistor value and send to InitialState
* **Determine light threshold (dark, ambient, bright) and send this value to InitialState**

## Lab - Send Photoresistor Value to Initial State

<img src="lecture_data_dashboards_initial_state_json.assets/photoresistor_and_fixed_resistor_bb.png" style="width:500px;" />



## Other Dashboard Platforms

* [Google Cloud IoT](https://cloud.google.com/solutions/iot) (many IoT services)
* [Microsoft Azure IoT](https://azure.microsoft.com/en-us/overview/iot/) (many IoT services)
* [Amazon Web Services](https://aws.amazon.com/iot/) (many IoT services)
* [Losant](https://www.losant.com/) (many IoT services)
* [Ubidots](https://ubidots.com/)
* [Tinamous](https://www.tinamous.com/)
* [Initial State](https://www.initialstate.com/)

## Credits

* [Growthlakes](https://commons.wikimedia.org/wiki/File:Infruid%27s_Self-Service_BI_Tool_Dashboard.jpg)  [CC BY-SA](https://creativecommons.org/licenses/by-sa/4.0)
* Image created with [Fritzing](https://fritzing.org)
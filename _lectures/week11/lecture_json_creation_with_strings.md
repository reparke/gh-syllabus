---
marp: true
theme: itp

week: 11
category: lectures
title: Creating JSON Manually with Strings
---

<!-- headingDivider: 2 -->

# Creating JSON Manually with Strings

## JSON Example Data

- Consider we want to send the following JSON data to a website

```json
[
 {"key":"temperature", "value":79.000000},
 {"key":"humidity", "value":22.000000},
 {"key":"weather", "value": "sunny"}
]
```

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

## Creating JSON Manually

### Argon code

```c++
void loop() {
  temp = 89;		//just example; temp should come from sensor
    
  String data = "[{ \"key\":\"temperature\", \"value\":" + 			
  String(temp) + "},{\"key\":\"humidity\", \"value\":" +
  String(humidity)+ "},{\"key\":\"weather\", \"value\": \"" +
  String(weather)+ "\"}]";
 
  //make sure to change the event name below to match the webhook you created  
  Particle.publish("inital_state_json", String(temp), PRIVATE);
  delay(60000);	//use delay or millis to avoid publishing too frequently
}
```

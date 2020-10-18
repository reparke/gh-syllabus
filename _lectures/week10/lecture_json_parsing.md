---
marp: true
theme: itp

week: 10
category: lectures
title: JSON Parsing
---

<!-- headingDivider: 2 -->

# JSON Parsing

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



## Recall: What is JSON?

* When we communicate with an API to request information (e.g. the weather next week a certain city), the API will provides us data
* The data is often in a JSON format
* We need to be able to convert it into something usable

## Recall: JSON (JavaScript Object Notation)

* JSON is a way of representing an object as a text string
* Built around key-value pair idea (like a dictionary or hash)
* Two data types
  * **objects** (single item denoted with `{`   `}`)
  * **arrays** (multiple items denoted with `[`   `]`)

## Recall: JSON Nested Objects

```JSON
    { 
      "forecast": {
        "mon": {
          "high": 89,
          "low":54
        }
      }
    }
```

* Values can be JSON **objects** 
  * Ex: `forecast` is a **key** and the **value** is `"mon"` 
  * `"mon"` is itself a **key** which store the **keys** `"high"`  and  `low` 

## Recall: JSON Arrays

```JSON
{ "daily_temp": [
    89,
    84,
    83
  ] 
}
```

* **Arrays** are specified with `[` `]` 
* Indices begin at `0` and up to `length - 1`
* Elements of arrays can be **string**, **int**, **float**, **objects**, or **arrays**
  * Ex:`"daily_temp"` is a **key** and its **value** is an **array** 
  * Ex: `89` is an **int** and is at index`0`

## Parsing JSON with C code directly

* JSON is `String` data 
* It is possible to parse JSON using C-language techniques like `strtok`, `strcpy`, `atoi` 
* However, this is considered unsafe due to potential for security vulnerabilities 
* Buffer overrun if the response from the webserver was larger than expected or malformed
* **Instead, we will use a JSON library to parse**

## Parsing JSON with a Library

- `JsonParserGeneratorRK` is a great Argon-specific library for parsing JSON code and can be installed from **Workbench**
* Use the sample code below for your event handler
* The first part allows for responses from the webhook that come in multiple parts (you don't need to change this)
* The second part is where you can adapt your own code

## Parsing with `JsonParserGeneratorRK`

```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
  //Part 1 allows for webhook responses to be delivered in multple "chunks"; you don't need to change this
  int responseIndex = 0;
  const char *slashOffset = strrchr(event, '/');
  if (slashOffset)
    responseIndex = atoi(slashOffset + 1);
  if (responseIndex == 0)
    jsonParser.clear();
  jsonParser.addString(data);

  //Part 2 is where you can parse the actual data; you code goes in the IF
  if (jsonParser.parse()) {

  	/****** YOUR PARSING CODE GOES HERE ********/
  
  }
}
```

## Example
- Import library
```c++
#include "JsonParserGeneratorRK.h"
```
- Create global `JsonParser` object to read JSON
```c++
JsonParser jsonParser; 
```

## Example: Configuration
- Create the Particle webhook
- Publish event
- Subscribe to response and call event handler
- *These processes are described in the WeatherStack example*
&nbsp;
- Now let's look at the actual JSON response


## Example: Consider the following JSON

```json
{
  "place": {
    "city": "los angeles",
    "state": "california"
  }
}
```
## Example
- The JSON will be passed to the `data` parameter of event handler 
```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
```
- The first part of our event handler accounts for a single JSON broken up into multiple events
- This code is complete and you don't need to modify it
- The part we are interested is the actual JSON parsing

## Example
```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
  /* ... rest of function code */
  if (jsonParser.parse()) {

    String city = jsonParser.getReference()
               .key("place")
               .key("city")
               .valueString();
   Serial.println("The city " + city);
  }
}
```

## Useful Links

- [JsonParserGeneratorRK library](https://github.com/rickkas7/JsonParserGeneratorRK)
- [JSON Online Formatter](https://jsonformatter.org/json-pretty-print)
- [Mustache Tester](http://rickkas7.github.io/mustache/) for identifying JSON values

## Credit

- [Webhooks by DioT Labs](https://diotlabs.daraghbyrne.me/docs/working-with-data/webhooks)

---
marp: true
theme: itp

week: 12
category: lectures
title: APIs and JSON
---

<!-- headingDivider: 2 -->

# APIs and JSON

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
    "uv_index": 3,
    "visibility": 10,
    "is_day": "yes"
  }
}
```



## APIs

* A specification used as an interface between different pieces of software
* Allows code we write to connect to other services, gather data, etc.
* Usually related to a software library
* May also be related to a software framework
* May also be an implementation of a protocol
* Publishing APIs has allowed web communities to create an open architecture for sharing content and data between communities and applications

## Examples of APIs

* Weather data - [https://weatherstack.com](https://weatherstack.com)
* Dictionaries - [Merriam-Webste](https://dictionaryapi.com/)
* Transit data - [Bay Area Rapid Transit](http://api.bart.gov)
* Useful lists of public APIs
  * [https://github.com/toddmotto/public-apis](https://github.com/toddmotto/public-apis)
  * [https://github.com/abhishekbanthia/Public-APIs](https://github.com/abhishekbanthia/Public-APIs)

## Steps to Interacting with Data from API

1. Identify API you want to use (make account if necessary)
2. Create a Particle webhook that interacts with the API
3. Use `Particle.publish` to trigger webhook
4. Use `Particle.subscribe` to "listen" for response from webhook
5. Create **function handler** that is used by `Particle.subscribe` to process JSON

## JSON (JavaScript Object Notation)

* Popular format for exchanging data with web services
  * XML is another
* JSON is useful because we can represent complex data with a simple string, and then share that data between two different services
* Typically, programmers use library to read (parse) and write JSON

## JSON Overview

* JSON is a way of representing an object as a text string
* Built around key-value pair idea (like a dictionary or hash)
* Two data types
  * **objects** (single item denoted with `{`   `}`)
  * **arrays** (multiple items denoted with `[`   ``]`)

## JSON Basics - Objects

```JSON
{ "weather": "sunny", 
  "temp": 78.000, 
  "humidity": 32 
}
```

* Inside `{` `}` is the JSON object
* **Keys** are to the left of the `:` and are always **strings**
* **Values** are to the right of the `:` and can be **string**, **int**, **float**, **objects**, or **arrays**
  * Ex:`"weather"` is a **key** and `"sunny"` is its **value** 
  * Ex: `"sunny"` is a **string**, `78.000` is a **double** or **float**, `32` is an **int**

## JSON Basics - Nested Objects

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

## JSON Basics - Arrays

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

## 



## Parsing JSON

* Typically parsing can be done using a library (in almost any language)
* We will use `JsonParserGeneratorRK` which is written specifically for Argon and can be installed from **Workbench**

## Parsing with `JsonParserGeneratorRK`

* The library provides sample code for interacting with most APIs that provide JSON data
* The sample code allows for responses from the webhook that come in multiple parts
* Adapt the code below by customizing the code within `if(jsonParser.parse())`

## Parsing with `JsonParserGeneratorRK`

```json
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
  	//parsing code goes here
  }
}
```



## Credit

- [Webhooks by DioT Labs](https://diotlabs.daraghbyrne.me/docs/working-with-data/webhooks)
- 


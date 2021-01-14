---
marp: true
theme: itp

week: 11
category: lectures
title: APIs and JSON Overview
---

<!-- headingDivider: 2 -->

# JSON Overview

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

## Review

* We want our device to interact with services all over the internet--e.g. permanently store all heart rate data in the cloud, retrieve the weather forecast tomorrow, etc.
* **APIs** provide the mechanism we use to communicate with these other services
* **Webhooks** are created in the Particle cloud to connect our Argon to an API online 

## Examples of APIs

* Weather data - [https://weatherstack.com](https://weatherstack.com)
* Dictionaries - [Merriam-Webste](https://dictionaryapi.com/)
* Transit data - [Bay Area Rapid Transit](http://api.bart.gov)
* Useful lists of public APIs
  * [https://github.com/toddmotto/public-apis](https://github.com/toddmotto/public-apis)
  * [https://github.com/abhishekbanthia/Public-APIs](https://github.com/abhishekbanthia/Public-APIs)

## Review: Process to Interacting with Data from API

* Identify API you want to use (make account if necessary)
* Create a Particle webhook that interacts with the API
* Use `Particle.publish` to trigger webhook (review)
* Use `Particle.subscribe` to "listen" for response from webhook (optional)
* Create **function handler** that is used by `Particle.subscribe` to process JSON


## Where does JSON come in?

* Sending one temperature value to a webservice is not hard
* Sending dozens of sensor every second requires creating much more complex way of representing / store those values so we can send them to the cloud
* JSON is an excellent, common way we exchange complex data

## JSON (JavaScript Object Notation)

* Popular format for exchanging data with web services
  * XML is another
* JSON is useful because we can represent complex data with a simple string, and then share that data between two different services
* JSON is **not** a programming language; it is a way of **representing complex data as a string**
* Typically, programmers use library to read (parse) and write JSON

## JSON Overview

* JSON is a way of representing an object as a text string
* Built around key-value pair idea (like a dictionary or hash)
* Two data types
  * **objects** (single item denoted with `{`   `}`)
  * **arrays** (multiple items denoted with `[`   `]`)

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



## Useful Links

- [JsonParserGeneratorRK library](https://github.com/rickkas7/JsonParserGeneratorRK)
- [JSON Online Formatter](https://jsonformatter.org/json-pretty-print)
- [Mustache Tester](http://rickkas7.github.io/mustache/) for identifying JSON values

## Credit

- [Webhooks by DioT Labs](https://diotlabs.daraghbyrne.me/docs/working-with-data/webhooks)


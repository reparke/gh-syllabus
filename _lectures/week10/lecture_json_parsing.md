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

* We will use the library `JsonParserGeneratorRK` which is written specifically for Argon and can be installed from **Workbench**

* The library provides sample code for interacting with most APIs that provide JSON data
* The sample code allows for responses from the webhook that come in multiple parts
* Adapt the code below by customizing the code within `if(jsonParser.parse())`

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



## Useful Links

- [JsonParserGeneratorRK library](https://github.com/rickkas7/JsonParserGeneratorRK)
- [JSON Online Formatter](https://jsonformatter.org/json-pretty-print)
- [Mustache Tester](http://rickkas7.github.io/mustache/) for identifying JSON values

## Credit

- [Webhooks by DioT Labs](https://diotlabs.daraghbyrne.me/docs/working-with-data/webhooks)

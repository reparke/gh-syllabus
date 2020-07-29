---
marp: true
theme: itp

week: 10
category: lectures
title: Checking the Weather (Weather Stack integration)
---

<!-- headingDivider: 2 -->

# Checking the Weather (Weather Stack API)

![bg opacity:.5 left:50%](lecture_weatherstack_integration.assets/inset-agency-Fc-9Tc_6AMc-unsplash.jpg)

## Checking the Weather

* We can use temperature and humidity sensors to measure our the immediate environment around the Argon
* However we can not access weather data and forecast
* Enter weather APIs!

## Weather APIs

* Weather APIs provide real-time, historical, and forecast data
* Often these APIs have a free tier with limited data, and paid tier for more advanced data
* Examples
  * [Weather Stack](https://weatherstack.com/)
  * [Open Weather Map](https://openweathermap.org/api)
  * [National Weather Service](https://www.weather.gov/documentation/services-web-api)
  * [ClimaCell Weather API](https://www.climacell.co/weather-api/)



## Steps to Connect Argon and Weather Stack

1. Create an integration -> webhook on [Particle console](https://console.particle.io/integrations) 
2. Use `Particle.publish` to trigger webhook
3. Use `Particle.subscribe` to "listen" for response from webhook
4. Create **function handler** that is used by `Particle.subscribe` to process JSON

## Example: Request Weather Data for Specific Zip Code

* We will walk through the steps for obtaining basic weather data by zip code from Weather Stack
* Different APIs and the JSON response are all slightly different, but the general process is the same

## Step 1: Create Webhook to Connect to Weather Stack

**Particle integration settings**

![image-20200405005837141](lecture_weatherstack_integration.assets/image-20200405005837141.png)

## Part 2: Publish Event to Trigger Webhook

**Argon firmware**

```c++
void loop() {
  String data = "90089";	//USC zip code
  
   // Trigger the integration
  Particle.publish("JSONWeatherStack", data, PRIVATE);
 
   // Wait 60 seconds
  delay(60000);
}

```

## Part 3: Subscribe to JSON response from Weather Stack

**Argon firmware**

```c++
#include "JsonParserGeneratorRK.h"
JsonParser jsonParser;  // dynamic version: needs to be global if multi-part responses will be sent

String response;	//stores JSON webhook response
double temp;		//stores temperature

void setup() {
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/JSONWeatherStack", jsonSubscriptionHandler, MY_DEVICES);
}
```
## Part 4: Creating the function handler to receive the JSON

* `JsonParserGeneratorRK` provides some helping code to handle JSON responses that come in multiple pieces (*this is called Step 1* in the code below). We don't need to change
* *Step 2* in the code below is where we parse our unique 

**Argon firmware**

```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
  //Step 1 allows for webhook responses to be delivered in multple "chunks"; you don't need to change this
  int responseIndex = 0;
  const char *slashOffset = strrchr(event, '/');
  if (slashOffset)
    responseIndex = atoi(slashOffset + 1);
  if (responseIndex == 0)
    jsonParser.clear();
  jsonParser.addString(data);

  //Step 2 is where you can parse the actual data; your code goes in the IF
  if (jsonParser.parse()) {
  	/****** YOUR PARSING CODE GOES HERE ********/
```

## Part 4: Creating the function handler to receive the JSON

* JSON is simply a way of storing data, but there is no rule about HOW the data is organized
* Every API will use slightly different organizations
* Before we can parse Weather Stack JSON, we need to examine how it looks

## Weather Stack JSON Response

```json
{
  "request": {
    "type": "Zipcode",
    "query": "92831",
    "language": "en",
    "unit": "f"
  },
  "location": {
    "name": "Fullerton",
    "country": "USA",
    "region": "California",
    "lat": "33.887",
    "lon": "-117.895",
    "timezone_id": "America/Los_Angeles",
    "localtime": "2020-04-04 21:30",
    "localtime_epoch": 1586035800,
    "utc_offset": "-7.0"
  },
  "current": {
    "observation_time": "04:30 AM",
    "temperature": 61,
    "weather_code": 122,
    "weather_icons": [
      "https://assets.weatherstack.com/images/wsymbols01_png_64/wsymbol_0004_black_low_cloud.png"
    ],
    "weather_descriptions": [
      "Overcast"
    ],
    "wind_speed": 6,
    "wind_degree": 170,
    "wind_dir": "S",
    "pressure": 1012,
    "precip": 0,
    "humidity": 67,
    "cloudcover": 100,
    "feelslike": 61,
    "uv_index": 1,
    "visibility": 10,
    "is_day": "no"
  }
}
```

## Weather Stack JSON Response

![image-20200405005641533](lecture_weatherstack_integration.assets/image-20200405005641533.png)

## Weather Stack JSON Response

![image-20200405005641533](lecture_weatherstack_integration.assets/image-20200405005641533_temperature.png)

## Part 4: Creating the function handler to receive the JSON

```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
  /* ... rest of function code */
  if (jsonParser.parse()) {

    temp = jsonParser.getReference()
               .key("current")
               .key("temperature")
               .valueDouble();
   Serial.println("The weather in 90089 is " + description);
  }
}
```



## Resources

* [JsonParserGeneratorRK tutorial and overview](https://github.com/rickkas7/JsonParserGeneratorRK)
* [Mustache creation tool](http://rickkas7.github.io/mustache/) (helps with crafting response template)
* [JSON Validator and formatter](https://jsonformatter.org/) 
* [Weatherstack documentation](https://weatherstack.com/documentation)

## Credits

* Photo by [Inset Agency](https://unsplash.com/@inset_agency?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText) on [Unsplash](https://unsplash.com/s/photos/rain-umbrella?utm_source=unsplash&utm_medium=referral&utm_content=creditCopyText)



<!--Alternate weather integration service
http://303.itpwebdev.com/~molld/assignment6/list.html
http://303.itpwebdev.com/~molld/assignment6/main.js
 -->

#include "JsonParserGeneratorRK.h"

JsonParser jsonParser;          

void setup() {
  // Subscribe to the integration response event
  Serial.begin(9600);
  Particle.subscribe("hook-response/WeatherStackJSON", myHandler, MY_DEVICES);
}

void myHandler(const char *event, const char *data) {

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

  	
  
  }
}

void loop() {
  // Get some data
  String data = String(10);
  // Trigger the integration
  Particle.publish("WeatherStackJSON", data, PRIVATE);
  // Wait 60 seconds
  delay(60000);
}

/*
hook-response/WeatherStackJSON/0
{"request":{"type":"Zipcode","query":"90089","language":"en","unit":"f"},"location":{"name":"Los
Angeles","country":"USA","region":"California","lat":"34.018","lon":"-118.284","timezone_id":"America\/Los_Angeles","localtime":"2020-04-06
18:56","localtime_epoch":1586199360,"utc_offset":"-7.0"},"current":{"observation_time":"01:56
AM","temperature":63,"weather_code":116,"weather_icons":["https:\/\/assets.weatherstack.com\/images\/wsymbols01_png_64\/wsymbol_0002_sunny_intervals.png"],"weather_descriptions":["Partly
cloudy"],"wind_speed":4,"wind_degree":270,"wind_dir":"W","pressure":1014,"precip":0,"humidity":56,"cloudcover":75,"feelslike":63,"uv_index":3,"visibility":10,"is_day":"yes"}}
*/
<!-- headingDivider: 2 -->

# Parsing JSON with the built-in JSON Library

## JSON Example Data

- Consider the following JSON data is being received by the Argon

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



## Parsing JSON with a Built-in JSON Library

- For simple parsing of JSON, the Particle Device OS provides a some built in class
- Use the sample code below for your event handler 
* This example assumes the JSON response is small so you should use Mustache templates to have the webserver extract only the relevant data

## Publishing and Subscribing

```c++
void setup() {
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/JSONWeatherStack", jsonSubscriptionHandler,
                     MY_DEVICES);
}

void loop() {
  // Get some data
  String data = "92807";
  // Trigger the integration
  Particle.publish("JSONWeatherStack", data, PRIVATE);
  // Wait 60 seconds
  delay(60000);
}
```






## Example: Parsing with Built-in Classes

### Consider the following JSON

```json
{
    "city": "los angeles",
    "temperature": "78"
} 
```

## Configuring the event handler
- The JSON will be passed to the `data` parameter of event handler 
```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
```


Here is an example

```c++
void jsonSubscriptionHandler(const char *event, const char *data) {
  /* ... rest of function code */
    JSONValue outerObj = JSONValue::parseCopy(data);
	JSONObjectIterator iter(outerObj);
    String city;
    double temp;
    
    while (iter.next()) {
        if (iter.name() == "city") {
            city = String(iter.value().toString());
        }
        if (iter.name() == "temperature") {
            temp = iter.value().toDouble();
        }
    }
   Serial.println(city + " is " + String(temp));
  }
}
```

## Useful Links

- [JSONValue Reference](https://docs.particle.io/reference/device-os/api/json/parsing/#jsonvalue)
- [JSON Parsing Code Sample](https://community.particle.io/t/weather-api-tutorial/60528)
- [JSON Online Formatter](https://jsonformatter.org/json-pretty-print)
- [Particle Documentation: Mustache variable substitution](https://docs.particle.io/reference/cloud-apis/webhooks/#variable-substitution) 
- [Mustache Tester](http://rickkas7.github.io/mustache/) for identifying JSON values

## Credit

- [Webhooks by DioT Labs](https://diotlabs.daraghbyrne.me/docs/working-with-data/webhooks)

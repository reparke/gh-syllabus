---
marp: true
theme: itp

week: 9
category: lectures
title: Initial State Integration
---

<!-- headingDivider: 2 -->


# Initial State 

## Initial State ([https://initialstate.com](https://initialstate.com))

* Initial State is a web platform the IoT
* It allows you to send data from Argon to be stored at Initial State 
* You can complex graphs and dashboard with the values from your Argon
* Initial State can also send SMS and email alerts based on the data (though this requires a paid plan)

## Configuring Argon and Initial State 

* The following examples are provided as a quick reference
* More detailed steps were described in the lecture 

## General Steps to Connect Argon and Initial State 

1. Create account at  [https://initialstate.com](https://initialstate.com) 
2. Create **stream bucket** at [https://initialstate.com](https://initialstate.com)  
3. Create an integration -> webhook on [Particle console](https://console.particle.io/integrations) 
4. Write firmware sketch and flash Argon



## Example 1: Send Single Data Point from Argon to Initial State

**Initial State Settings**

<img src="lecture_initial_state_integration.assets/image-20200703180348874.png" alt="image-20200703180348874" style="width:500px;" />

## Example 1: Send Single Data Point from Argon to ThingSpeak

**Particle integration settings**

<img src="lecture_initial_state_integration.assets/image-20200703160032339.png" alt="image-20200703160032339" style="width:600px;" />

## Example 1: Send Single Data Point from Argon to ThingSpeak

**Particle integration settings**

JSON Data: `{{{PARTICLE_EVENT_VALUE}}}`

URL: `https://groker.init.st/api/events`

<img src="lecture_initial_state_integration.assets/image-20200703180944077.png" alt="image-20200703180944077" style="width:500px;" />

## Example 1: Send Single Data Point from Argon to ThingSpeak

**Particle integration settings**

<img src="lecture_initial_state_integration.assets/SNAGHTML22743719.PNG" alt="img" style="width:500px;" />



## Example 1: Send Single Data Point from Argon to Initial State

**Particle integration setting: HTTP Headers**

`Accept-Version`	>	`~0`

`X-IS-AccessKey`	>	*<<USE YOUR OWN API KEY>>>*

`X-IS-BucketKey`	>	*<<USE YOUR OWN BUCKET KEY>>>*




## Example 1: Send Single Data Point from Argon to Initial State

* Initial State expects data to be entered in JSON format

```json
{"key": "temp", "value": 32}
```

*Where `temp` is the your chosen data label, and `32` is the current value*



* Each time we send data to Initial State, we sent one single data point



## Example 1: Send Single Data Point from Argon to Initial State

**Argon code**

```c++
double temp;

void loop() {
  temp = 89;		//just example; temp should come from sensor
    
  String data = "{ \"key\":\"temperature\","   
                "\"value\":" + String(temp)+"}";
  // Trigger the integration
  Particle.publish("inital_state_json", String(temp), PRIVATE);
  delay(60000);	//use delay or millis to avoid publishing too frequently
}
```





## Example 2: Send Multiple Data Points from Argon to Initial State  

* Sending one data point at a time is valid, but is tedious if there are many values to send
* Since Initial State accepts JSON data, we send a JSON array with many data point

```json
[
 {"key":"temperature", "value":79.000000},
 {"key":"humidity", "value":22.000000},
 {"key":"weather", "value": "sunny"}
]
```

* The only difference in our setup is changing the formatting of the data we send

## Example 2: Send Multiple Data Points from Argon to Initial State  

**Argon code**

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




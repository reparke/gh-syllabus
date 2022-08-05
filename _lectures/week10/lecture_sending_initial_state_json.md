---
marp: true
theme: itp

week: 10
category: lectures
title: Sending Multiple Values to Initial State using JSON
---

<!-- headingDivider: 2 -->

# Sending Multiple Values to Initial State using JSON

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




## Sending Multiple Values  

* Sending one data point at a time is valid, but is tedious if there are many values to send
* Instead, we can send a JSON array with many data points
* JSON uses stores data in **key / value pairs** 
* JSON representation consists of **objects** and **arrays**

## JSON Format  

* The example below contains one JSON object `{...}`

```json
{"key": "temp", "value": 32}
```

*Where `temp` is the your chosen data label, and `32` is the current value*



* The example below contains one JSON array `[...]` containing three JSON objects `{...}`

```json
[
 {"key":"temperature", "value":79.000000},
 {"key":"humidity", "value":22.000000},
 {"key":"weather", "value": "sunny"}
]
```

*Where `temperature`, `humidity`, and `weather` are the data labels, and `22.000000`, `22.000000`, and `sunny` are the corresponding values*

## Creating JSON

- To create JSON data, you can use `String` variables to manually build the JSON data, or you can use a library.
- Generating this value as a `String` can be tedious so a library is recommendedis going to be messy
- [Instruction and examples for creating JSON manually with `String` variables`](lecture_json_creation_with_strings)
- [Instruction and examples for creating JSON with `ArduinoJson`](lecture_json_creation_with_arduinojson)

- [Instruction and examples for creating JSON with `JsonParserGeneratorRK`](lecture_json_creation_with_jsonparsergeneratorrk)

## Lab - Send Photoresistor Value to Initial State

* Connect photoresistor to Argon
* Read photoresistor value and send to InitialState
* **Determine light threshold (dark, ambient, bright) and send this value to InitialState**

## Lab - Send Photoresistor Value to Initial State

<img src="lecture_data_dashboards_initial_state_json.assets/photoresistor_and_fixed_resistor_bb.png" style="width:500px;" />



<!-- generate random values if students have projects already built 
	
-->

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
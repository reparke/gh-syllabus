---
marp: true
theme: itp

week: 13
category: lectures
title: RFID
---

<!-- headingDivider: 2 -->

# RFID 

*This content is incomplete but provides some code examples to get started using RFID*



## Radio Frequency ID 

* Wireless technology identify devices
* RFID **tags** can be embedded in objects 
  * Can be passive (no power needed) or active (power/battery needed)
* RFID **readers** send a electromagnetic pulse (*radio frequency*), which triggers the tag to emit a response

## RFID Uses

* Inventory tracking
  * items, clothing, parts for manufacturing
* Access and identificato
  * hotel key cards
  * ID cards (USC Card has an RFID tag)
* Contact-less payment
  * ApplePay uses NFC (near-field communication), which is a form of RFID

## RFID Sensor

* Sensors are designed to read cards are specific frequencies. 
  * Ours works at **13.56MHz**
* RFID sensors and cards must all use the same frequency
* Sensor communicates with Argon using **SPI**
* Operates at 3.3v

## RFID Cards and Fobs

<img src="lecture_rfid.assets/image-20200430155204041.png" alt="image-20200430155204041" style="width:300px" />



* Each key card and key fob have a **unique code** stored in their RFID tag (e.g. `OB 45 EA 0E`)

  


## Sensor Wiring (SPI)

| Sensor | Argon                  |
| ------ | ---------------------- |
| 3.3v   | 3.3v                   |
| Reset  | Any digital output pin |
| GND    | GND                    |
| IRQ    | -                      |
| MOSI   | MO                     |
| MISO   | MI                     |
| SCK    | SCK                    |
| SDA    | Any digital output pin |

<!--This sensor has an SDA pin, but it is SPI, not I2C. It is really a data pin -->

## RFID Library

  * `MFRC522` is an Argon compatible library

## Sample Code #1: Find the Card ID

* The following code is adapted from the library example
* Swiping key card in front of sensor will display the unique ID from each card
* Once the card's unique ID is known, that ID can be used for tracking or identification (copy it from Serial monitor)

## Sample Code #1: Setup

```c++
#include "MFRC522.h"

const int SS_PIN = D2;
const int RST_PIN = D3'

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 object

void setup() {
  Serial.begin(9600); 
  mfrc522.setSPIConfig();
  mfrc522.PCD_Init();  // Init MFRC522 card
}

```

## Sample Code #1: Testing and Resting

```c++
void loop() {
  // Look for new cards (exit if no card is found)
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  // Dump info about the card. PICC_HaltA() is automatically called.
  Serial.println("About to dump");
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

```

## Sample Code #2: Checking for Authorization

- Once you have the unique for one or more cards, that ID can then be used to provide authorized access
- Based on the card that is present, different outputs can be enable (e.g. doors unlocked)
- To proceed, you will need the unique ID form a card which will be something like  `OB 45 EA 0E`

## Sample Code #2: Setup

```c++
#include "MFRC522.h"

const int SS_PIN = D2;
const int RST_PIN = D3'
const String matchId = "OB 45 EA 0E"; //target id to match

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

void setup() {
  Serial.begin(9600); 
  mfrc522.setSPIConfig();
  mfrc522.PCD_Init();  // Init MFRC522 card
  Serial.println("Scan PICC to see UID and type...");
}
```

## Sample Code #2: Match ID

```c++
void loop() {
  String scanId = ""; 
  if (mfrc522.PICC_IsNewCardPresent()) { // check sensor
    if(mfrc522.PICC_ReadCardSerial()) { // check valid read
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        scanId += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        scanId += String(mfrc522.uid.uidByte[i], HEX));
      }
      if (scanId.equals(matchId)) {
          // this means scanned card and target card match
      }
    }
  }
}
```

## Wiring

* Sensor: [Amazon](https://www.amazon.com/gp/product/B01CSTW0IA)
* Key cards: [Amazon](https://www.amazon.com/gp/product/B01M0ACMDS)

## Credit

* [Sparkfun](https://www.sparkfun.com/products/13285)






























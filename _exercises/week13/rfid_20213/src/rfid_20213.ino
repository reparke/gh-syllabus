/*
Important:
MFRC522 library doesn't work with DeviceOS 3.1+.
You need to do the following two things

  1) change MIFARE_UnbrickUidSector method to return true
   in case of ELSE

  2) open project.properties and delete the dependency line for MFRC522.
  Particle cloud flash uses the cloud version of the library
  otherwise, meaning it won't use the local, changed version
*/

//#include <SPI.h>
#include "MFRC522.h"

#define SS_PIN A4
#define RST_PIN A5

String card1 = "0E 0D 8E 6A";  // use your own
String card2 = "DE 8A 8E 6A";  // use your own

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

unsigned long SCAN_DELAY = 1500;
unsigned long prevMillis = 0;

void setup() {
    Serial.begin(9600);  // Initialize serial communications with the PC
    mfrc522.setSPIConfig();

    mfrc522.PCD_Init();  // Init MFRC522 card
    Serial.println("Scan PICC to see UID and type...");
    pinMode(D7, OUTPUT);
}

void loop() {
    // String currentCard = "";
    // // we only want to read from the card when 1) card is present and 2) serial
    // // monitor is working
    // unsigned long curMillis = millis();
    // if (curMillis - prevMillis > SCAN_DELAY) {
    //     prevMillis = curMillis;
    //     if (mfrc522.PICC_IsNewCardPresent() == true &&
    //         mfrc522.PICC_ReadCardSerial() == true) {
    //         for (byte i = 0; i < mfrc522.uid.size; i++) {
    //             currentCard +=
    //                 String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //             currentCard += String(mfrc522.uid.uidByte[i], HEX);
    //         }
    //         Serial.println("The current card UID is: " + currentCard);
    //         // make string upper case
    //         currentCard.toUpperCase();
    //         // remove extra space from string
    //         currentCard.trim();
    //         Serial.println("The current card modified UID is: " + currentCard);

    //         // card1 will turn on D7, card2 will turn off D7
    //         if (currentCard == card1) {
    //             digitalWrite(D7, HIGH);
    //             Serial.println("Card1 found!");
    //         } else if (currentCard == card2) {
    //             digitalWrite(D7, LOW);
    //             Serial.println("Card2 found");
    //         }
    //     }
    // }

    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Dump debug info about the card. PICC_HaltA() is automatically called.
    Serial.println("found card...printing to serial");
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

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

/*
 * MFRC522 - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W
 AND R BY COOQROBOT.
 * The library file MFRC522.h has a wealth of useful info. Please read it.
 * The functions are documented in MFRC522.cpp.
 *
 * Based on code Dr.Leong   ( WWW.B2CQSHOP.COM )
 * Created by Miguel Balboa (circuitito.com), Jan, 2012.
 * Rewritten by Søren Thing Andersen (access.thing.dk), fall of 2013
 (Translation to English, refactored, comments, anti collision, cascade levels.)
 * Released into the public domain.
 *
 * Sample program showing how to read data from a PICC using a MFRC522 reader on
 the Arduino SPI interface.
 *-----------------------------------------------------------------------------
 empty_skull
 * Aggiunti pin per arduino Mega
 * add pin configuration for arduino mega
 * http://mac86project.altervista.org/
 -----------------------------------------------------------------------------
 Nicola Coppola
 * Pin layout should be as follows:
 * Signal     Pin       Pin
 *            SPARK     MFRC522 board
 * ---------------------------------------------------------------------------
 * Reset      ANY 		    RST
 * SPI SS     ANY     		SDA
 * SPI MOSI   MO          MOSI
 * SPI MISO   MI          MISO
 * SPI SCK    SCK          SCK
 *
 * The reader can be found on eBay for around 5 dollars. Search for "mf-rc522"
 on ebay.com.
 */

//#include <SPI.h>
#include "MFRC522.h"

#define SS_PIN A4
#define RST_PIN A5

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

unsigned long int scanDelay =
    1500;  // time to pause between reading cards to prevent continuous reads
unsigned long prevMillis = 0;
const int PIN_LED = D7;

String card1 = "4E B3 01 BF";
String card2 = "0E 8B 8E 6A";

void setup() {
    Serial.begin(9600);  // Initialize serial communications with the PC
    mfrc522.setSPIConfig();
    mfrc522.PCD_Init();  // Init MFRC522 card
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    unsigned long curMillis = millis();
    if ((curMillis - prevMillis) > scanDelay) {
        prevMillis = curMillis;  // update time

        // scanAndPrintCardId();
        // checkForMatch();
        controlLED();
    }
}

// use this to test scanner and to obtain card ID (printed to serial)
void scanAndPrintCardId() {
    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Dump debug info about the card. PICC_HaltA() is automatically called.
    Serial.println("About to dump");
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

void controlLED() {
    String scanId = "";
    if (mfrc522.PICC_IsNewCardPresent()) {    // check sensor
        if (mfrc522.PICC_ReadCardSerial()) {  // check valid read
            for (byte i = 0; i < mfrc522.uid.size; i++) {
                scanId += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                scanId += String(mfrc522.uid.uidByte[i], HEX);
            }
            scanId.toUpperCase();  // scanId will be lowercase
            scanId.trim();         // scanId has an intial leading " "
            Serial.println("size: " + String(mfrc522.uid.size));
            if (scanId == card1) {
                // this means scanned card and target card match
                digitalWrite(PIN_LED, HIGH);
                Serial.println("Card 1, light ON " + card1);

            } else if (scanId == card2) {
                Serial.println("Card 2, light OFF " + card2);
                digitalWrite(PIN_LED, LOW);

            } else {
                Serial.println("Card NOT recognized! ScanId = " + scanId);
            }
        }
    }
}

void checkForMatch() {
    String scanId = "";
    if (mfrc522.PICC_IsNewCardPresent()) {    // check sensor
        if (mfrc522.PICC_ReadCardSerial()) {  // check valid read
            for (byte i = 0; i < mfrc522.uid.size; i++) {
                scanId += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                scanId += String(mfrc522.uid.uidByte[i], HEX);
            }
            scanId.toUpperCase();  // scanId will be lowercase
            scanId.trim();         // scanId has an intial leading " "
            Serial.println("size: " + String(mfrc522.uid.size));
            if (scanId == card1) {
                // this means scanned card and target card match
                Serial.println("Card 1 recognized! " + card1);
            } else if (scanId == card2) {
                Serial.println("Card 2 recognized! " + card2);
            } else {
                Serial.println("Card NOT recognized! ScanId = " + scanId);
            }
        }
    }
}
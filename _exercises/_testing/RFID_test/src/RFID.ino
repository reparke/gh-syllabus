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
 * Reset      ANY (D2)		RST
 * SPI SS     ANY (A5)		SDA
 * SPI MOSI   MO          MOSI
 * SPI MISO   MI          MISO
 * SPI SCK    SCK          SCK
 *
 * The reader can be found on eBay for around 5 dollars. Search for "mf-rc522"
 on ebay.com.
 */

//#include <SPI.h>
#include "MFRC522.h"

#define SS_PIN D2
#define RST_PIN D3

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
//SYSTEM_MODE(MANUAL);


void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  Serial.println("in setup");
  mfrc522.setSPIConfig();
  Serial.println("finished config");
  mfrc522.PCD_Init();  // Init MFRC522 card
  Serial.println("Scan PICC to see UID and type...");
}

void loop() {
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

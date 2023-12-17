#include "Particle.h"

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

#include <MFRC522.h>
#include <SPI.h>

constexpr uint8_t RST_PIN = A5;  // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = A4;   // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

const String card1 = "0E 8B 8E 6A";  
const String card2 = "4E B3 01 BF";  

unsigned long prevMillis = 0;
unsigned long scanDelay = 2000;  // time between scans

void setup() {
    Serial.begin(9600);  // Initialize serial communications with the PC
    while (!Serial)
        ;  // Do nothing if no serial port is opened (added for Arduinos based
           // on ATMEGA32U4)
    SPI.begin();                        // Init SPI bus
    mfrc522.PCD_Init();                 // Init MFRC522
    mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card
                                        // Reader details
    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
    String scannedCard = "";

    unsigned long curMillis = millis();
    if (curMillis - prevMillis > scanDelay) {
        prevMillis = curMillis;
        if (mfrc522.PICC_IsNewCardPresent() == true) {
            if (mfrc522.PICC_ReadCardSerial() == true) {
                for (byte i = 0; i < mfrc522.uid.size; i++) {
                    if (mfrc522.uid.uidByte[i] < 0x10) {
                        scannedCard = scannedCard + " 0";
                    } else {
                        scannedCard = scannedCard + " ";
                    }
                    scannedCard =
                        scannedCard + String(mfrc522.uid.uidByte[i], HEX);
                }
                scannedCard.toUpperCase();
                scannedCard.trim();
                if (scannedCard == card1) {
                    Serial.println("Card 1 scanned");
                } else if (scannedCard == card2) {
                    Serial.println("Card 2 scanned");
                } else {
                    Serial.println("Card not recognized");
                }
            }
        }
    }
}

/*
 * Project myProject
 * Author: Your Name
 * Date:
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

#include <MFRC522.h>
#include <SPI.h>

constexpr uint8_t RST_PIN = A5;  // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = A4;   // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

const String card1 = "0E 8B 8E 6A";  // person1, jazz playlist
const String card2 = "4E B3 01 BF";  // person2, classical
const String card3 = "57 67 BA 60";

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
                // Serial.println("Scanned card: " + scannedCard);
                if (scannedCard == card1) {
                    Serial.println("Playlist Jazz");
                } else if (scannedCard == card2) {
                    Serial.println("Playlist classical");
                } else if (scannedCard == card3) {
                    Serial.println("Playlist EDM");
                } else {
                    Serial.println("Card not recognized");
                }
            }
        }
    }
}

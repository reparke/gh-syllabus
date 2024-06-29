#include "Particle.h"

SYSTEM_MODE(AUTOMATIC);
// SYSTEM_THREAD(ENABLED); //comment out

SerialLogHandler logHandler(LOG_LEVEL_WARN);

#include <MFRC522.h>
#include <SPI.h>

// constexpr uint8_t RST_PIN = 9;  // Configurable, see typical pin layout above
// constexpr uint8_t SS_PIN = 10;  // Configurable, see typical pin layout above
constexpr uint8_t RST_PIN = A1;  // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = A0;   // Configurable, see typical pin layout above

String card1 = "4E B3 01 BF";  // Rob card 1
String card2 = "57 67 BA 60";  // rob key fob

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

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

/*
  make sure sensor is ready for valid reading
      "read the uid" from the current card
        (requires to do some manipulation)
      compare to our stored card id
      print message if access or not
*/
void loop() {
    String scannedCard = "";
    mfrc522.serialn

    if (mfrc522.PICC_IsNewCardPresent() == true) {    // card is ready
        if (mfrc522.PICC_ReadCardSerial() == true) {  // card could read

            // UID
            // Serial.print(F("Card UID:"));
            for (byte i = 0; i < mfrc522.uid.size; i++) {
                if (mfrc522.uid.uidByte[i] < 0x10)
                    // Serial.print(F(" 0"));
                    scannedCard += " 0";
                else
                    scannedCard += " ";
                scannedCard += String(mfrc522.uid.uidByte[i], HEX);
                scannedCard.toUpperCase();
                scannedCard.trim(); //removes excess space
            }
            // Serial.println("Scanned card: " + scannedCard);
            if (scannedCard == card1) {
              Serial.println("Match card 1");
            }
            else if (scannedCard == card2) {
              Serial.println("Match card 2");
            }
            else {
              Serial.println("No match - not authorized");
            }
        }
    }


}

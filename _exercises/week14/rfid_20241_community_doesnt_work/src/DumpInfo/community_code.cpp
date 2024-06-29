//  Project:        Mobile RFID Attendence register
//                  A project by FireFli (PTY) LTD

//  Date:           October 2019
//  Compiled by:    Friedl Basson
//  Details:        Scan for UID's from RFID cards and posting via webhooks to,
//  UbiDots, mySQL DB or Google Sheets
//                  UPDATE: Display Cardholder name as apposed to UID.
//  Credits:        Special thanks to the Particle community for assisting and
//  making this project possible! Firmware:       V2.1.2

// System Mode// - comment out if you will be settng up WiFi via Particle app
// and do not need to connect to another Wireless network aftwer the fact
// SYSTEM_MODE(SEMI_AUTOMATIC);

// This #include statement was automatically added by the Particle IDE.

#include "RFID.h"

/* Define the pins used for the SS (SDA) and RST (reset) pins for BOTH hardware
 * and software SPI */
#define SS_PIN A0
#define RST_PIN A1

/* Define the pins used for the DATA OUT (MOSI), DATA IN (MISO) and CLOCK (SCK)
 * pins for SOFTWARE SPI ONLY */
#define MOSI_PIN D15
#define MISO_PIN D16
#define SCK_PIN D17

// Initialising RGB START  - RGB LED and buzzer is used as system status
// indicator
int redPin = D6; // not PWM
int greenPin = D5; // not PWM
int bluePin = D4; // not PWM
int buzzPin = A2; 
// Initializing RGB END

/* Create an instance of the RFID library */

RFID RC522(SS_PIN, RST_PIN);  // Hardware SPI

// const char* WEBHOOK_NAME = "rfid_uid";

// List of Card UIDs
char* allowedTags[] = {"0E 8B 8E 6A",  // Test Tag
                       "4E B3 01 BF"};

// List of names to associate with the matching tag IDs
char* tagName[] = {"tag1",  // Test Tag
                   "tag2"

};

String str;
char tagValue[16];

int numberOfTags = 294;  // Total number of tags used

void setup() {
    Serial.begin(9600);

    /* Initialise the RFID reader */
    RC522.init();

    delay(5000);

    digitalWrite(bluePin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
}

void loop()

{
    uint8_t i;

    /* Has a card been detected? */
    if (RC522.isCard()) {
        /* If so then get its serial number */
        RC522.readCardSerial();

        char CID[16];
        snprintf(CID, sizeof(CID), "%02X %02X %02X %02X", RC522.serNum[0],
                 RC522.serNum[1], RC522.serNum[2], RC522.serNum[3]);

        int iPos = findTag(CID);
    }

    delay(500);
}

int findTag(char tagValue[16]) {
    for (int thisCard = 0; thisCard < numberOfTags; thisCard++) {
        // Check if the tag value matches this row in the tag database
        if (strcmp(tagValue, allowedTags[thisCard]) == 0) {
            // The row in the database starts at 0, so add 1 to the result so
            // that the card ID starts from 1 instead (0 represents "no match")
            return (thisCard);
        }
    }
    // If we don't find the tag return a tag ID of 0 to show there was no match
    return -1;
}

//  Project:        Mobile RFID Attendence register 
//                  A project by FireFli (PTY) LTD

//  Date:           October 2019
//  Compiled by:    Friedl Basson
//  Details:        Scan for UID's from RFID cards and posting via webhooks to, UbiDots, mySQL DB or Google Sheets
//                  UPDATE: Display Cardholder name as apposed to UID.                    
//  Credits:        Special thanks to the Particle community for assisting and making this project possible!
//  Firmware:       V2.1.2



//System Mode// - comment out if you will be settng up WiFi via Particle app and do not need to connect to another Wireless network aftwer the fact
//SYSTEM_MODE(SEMI_AUTOMATIC);


// This #include statement was automatically added by the Particle IDE.
#include "RFID.h"
// #include <Ubidots.h>


/* Define the pins used for the SS (SDA) and RST (reset) pins for BOTH hardware and software SPI */
#define SS_PIN      A2      
#define RST_PIN     D2

/* Define the pins used for the DATA OUT (MOSI), DATA IN (MISO) and CLOCK (SCK) pins for SOFTWARE SPI ONLY */
#define MOSI_PIN    D3      
#define MISO_PIN    D4      
#define SCK_PIN     D5      


//Initialising RGB START  - RGB LED and buzzer is used as system status indicator
int redPin = D6;       
int greenPin = D1;    
int bluePin = D0;     
int buzzPin = D7;
//Initializing RGB END   


/* Create an instance of the RFID library */
#if defined(_USE_SOFT_SPI_)
    RFID RC522(SS_PIN, RST_PIN, MOSI_PIN, MISO_PIN, SCK_PIN);    // Software SPI
#else
    RFID RC522(SS_PIN, RST_PIN);                                 // Hardware SPI
#endif

//const char* WEBHOOK_NAME = "rfid_uid";
// const char* WEBHOOK_NAME = "Ubidots";
// Ubidots ubidots("webhook", UBI_PARTICLE);


// List of Card UIDs
char* allowedTags[] = {
"0E 8B 8E 6A", // Test Tag
"4E B3 01 BF" };

// List of names to associate with the matching tag IDs
 char* tagName[] = {
"Friedl", // Test Tag 
"LUKE LALIN"
 };



String str;
char tagValue[16];

int numberOfTags = 294; //Total number of tags used

void setup()
    {
         Serial.begin(9600);    
  
//  WiFi.listen();

        pinMode(redPin, OUTPUT);
        pinMode(greenPin, OUTPUT);
        pinMode(bluePin, OUTPUT);
        pinMode(buzzPin, OUTPUT);
    

// Setting credentials for new WiFi Connection
/*  
    This section is only needed if you want to connect to a new WiFi Network after initial setup
    This will only work if current WiFi credentials have been cleared.  
    Code will run ONLY ONCE on startup and set new crediatials specified.  Once new credentials is set, this code will not run again.
*/

// WiFi.on();

// if (!WiFi.hasCredentials()) {
// WiFi.setCredentials("Rhino Africa Office", "Pang01in", WPA2, WLAN_CIPHER_AES);      //Rhino Africa Office//Pang01in//WPA2/WLAN_CIPHER_AES
// }

// WiFi.connect();
// waitUntil(WiFi.ready);
// Particle.connect();

  
  
#if !defined(_USE_SOFT_SPI_)
  /* Enable the HW SPI interface */
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.begin();
#endif

  /* Initialise the RFID reader */
  RC522.init();

delay(5000);
            
            digitalWrite(bluePin, HIGH);
            digitalWrite(greenPin, HIGH);
            digitalWrite(redPin, LOW); 
}

void loop()

{
  uint8_t i;

  /* Has a card been detected? */
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();

  char CID[16]; 
  snprintf(CID, sizeof(CID)
          , "%02X %02X %02X %02X"
          , RC522.serNum[0]
          , RC522.serNum[1]
          , RC522.serNum[2]
          , RC522.serNum[3]
          );

    int iPos = findTag(CID);
  }
    

// Webhooks//
/*
RFID_WP = your webhook name
str = your data you want to publish
PRIVATE or PUBLIC
*/

//            Particle.publish("RFID_WP", str, PRIVATE);          //Publish Data to Wordpress DB
//            Particle.publish("XLS", str, PRIVATE);              // Publish Data to Google Sheets   


// /* Adds context key-value pairs */
   
 
 if (RC522.isCard())
  
  {

    RC522.readCardSerial();

 char CID[16]; 
 snprintf(CID, sizeof(CID)
          , "%02X %02X %02X %02X"
          , RC522.serNum[0]
          , RC522.serNum[1]
          , RC522.serNum[2]
          , RC522.serNum[3]
          ); 

            digitalWrite(bluePin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(redPin, HIGH);
            delay(1000);
            digitalWrite(bluePin, HIGH);
            digitalWrite(greenPin, HIGH);
            digitalWrite(redPin, LOW);
            digitalWrite(buzzPin, LOW);
    }

  delay(500);
}

int findTag(char tagValue[16]) 
{
    for (int thisCard = 0; thisCard < numberOfTags; thisCard++) {
// Check if the tag value matches this row in the tag database
        if(strcmp(tagValue, allowedTags[thisCard]) == 0)
        {
// The row in the database starts at 0, so add 1 to the result so
// that the card ID starts from 1 instead (0 represents "no match")
            return(thisCard);
        }
    }
// If we don't find the tag return a tag ID of 0 to show there was no match
return -1;
}
/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "f:/Github/ITP_348_Content_Public/_exercises/week01/find_mac_address/src/find_mac_address.ino"
 void setup();
void loop();
#line 1 "f:/Github/ITP_348_Content_Public/_exercises/week01/find_mac_address/src/find_mac_address.ino"
SYSTEM_MODE(MANUAL);
byte mac[6];  // the MAC address of your Wifi shield
int LED = D7;

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    WiFi.macAddress(mac);
}

void loop() {
    Serial.print("MAC: ");
    for (int i = 0; i < 6; i++) {
        Serial.printf("%02x%s", mac[i], i != 5 ? ":" : "");
    }
    Serial.println();

    // blink an LED - this is just here as a validation that it's working...
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(1000);
}

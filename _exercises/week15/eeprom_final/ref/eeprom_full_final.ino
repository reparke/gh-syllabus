// uint8 = 1 byte = 0-255
// int8 = 1 byte = -128 to 127
// uint16 = 2 bytes = 0 65,535
// int16 = 2 bytes = -32,768 to 32,767
// bool = 1 byte
// float = 4 bytes

/* 255 bytes in EEPROM

    The sum of sizeof variables in the structure != sizeof struct
        this is because compilers add padding for some variables like floats

        For example, the below example using a float has 7 bytes of variables,
        but the struct is 12 bytes

        Using uint8_t only, however, does result in sum  sizeof var = size struct
*/


int address = 0;
struct dataContainer {
    uint8_t version;
    uint8_t ledOn;          // 1 bytes
    // float temperature;      // 4 bytes
    uint8_t temperature;      // 4 bytes
    uint8_t buttonPresses;  // 1 byte
    // uint8_t temperature[10];    //
};
dataContainer container;

unsigned long prevMillis = 0;

void setup() {
    // EEPROM.clear();
    EEPROM.get(address, container);
    if (container.version != 0) {
        // EEPROM was empty -> initialize value
        container = {0, true, 0, 0};
    }
}

void loop() {
    unsigned long curMillis = millis();
    if (curMillis - prevMillis > 5000) {
        container.buttonPresses++;
        container.temperature = random(-50, 120);
        container.ledOn = random(0,1);
        printEepromData();
        // write eeprom data
        EEPROM.put(0, container);
        prevMillis = curMillis;
    }
}

void printEepromData() {
    Serial.println("Size of container: " + String(sizeof(container)));
    Serial.println("Size of version: " + String(sizeof(container.version)));
    Serial.println("Size of ledOn: " + String(sizeof(container.ledOn)));
    Serial.println("Size of temp: " +
                   String(sizeof(container.temperature)));
    Serial.println("Size of buttonPresses: " +
                   String(sizeof(container.buttonPresses)));

    Serial.println("\t**version: " + String(container.version));
    Serial.println("\t**ledOn: " + String(container.ledOn));
    Serial.println("\t**temperature: " + String(container.temperature));
    Serial.println("\t**buttonPresses: " + String(container.buttonPresses));
    Serial.println();
}
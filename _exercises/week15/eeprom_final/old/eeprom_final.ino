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

        Using uint8_t only, however, does result in sum  sizeof var = size
   struct

*/

/*
    Example:
        This example stores a temperature and num button presses to EEPROM
        Temp is randomly generated on button press
        Every 5 seconds, the data is written to EEPROM
    Wiring:
        Connect button to D2


*/

unsigned long prevMillis = 0;
const int PIN_BUTTON = D2;
int prevButtonVal = HIGH;

int address = 0;
struct dataContainer {
    uint8_t version;
    int temperature;    // 4 bytes
    int buttonPresses;  // 1 byte
    // uint8_t ledOn;          // 1 bytes
    // float temperature;      // 4 bytes
    // uint8_t temperature[10];    //
};
dataContainer container;

void setup() {
    // EEPROM.clear();
    pinMode(PIN_BUTTON, INPUT);
    EEPROM.get(address, container);
    if (container.version != 0) {
        // EEPROM was empty -> initialize value
        container = {0, 0, 0};
    }
}

void loop() {
    int currButtonVal = digitalRead(PIN_BUTTON);
    if (currButtonVal == HIGH && prevButtonVal == LOW) {
        container.buttonPresses++;
        container.temperature = random(-50, 120);
        Serial.println("\tbutton pressed!");
    }
    prevButtonVal = currButtonVal;

    unsigned long curMillis = millis();
    if (curMillis - prevMillis > 5000) {
        printEepromData();
        // write eeprom data
        EEPROM.put(0, container);
        prevMillis = curMillis;
    }
}

void printEepromData() {
    Serial.println("Sizes:");
    Serial.println("\tcontainer: " + String(sizeof(container)));
    Serial.println("\tversion: " + String(sizeof(container.version)));
    Serial.println("\ttemperature: " + String(sizeof(container.temperature)));
    Serial.println("\tbuttonPresses: " +
                   String(sizeof(container.buttonPresses)));

    Serial.println("Contents:");
    Serial.println("\tversion: " + String(container.version));
    Serial.println("\ttemperature: " + String(container.temperature));
    Serial.println("\tbuttonPresses: " + String(container.buttonPresses));
    Serial.println();
}
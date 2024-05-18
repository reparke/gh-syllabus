/*
 * Final Project
 * Author: Victoria Lawton
 * Date: 11 Mar 2024
 */

#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);


int lunge_set_count;
int cardio_minutes_count;
int stretch_minutes_count;

typedef struct {
    int check;  // value to check if data is valid
    int lunge_set_count;
    int cardio_minutes_count;
    int stretch_minutes_count;
} MemoryObject;

int check = 8;  // use this to see if restored memory is valid

void storeInMemory();
void retrieveFromMemory();

// void storeInMemory(int lunge, int cardio, int stretch) {
void storeInMemory() {
    // update memory if change in values
    MemoryObject memObj;
    memObj.check = check;  // copy check into the struct
    memObj.lunge_set_count = 4;
    memObj.cardio_minutes_count = 3;
    memObj.stretch_minutes_count = 2;

    EEPROM.put(0, memObj);
    Serial.println("values stored in memory");
}

void retrieveFromMemory() {
    MemoryObject memObj;
    EEPROM.get(0, memObj);
    if (memObj.check == check) {
        // if check matches --> valid data
        lunge_set_count = memObj.lunge_set_count;
        cardio_minutes_count = memObj.cardio_minutes_count;
        stretch_minutes_count = memObj.stretch_minutes_count;
        Serial.println("values restored from memory");
    } else {
        // memory data not valid --> initialize to 0
        lunge_set_count = 0;
        cardio_minutes_count = 0;
        stretch_minutes_count = 0;
        Serial.println("Using 0 for all values (memory not valid)");
    }
}

void setup() {
    retrieveFromMemory();
}

void loop() {
    delay(10000);
    lunge_set_count++;
    cardio_minutes_count++;
    stretch_minutes_count++;

    storeInMemory();
}

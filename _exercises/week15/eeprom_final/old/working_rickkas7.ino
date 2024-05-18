// EEPROM sample code
// EEPROM Documentation: https://docs.particle.io/reference/firmware/photon/#eeprom

#include "Particle.h"

void clearEEPROM(); // forward declaration

// This is just a list of 16 fish names from Wikipedia for testing
const char *fishNames[] = {"Aeneus corydoras", "African glass catfish", "African lungfish", "Aholehole",
						   "Airbreathing catfish", "Airsac catfish", "Alaska blackfish", "Albacore",
						   "Alewife", "Alfonsino", "Algae eater", "Alligatorfish",
						   "Alligator gar", "American sole", "Amur pike", "Anchovy"};

typedef struct {
	int a;
	float b;
	bool c;
} SimpleStruct;

void setup() {
	Serial.begin(9600);

	// clearEEPROM();
}


void loop() {
	int addr = 0;
	int intVal;

	// int
	{
		// You can get and put simple values like int, long, bool, etc. using get and put directly

		EEPROM.get(addr, intVal);
		Serial.printlnf("addr=%d, intVal=%d, sizeof(int)=%d", addr, intVal, sizeof(int));

		intVal++;
		EEPROM.put(addr, intVal);

		addr += sizeof(int);
	}
	// double
	{
		double doubleVal;

		// Same for float, double
		EEPROM.get(addr, doubleVal);
		Serial.printlnf("addr=%d, doubleVal=%lf, sizeof(doubleVal)=%d", addr, doubleVal, sizeof(doubleVal));

		doubleVal += 0.1;
		EEPROM.put(addr, doubleVal);

		addr += sizeof(doubleVal);
	}

	// Strings are a bit more of a pain because you have to know how much space you want to reserve.
	// In this example, we store a string of up to 15 characters, plus a null byte, in a 16 character buffer
	{
		const int STRING_BUF_SIZE = 16;
		char stringBuf[STRING_BUF_SIZE];

		EEPROM.get(addr, stringBuf);
		stringBuf[sizeof(stringBuf) - 1] = 0; // make sure it's null terminated

		// Initialize a String object from the buffer
		String str(stringBuf);

		Serial.printlnf("addr=%d, str=%s, sizeof(stringBuf)=%d", addr, str.c_str(), sizeof(stringBuf));

		str = String(fishNames[intVal & 0xf]);
		Serial.printlnf("next fish name=%s", str.c_str());

		// getBytes handles truncating the string if it's longer than the buffer.
		str.getBytes((unsigned char *)stringBuf, sizeof(stringBuf));
		EEPROM.put(addr, stringBuf);

		addr += sizeof(stringBuf);
	}

	// A simple structure
	{
		SimpleStruct data;

		// You can even store a small structure of values
		EEPROM.get(addr, data);
		Serial.printlnf("addr=%d, a=%d b=%f c=%d, sizeof(data)=%d", addr, data.a, data.b, data.c, sizeof(data));

		data.a += 2;
		data.b += 0.02;
		data.c = !data.c;

		EEPROM.put(addr, data);

		addr += sizeof(data);
	}
	Serial.println("--------");

	delay(30000);
}

void clearEEPROM() {
	for(int addr = 0; addr < 256; addr++) {
		EEPROM.write(addr, 0);
	}
}
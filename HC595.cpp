/*
 * 74HC595 chip driver for Wiring/Arduino.
 * File: HC595.cpp
 * Version: 1
 * Copyright (c) 2010 by Radek Hnilica
 * License: GPLv3
 * This code was tested with Arduino version 18.
 */
#include "WProgram.h"
#include "HC595.h"

/*
 * Constructor defines connection pins for the HC595 chip.
 */
HC595::HC595(int latchPin, int clockPin, int dataPin) {
	this->latchPin = latchPin;
	this->clockPin = clockPin;
	this->dataPin  = dataPin;

	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin,  OUTPUT);

	// Default values for pins.
	digitalWrite(latchPin, HIGH);
	//digitalWrite(clockPin, LOW);
	//digitalWrite(dataPin,  LOW);
}

void
HC595::writeByte(byte data) {
	byte counter;	// For counting bits in data.

	digitalWrite(this->latchPin, LOW);
	for (counter=8; counter; counter--) {
		digitalWrite(this->clockPin, LOW);
		digitalWrite(this->dataPin, data & 1);
		digitalWrite(this->clockPin, HIGH); // Strobe data bit.
		data >>= 1;	// Shift to get next data bit.
	}
	digitalWrite(this->latchPin, HIGH); // Strobe output.
}

/*
 * Library version information.
 */
int
HC595::version(void) {
	return 1;
}


/*
 * 74HC595 chip driver for Wiring/Arduino.
 * File: HC595.h
 * Version: 1
 * Copyright (c) 2010 by Radek Hnilica
 * License: GPLv3
 * This code was tested with Arduino version 18.
 */
#ifndef HC595_h
#define HC595_h
#include "WProgram.h"

// Interface description
class HC595 {
 public:
	HC595(int latchPin, int clockPin, int DataPin);
	void writeByte(byte data);
	int version(void);
 private:
	int latchPin;
	int clockPin;
	int dataPin;
};
#endif

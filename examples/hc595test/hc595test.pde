#include "HC595.h"

int  latchPin = 9;
int  clockPin = 11;
int  dataPin  = 10;

int  pocitadlo = 0;

HC595 chip(latchPin, clockPin, dataPin);

void setup(void) {
  pocitadlo = 0;
}

void loop(void) {
  chip.writeByte(~pocitadlo);
  pocitadlo++;
  delay(1000);
}

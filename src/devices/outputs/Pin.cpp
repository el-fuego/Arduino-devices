#include <Arduino.h>
#include "./Pin.h"


void PinOutput::init(unsigned char pin) {
  pinMode(pin, OUTPUT);
}

void PinOutput::write(unsigned char pin, bool value) {
  digitalWrite(pin, value);
}

void PinOutput::write(unsigned char pin, uint16_t value) {
  analogWrite(pin, value);
}

PinOutput *pinOutput = new PinOutput;
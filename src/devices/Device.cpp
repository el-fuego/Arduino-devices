#include <Arduino.h>
#include "./Device.h"
#include "./outputs/Pin.h"


Device::Device(unsigned char _pin) : pin(_pin), output(pinOutput) {};
Device::Device(BaseOutput *_output, unsigned char _pin) : output(_output), pin(_pin) {};

void Device::makeOutputInverted() {
  isOutputInverted = true;
}

void Device::writeToPin() {
  bool pinValue;

  if (isEnabled) {
    pinValue = isOutputInverted ? LOW : HIGH;
  } else {
    pinValue = isOutputInverted ? HIGH : LOW;
  }
  output->write(pin, pinValue);
}

void Device::init() {
  output->init(pin);

  if (isOutputInverted) {
    writeToPin();
  }
}
#include <Arduino.h>
#include "./IntensityControl.h"


IntensityControl::IntensityControl(
  unsigned char _pin,
   unsigned int &_percentage,
    unsigned int _rangeStart
    ) :
     Device(_pin),
      percentage(_percentage),
       rangeStart(_rangeStart) {};

IntensityControl::IntensityControl(
  BaseOutput *_output,
   unsigned char _pin,
    unsigned int &_percentage,
     unsigned int _rangeStart
     ) :
      Device(_pin),
       percentage(_percentage),
        rangeStart(_rangeStart) {};

uint16_t IntensityControl::getPinValue() {
  return (rangeStart + percentage * (100 - rangeStart) / 100) * output->maxValue / 100;
}

void IntensityControl::writeToPin() {
  uint16_t pinValue = isEnabled ? getPinValue() : 0;

  output->write(pin, (uint16_t)(isOutputInverted ? output->maxValue - pinValue : pinValue));
}

void IntensityControl::update() {
  if (previousPercentage != percentage) {
    isEnabled = percentage > 0;
    writeToPin();

    previousPercentage = percentage;
  }
};
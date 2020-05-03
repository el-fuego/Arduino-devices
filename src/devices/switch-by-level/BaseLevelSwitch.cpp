#include <Arduino.h>
#include "./BaseLevelSwitch.h"


BaseLevelSwitch::BaseLevelSwitch(
  unsigned char _pin,
   unsigned int &_demandedValue,
    unsigned char &_currentValue
    ) :
     Device(_pin),
      demandedValue(_demandedValue),
       currentValue(_currentValue) {};

BaseLevelSwitch::BaseLevelSwitch(
  BaseOutput *_output,
   unsigned char _pin,
    unsigned int &_demandedValue,
     unsigned char &_currentValue
     ) :
      Device(_output, _pin),
       demandedValue(_demandedValue),
        currentValue(_currentValue) {};

BaseLevelSwitch::BaseLevelSwitch(
  unsigned char _pin,
   unsigned int &_demandedValue,
    unsigned char &_currentValue,
     const unsigned char _minDifference
     ) :
      Device(_pin),
       demandedValue(_demandedValue),
        currentValue(_currentValue),
         minDifference(_minDifference) {};

BaseLevelSwitch::BaseLevelSwitch(
  BaseOutput *_output,
   unsigned char _pin,
    unsigned int &_demandedValue,
     unsigned char &_currentValue,
      const unsigned char _minDifference
      ) :
       Device(_output, _pin),
        demandedValue(_demandedValue),
         currentValue(_currentValue),
          minDifference(_minDifference) {};

void BaseLevelSwitch::writeToPin() {
  Device::writeToPin();
  toggledAt = millis();
};

bool BaseLevelSwitch::canMeasure() {
  return toggledAt == 0 || abs(millis() - toggledAt) > minMeasureInterval;
};

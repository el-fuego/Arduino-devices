#include <Arduino.h>
#include "./ClockTimeIntervalSwitch.h"


ClockTimeIntervalSwitch::ClockTimeIntervalSwitch(
  unsigned char _pin,
  unsigned int &_fromMinutes,
  unsigned int &_toMinutes
) :
    Device(_pin),
    fromMinutes(_fromMinutes),
    toMinutes(_toMinutes) {};

ClockTimeIntervalSwitch::ClockTimeIntervalSwitch(
  BaseOutput *_output,
  unsigned char _pin,
  unsigned int &_fromMinutes,
  unsigned int &_toMinutes
) :
    Device(_output, _pin),
    fromMinutes(_fromMinutes),
    toMinutes(_toMinutes) {};
    
void ClockTimeIntervalSwitch::update(unsigned int currentTimeMinutes) {
  isEnabled = currentTimeMinutes > fromMinutes && currentTimeMinutes < toMinutes;
  writeToPin();
};

#include <Arduino.h>
#include "./TimeIntervalSwitch.h"


TimeIntervalSwitch::TimeIntervalSwitch(
  unsigned char _pin,
   TimeInterval &_interval,
    DS3231_Sensor &_clockSensor
    ) :
     Device(_pin),
      interval(_interval),
       clockSensor(_clockSensor) {};
    
void TimeIntervalSwitch::update() {
  unsigned int currentTimeMins = clockSensor.getIntTime();
  
  isEnabled = currentTimeMins > interval.from && currentTimeMins < interval.to;
  writeToPin();
};

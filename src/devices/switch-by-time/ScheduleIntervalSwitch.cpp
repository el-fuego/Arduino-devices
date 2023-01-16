#include <Arduino.h>
#include "./ScheduleIntervalSwitch.h"


ScheduleIntervalSwitch::ScheduleIntervalSwitch(
  unsigned char _pin,
   unsigned int &_enableForMinutes,
   unsigned int &_periodMinutes
    ) : Device(_pin),
      enableForMinutes(_enableForMinutes) ,
      periodMinutes(_periodMinutes) {};

ScheduleIntervalSwitch::ScheduleIntervalSwitch(
  BaseOutput *_output,
   unsigned char _pin,
   unsigned int &_enableForMinutes,
   unsigned int &_periodMinutes
     ) : Device(_output, _pin),
      enableForMinutes(_enableForMinutes) ,
      periodMinutes(_periodMinutes) {};
    
void ScheduleIntervalSwitch::update(uint32_t currentEpochMinutes) {
  unsigned int currentTimeInPeriod = currentEpochMinutes % periodMinutes;

  isEnabled = currentTimeInPeriod < enableForMinutes;
  writeToPin();
};

#include <Arduino.h>
#include "./ScheduleIntervalSwitch.h"


ScheduleIntervalSwitch::ScheduleIntervalSwitch(
  unsigned char _pin,
   ScheduleInterval &_interval,
    DS3231_Sensor &_clockSensor
    ) : Device(_pin),
     interval(_interval),
      clockSensor(_clockSensor) {};

ScheduleIntervalSwitch::ScheduleIntervalSwitch(
  BaseOutput *_output,
   unsigned char _pin,
    ScheduleInterval &_interval,
     DS3231_Sensor &_clockSensor
     ) : Device(_output, _pin),
      interval(_interval),
       clockSensor(_clockSensor) {};
    
void ScheduleIntervalSwitch::update() {
  unsigned int currentTimeInPeriod = clockSensor.toEpochMinutes() % interval.period;

  isEnabled = currentTimeInPeriod < interval.enableFor;
  writeToPin();
};

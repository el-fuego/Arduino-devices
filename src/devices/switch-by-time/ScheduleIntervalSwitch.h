#ifndef SCHEDULE_INTERVAL_SWITCH_H
#define SCHEDULE_INTERVAL_SWITCH_H

#include "../Device.h"
#include "../../sensors/clocks/DS3231.h"


struct ScheduleInterval {
  unsigned int enableFor; // sec
  unsigned int period; // sec
};

/**
* Enable your device for enableFor seconds each period in seconds
**/
class ScheduleIntervalSwitch: public Device {
  private:
    ScheduleInterval &interval;
    DS3231_Sensor &clockSensor;
  public:
    ScheduleIntervalSwitch(unsigned char _pin, ScheduleInterval &_interval, DS3231_Sensor &_clockSensor);
    ScheduleIntervalSwitch(BaseOutput *_output, unsigned char _pin, ScheduleInterval &_interval, DS3231_Sensor &_clockSensor);
    void update();
};

#endif
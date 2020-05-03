#ifndef TIME_INTERVAL_SWITCH_H
#define TIME_INTERVAL_SWITCH_H

#include "../Device.h"
#include "../../sensors/clocks/DS3231.h"


struct TimeInterval {
  unsigned int from; // Time in minutes
  unsigned int to; // Time in minutes
};


/**
* Enable your device in specified time interval
**/
class TimeIntervalSwitch: public Device {
  private:
    TimeInterval &interval;
    DS3231_Sensor &clockSensor;
  public:
    TimeIntervalSwitch(unsigned char _pin, TimeInterval &_interval, DS3231_Sensor &_clockSensor);
    TimeIntervalSwitch(BaseOutput *_output, unsigned char _pin, TimeInterval &_interval, DS3231_Sensor &_clockSensor);
    void update();
};

#endif
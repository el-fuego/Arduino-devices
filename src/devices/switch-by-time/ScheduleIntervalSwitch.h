#ifndef SCHEDULE_INTERVAL_SWITCH_H
#define SCHEDULE_INTERVAL_SWITCH_H

#include "../Device.h"
#include "../../sensors/clocks/DS3231.h"


/**
* Enable your device for enableFor seconds each period in seconds
**/
class ScheduleIntervalSwitch: public Device {
  public:
    unsigned int enableForMinutes;
    unsigned int periodMinutes;
    ScheduleIntervalSwitch(unsigned char _pin, unsigned int &_enableForMinutes, unsigned int &_periodMinutes);
    ScheduleIntervalSwitch(BaseOutput *_output, unsigned char _pin, unsigned int &_enableForMinutes, unsigned int &_periodMinutes);
    void update(uint32_t currentEpochMinutes);
};

#endif
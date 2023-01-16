#ifndef TIME_INTERVAL_SWITCH_H
#define TIME_INTERVAL_SWITCH_H

#include "../Device.h"
#include "../../sensors/clocks/DS3231.h"

/**
* Enable your device in specified time interval
**/
class ClockTimeIntervalSwitch: public Device {
  public:
    unsigned int fromMinutes;
    unsigned int toMinutes;
    ClockTimeIntervalSwitch(unsigned char _pin, unsigned int &_fromMinutes, unsigned int &_toMinutes);
    ClockTimeIntervalSwitch(BaseOutput *_output, unsigned char _pin, unsigned int &_fromMinutes, unsigned int &_toMinutes);
    void update(unsigned int currentTimeMinutes);
};

#endif
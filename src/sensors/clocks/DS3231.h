#ifndef DS3231_SENSOR_H
#define DS3231_SENSOR_H

#include "Sodaq_DS3231.h"
#include "../Sensor.h"


/**
* Clock sensor
**/
class DS3231_Sensor: public Sensor {
  public:
    DateTime dateTime;
    void init();
    void update();
    unsigned int getIntTime();
    uint32_t toEpochMinutes();
};

#endif
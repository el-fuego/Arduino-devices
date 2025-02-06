#ifndef MILLIS_CLOCK_SENSOR_H
#define MILLIS_CLOCK_SENSOR_H

#include "../Sensor.h"


/**
* Clock sensor
**/
class MillisClock_Sensor: public Sensor {
  public:
    unsigned long timeFromStart;
    void init() {};
    void update();
    unsigned int getIntTime();
    uint32_t toEpochMinutes();
};

#endif
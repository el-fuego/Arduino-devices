#ifndef BASE_DHT_SENSOR_H
#define BASE_DHT_SENSOR_H

#include <Arduino.h>
#include "../Sensor.h"


/**
* Temperature, Humidity Base sensor
**/
class BaseDHT: public Sensor {
  protected:
    unsigned long updatedAt = 0;
    bool canUpdate();
  public:
    unsigned char humidity;
    unsigned char temperature;
    unsigned char pressure;
};

#endif
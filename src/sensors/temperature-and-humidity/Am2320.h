#ifndef Am2320_SENSOR_H
#define Am2320_SENSOR_H

#include <Adafruit_AM2320.h>
#include "./BaseDHT.h"


/**
* Temperature and Humidity sensor
**/
class Am2320_Sensor: public BaseDHT {
  private:
    Adafruit_AM2320 driver;
  public:
    Am2320_Sensor();
    void init();
    void update();
};

#endif
#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

#include <SimpleDHT.h>
#include "./BaseDHT.h"


/**
* Temperature and Humidity sensor
**/
class DHT11_Sensor: public BaseDHT {
  private:
    SimpleDHT11 driver;
    const unsigned char pin;
  public:
    DHT11_Sensor(unsigned char _pin);
    void init();
    void update();
};

#endif
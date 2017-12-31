#ifndef Si7021_SENSOR_H
#define Si7021_SENSOR_H

#include <Adafruit_Si7021.h>
#include "./BaseDHT.h"


/**
* Temperature and Humidity sensor
**/
class Si7021_Sensor: public BaseDHT {
  private:
    Adafruit_Si7021 driver;
    const unsigned char pin;
  public:
    Si7021_Sensor();
    unsigned char humidity;
    unsigned char temperature;
  	void init();
    void update();
};

#endif;
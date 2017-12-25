#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

#include <SimpleDHT.h>
#include "../Sensor.h"


/**
* Temperature and Humidity sensor
**/
class DHT11_Sensor: public Sensor {
  private:
    SimpleDHT11 driver;
    unsigned long updatedAt = 0;
    const unsigned char pin;
  public:
    DHT11_Sensor(unsigned char _pin);
    unsigned char humidity;
    unsigned char temperature;
  	void init();
    void update();
};

#endif;
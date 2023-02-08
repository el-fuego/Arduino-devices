#ifndef DALLAS_TEMPERATURE_SENSOR_H
#define DALLAS_TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "./BaseDHT.h"

/**
* Temperature and Humidity sensor
**/
class DallasTemperature_Sensor: public BaseDHT {
  private:
    DallasTemperature driver;
    OneWire *oneWire;
    uint8_t *address;
    // 9 provide smallest request time, but resolution at 0.5*C, so using closest yet slower
    unsigned char resolution = 10;
  public:
    DallasTemperature_Sensor(OneWire *_oneWire, uint8_t* _address);
    DallasTemperature_Sensor(OneWire *_oneWire, uint8_t* _address, unsigned char _resolution);
    void init();
    void update();
};

#endif
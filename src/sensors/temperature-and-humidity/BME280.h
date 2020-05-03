#ifndef BME280_SENSOR_H
#define BME280_SENSOR_H

#include <BME280I2C.h>
#include <Wire.h>
#include "./BaseDHT.h"


/**
* Temperature, Humidity and Pressure sensor
**/
class BME280_Sensor: public BaseDHT {
  private:
    BME280I2C driver;
    BME280I2C::I2CAddr address = BME280I2C::I2CAddr_0x76;
  public:
    BME280_Sensor();
    BME280_Sensor(BME280I2C::I2CAddr _address);
    unsigned char pressure;
    void init();
    void update();
};

#endif
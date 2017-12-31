#include <Arduino.h>
#include "./BME280.h"


BME280_Sensor::BME280_Sensor() {};

BME280_Sensor::BME280_Sensor(BME280I2C::I2CAddr _address) : address(_address) {};

void BME280_Sensor::init() {
  Wire.begin();
  hasError = !driver.begin();

  BME280I2C::Settings settings(
     BME280::OSR_X1,
     BME280::OSR_X1,
     BME280::OSR_X1,
     BME280::Mode_Forced,
     BME280::StandbyTime_1000ms,
     BME280::Filter_16,
     BME280::SpiEnable_False,
     address
  );

  driver.setSettings(settings);
};

void BME280_Sensor::update() {
  if (!canUpdate()) {
    return;
  }

  float temp, hum, pres;
  driver.read(pres, temp, hum);

  updatedAt = millis();
  pressure = static_cast<int>(pres);
  temperature = static_cast<int>(temp);
  humidity = static_cast<int>(hum);

  hasError = !temperature || !humidity;
};


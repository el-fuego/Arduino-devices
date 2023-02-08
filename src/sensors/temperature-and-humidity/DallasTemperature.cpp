#include "./DallasTemperature.h"

DallasTemperature_Sensor::DallasTemperature_Sensor(OneWire* _oneWire, uint8_t* _address) :
  oneWire(_oneWire),
  address(_address)
  {};
DallasTemperature_Sensor::DallasTemperature_Sensor(OneWire* _oneWire, uint8_t* _address, unsigned char _resolution) :
  oneWire(_oneWire),
  address(_address),
  resolution(_resolution)
  {};

void DallasTemperature_Sensor::init() {
  driver.begin();
  driver.setWaitForConversion(false);

  driver.setResolution(address, resolution);
  driver.requestTemperaturesByAddress(address);
};

void DallasTemperature_Sensor::update() {
  if (!canUpdate()) {
    return;
  }

  updatedAt = millis();
  temperature = static_cast<int>(driver.getTempC(address));
  driver.requestTemperaturesByAddress(address);
};


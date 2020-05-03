#include "./Am2320.h"


Am2320_Sensor::Am2320_Sensor() {};

void Am2320_Sensor::init() {
  hasError = !driver.begin();
};

void Am2320_Sensor::update() {
  if (!canUpdate()) {
    return;
  }

  updatedAt = millis();
  temperature = static_cast<int>(driver.readTemperature());
  humidity = static_cast<int>(driver.readHumidity());

  hasError = !temperature || !humidity;
};


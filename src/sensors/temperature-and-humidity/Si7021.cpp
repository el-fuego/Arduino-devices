#include "./Si7021.h"


Si7021_Sensor::Si7021_Sensor() {};

void Si7021_Sensor::init() {
  hasError = !driver.begin();
};

void Si7021_Sensor::update() {
  if (!canUpdate()) {
    return;
  }

  updatedAt = millis();
  temperature = static_cast<int>(driver.readTemperature());
  humidity = static_cast<int>(driver.readHumidity());

  hasError = !temperature || !humidity;
};


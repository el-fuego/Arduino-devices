#include "./DHT11.h"


DHT11_Sensor::DHT11_Sensor(unsigned char _pin) : pin(_pin) {};

void DHT11_Sensor::init() {};

void DHT11_Sensor::update() {
  if (!canUpdate()) {
    return;
  }

  updatedAt = millis();
  hasError = driver.read(pin, &temperature, &humidity, NULL);
};


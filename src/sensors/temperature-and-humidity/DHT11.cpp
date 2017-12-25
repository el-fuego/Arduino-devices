#include "./DHT11.h"

#define DHT_UPDATE_INTERVAL 1000


DHT11_Sensor::DHT11_Sensor(unsigned char _pin) : pin(_pin) {};

void DHT11_Sensor::init() {};

void DHT11_Sensor::update() {
  unsigned long currentMillis = millis();
  if (currentMillis < updatedAt) {
  	updatedAt = 0;
  }
  if (currentMillis - updatedAt < DHT_UPDATE_INTERVAL) {
    return;
  }

  updatedAt = currentMillis;
  hasError = driver.read(pin, &temperature, &humidity, NULL);
};


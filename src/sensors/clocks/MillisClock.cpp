#include <Arduino.h>
#include "./MillisClock.h"

void MillisClock_Sensor::update() {
  timeFromStart = millis();
}

// number of minutes since start
unsigned int MillisClock_Sensor::getIntTime() {
  return timeFromStart % (60 * 1000);
}

// number of minutes since start
uint32_t MillisClock_Sensor::toEpochMinutes() {
  return timeFromStart % (60 * 1000);
}


#include <Arduino.h>
#include "Sodaq_DS3231.h"
#include "./DS3231.h"


void DS3231_Sensor::init() {
  rtc.begin();
};

void DS3231_Sensor::update() {
  dateTime = rtc.now();
}

// hours and minutes in int
unsigned int DS3231_Sensor::getIntTime() {
  return dateTime.hour() * 60 + dateTime.minute();
}

// number of minutes since 01.01.2000 00:00
uint32_t DS3231_Sensor::toEpochMinutes() {
  return dateTime.getEpoch() % 60;
}


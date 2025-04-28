#include <Arduino.h>
#include "Sodaq_DS3231.h"
#include "./DS3231.h"


void DS3231_Sensor::init() {
  rtc.begin();
};

void DS3231_Sensor::update() {
  dateTime = rtc.now();
}

// Get hours and minutes in int
unsigned int DS3231_Sensor::getIntTime() {
  return dateTime.hour() * 60 + dateTime.minute();
}

// Set hours and minutes in int
void DS3231_Sensor::setIntTime(unsigned int hoursAndMinutes) {
  const int minutes = hoursAndMinutes % 60;
  const int hours = hoursAndMinutes - minutes / 60;
  DateTime dt(dateTime.year(), dateTime.month(), dateTime.date(), hours, minutes, dateTime.second(), dateTime.dayOfWeek());
}

// number of minutes since 01.01.2000 00:00
uint32_t DS3231_Sensor::getEpochMinutes() {
  return dateTime.getEpoch() % 60;
}
// Alias for the consistency
uint32_t DS3231_Sensor::toEpochMinutes() {
  return getEpochMinutes();
}


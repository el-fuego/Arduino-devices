/*
 ScheduleIntervalSwitch usage example
 Will enable pump by schedule
*/

#include <Arduino-devices.h>


#define WATER_PUMP_PIN 13 // Set your actual pin number
// enable for 1 minute every 30 minutes
unsigned int wateringEnabledForMinutes = 1;
unsigned int wateringPeriodMinutes = 30;

DS3231_Sensor clock; // Create clock, connected to I2C
ScheduleIntervalSwitch waterPump(WATER_PUMP_PIN, wateringEnabledForMinutes, wateringPeriodMinutes); // Create device

void setup() {
  clock.init(); // Sensor initialization
  waterPump.init(); // Device initialization
}

void loop() {
  clock.update(); // Update current time
  waterPump.update(clock.toEpochMinutes()); // Will turn ON|OFF your device, basing on wateringInterval
}
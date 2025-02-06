/*
 ClockTimeIntervalSwitch usage example
 Will enable lamp by in specific time range
*/

#include <Arduino-devices.h>
#include "devices/switch-by-time/ClockTimeIntervalSwitch.h"


#define LAMP_PIN 13 // Set your actual pin number
// enable from 10AM till 6PM
unsigned int lighteningFromMinutes = 10*60;
unsigned int lighteningToMinutes = 18*60;

DS3231_Sensor clock; // Create clock, connected to I2C
ClockTimeIntervalSwitch lamp(LAMP_PIN, lighteningFromMinutes, lighteningToMinutes); // Create device

void setup() {
  clock.init(); // Sensor initialization
  lamp.init(); // Device initialization
}

void loop() {
  clock.update(); // Update current time
  lamp.update(clock.getIntTime()); // Will turn ON your device in lighteningInterval range
}

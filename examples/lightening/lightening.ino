/*
 TimeIntervalSwitch usage example
 Will enable lamp by in specific time range
*/

#include <Arduino-devices.h>


#define LAMP_PIN 13 // Set your actual pin number
TimeInterval lighteningInterval = { 10*60, 18*60 }; // enable from 10AM till 6PM

DS3231_Sensor clock; // Create clock, connected to I2C
TimeIntervalSwitch lamp(LAMP_PIN, lighteningInterval, clock); // Create device

void setup() {
  clock.init(); // Sensor initialization
  lamp.init(); // Device initialization
}

void loop() {
  clock.update(); // Update current time
  lamp.update(); // Will turn ON your device in lighteningInterval range
}
/*
 TurnOnWhenHigher usage example
 Will cool the air if it is too hot
*/

#include <Arduino-devices.h>
#include "devices/switch-by-level/TurnOnWhenHigher.h"


#define TEMPERATURE_SENSOR_PIN 2 // Set your actual pin number
#define AIR_CONDITIONER_PIN 13 // Set your actual pin number
unsigned int demandedTemperature = 23; // Setup demanded value

DHT11_Sensor temperatureAndHumiditySensor(TEMPERATURE_SENSOR_PIN); // Create sensor
TurnOnWhenHigher airConditioner(AIR_CONDITIONER_PIN, demandedTemperature, temperatureAndHumiditySensor.temperature); // Create device

void setup() {
  temperatureAndHumiditySensor.init(); // Sensor initialization
  airConditioner.init(); // Device initialization
}

void loop() {
  temperatureAndHumiditySensor.update(); // Update temperature value
  airConditioner.update(); // Will turn ON your device, if currentTemperature > DEMANDED_TEMPERATURE

  delay(5000); // Wait some time
}

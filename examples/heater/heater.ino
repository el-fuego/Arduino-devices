/*
 TurnOnWhenLower usage example
 Will heat the air if it is too cool
*/

#include <Arduino-devices.h>


#define TEMPERATURE_SENSOR_PIN 2 // Set your actual pin number
#define HEATER_PIN 13 // Set your actual pin number
unsigned int demandedTemperature = 23; // Setup demanded value

DHT11_Sensor temperatureAndHumiditySensor(TEMPERATURE_SENSOR_PIN); // Create sensor
TurnOnWhenLower heater(HEATER_PIN, demandedTemperature, temperatureAndHumiditySensor.temperature); // Create device

void setup() {
  temperatureAndHumiditySensor.init(); // Sensor initialization
  heater.init(); // Device initialization
}

void loop() {
  temperatureAndHumiditySensor.update(); // Update temperature value
  heater.update(); // Will turn ON your device, if currentTemperature > DEMANDED_TEMPERATURE

  delay(5000); // Wait some time
}
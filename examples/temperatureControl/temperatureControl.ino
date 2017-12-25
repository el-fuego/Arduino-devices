/*
 TurnOnWhenHigher, TurnOnWhenLower with minDifference usage example
 Will heat or cool the air in close to demanded value
*/

#include <Arduino-devices.h>


#define TEMPERATURE_SENSOR_PIN 2 // Set your actual pin number
#define AIR_CONDITIONER_PIN 12 // Set your actual pin number
#define HEATER_PIN 13 // Set your actual pin number
#define TEMPERATURE_RANGE 6 // No operation range in degrees. Your devices will be turned off, if value is close to demanded
unsigned int demandedTemperature = 23; // Setup demanded value in degrees

DHT11_Sensor temperatureAndHumiditySensor(TEMPERATURE_SENSOR_PIN); // Create sensor
TurnOnWhenHigher airConditioner(AIR_CONDITIONER_PIN, demandedTemperature, temperatureAndHumiditySensor.temperature, TEMPERATURE_RANGE / 2); // Create air conditioner
TurnOnWhenLower heater(HEATER_PIN, demandedTemperature, temperatureAndHumiditySensor.temperature, TEMPERATURE_RANGE / 2); // Create heater

void setup() {
  temperatureAndHumiditySensor.init(); // Sensor initialization
  airConditioner.init(); // Air conditioner initialization
  heater.init(); // Heater initialization
}

void loop() {
  temperatureAndHumiditySensor.update(); // Update temperature value
  airConditioner.update(); // Will turn ON, if currentTemperature > 23 + 3
  heater.update(); // Will turn ON, if currentTemperature < 23 - 3

  delay(5000); // Wait some time
}
/*
 IntensityControl usage example
 Will set speed of your fan at defined percentage
*/

#include <Arduino-devices.h>


#define FAN_PIN 13 // Set your actual pin number
unsigned int speedPercentage = 50; // Setup demanded value, %

IntensityControl fanSpeedController(FAN_PIN, speedPercentage); // Create device
// To define initial fan speed: at 0% demanded speed will be equal 60% of fan speed, 100% - 100%
// IntensityControl fanSpeedController(FAN_PIN, speedPercentage, 60);

void setup() {
  fanSpeedController.init(); // Device initialization
}

void loop() {
  fanSpeedController.update(); // Will set speed of your fan at defined percentage

  delay(5000); // Wait some time
}
#include "./PCA9685.h"

PCA9685_Output::PCA9685_Output() {
  driver = Adafruit_PWMServoDriver(0x40);
}

PCA9685_Output::PCA9685_Output(uint8_t port) {
  driver = Adafruit_PWMServoDriver(port);
}

void PCA9685_Output::init(unsigned char pin) {
  if (isInitialized) {
    return;
  }

  isInitialized = true;
  driver.begin();
}

void PCA9685_Output::write(unsigned char pin, bool value) {
  driver.setPin(pin, value == HIGH ? maxValue : 0);
}

void PCA9685_Output::write(unsigned char pin, uint16_t value) {
  driver.setPin(pin, value);
}

PCA9685_Output *pca9685_Output = new PCA9685_Output;
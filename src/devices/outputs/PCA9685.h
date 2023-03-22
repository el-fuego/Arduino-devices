#ifndef PCA9685_OUTPUT_H
#define PCA9685_OUTPUT_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <inttypes.h>
#include "./Base.h"

/**
* Write value to servo driver used as pin expander
**/
class PCA9685_Output: public BaseOutput {
  private:
    bool isInitialized = false;
    Adafruit_PWMServoDriver driver;

  public:
    const uint16_t maxValue = 4095;
    PCA9685_Output();
    PCA9685_Output(uint8_t port);

    void init(unsigned char pin);
    void write(unsigned char pin, bool value);
    void write(unsigned char pin, uint16_t value);
};

extern PCA9685_Output *pca9685_Output;

#endif
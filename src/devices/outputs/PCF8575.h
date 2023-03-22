#ifndef PCF8575_OUTPUT_H
#define PCF8575_OUTPUT_H

#include <Wire.h>
#include <I2cDiscreteIoExpander.h>
#include <inttypes.h>
#include "./Base.h"

/**
* Write value to pin expander
**/
class PCF8575_Output: public BaseOutput {
  private:
    I2cDiscreteIoExpander driver;

  public:
    PCF8575_Output();
    PCF8575_Output(uint8_t port);

    void init(unsigned char _) {};
    void write(unsigned char pin, bool value);
    void write(unsigned char _, uint16_t __) {};
};

#endif
#ifndef PIN_OUTPUT_H
#define PIN_OUTPUT_H

#include <inttypes.h>
#include "./Base.h"

/**
* Write value directly to Arduino pin
**/
class PinOutput: public BaseOutput {
  public:
    const uint16_t maxValue = 255;
    void init(unsigned char pin);
    void write(unsigned char pin, bool value);
    void write(unsigned char pin, uint16_t value);
};

extern PinOutput *pinOutput;

#endif
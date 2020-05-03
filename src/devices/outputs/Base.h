#ifndef BASE_OUTPUT_H
#define BASE_OUTPUT_H

#include <inttypes.h>


/**
* Base class for internal usage
**/
class BaseOutput {
  public:
    uint8_t maxValue = 255;
    virtual void init(unsigned char pin) = 0;
    virtual void write(unsigned char pin, bool value) = 0;
    virtual void write(unsigned char pin, uint16_t value) = 0;
};

#endif
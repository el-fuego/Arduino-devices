#ifndef DEVICE_H
#define DEVICE_H

#include "./outputs/Base.h"


/**
* Base class for internal usage
**/
class Device {
  protected:
    void writeToPin();
  public:
    BaseOutput *output;
    const unsigned char pin = 13;
    bool isOutputInverted = false;
    bool isEnabled = false;

    Device(unsigned char _pin);
    Device(BaseOutput *_output, unsigned char _pin);
    void makeOutputInverted();
    void init();
};

#endif
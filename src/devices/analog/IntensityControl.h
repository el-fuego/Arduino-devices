#ifndef INTENSITY_CONTROL_H
#define INTENSITY_CONTROL_H

#include "../Device.h"

/**
* Set analog pin value, based on percentage value
* For the devices like fans, use rangeStart to provide minimal working point
**/
class IntensityControl: public Device {
  private:
    unsigned int &percentage;
    unsigned int previousPercentage = 0;
    const unsigned int rangeStart = 0;
    void writeToPin();
    uint16_t getPinValue();
  public:
    IntensityControl(unsigned char _pin, unsigned int &_percentage, unsigned int _rangeStart);
    IntensityControl(BaseOutput *_output, unsigned char _pin, unsigned int &_percentage, unsigned int _rangeStart);
    void update();
};

#endif
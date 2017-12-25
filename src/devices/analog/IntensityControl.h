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
    unsigned int getPinValue();
  public:
    IntensityControl(unsigned char _pin, unsigned int &_percentage);
    IntensityControl(unsigned char _pin, unsigned int &_percentage, unsigned int _rangeStart);
    void update();
};

#endif;
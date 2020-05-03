#ifndef BASE_LEVEL_SWITCH_H
#define BASE_LEVEL_SWITCH_H

#include "../Device.h"
#include "../outputs/Base.h"


/**
* Base class for internal usage
**/
class BaseLevelSwitch : public Device {
  protected:
    unsigned long toggledAt = 0;
    const unsigned long minMeasureInterval = 10000;
    const unsigned char minDifference = 0;
    void writeToPin();
    bool canMeasure();
  public:
    const unsigned int &demandedValue;
    unsigned char &currentValue;
    BaseLevelSwitch(unsigned char _pin, unsigned int &_demandedValue, unsigned char &_currentValue);
    BaseLevelSwitch(BaseOutput *_output, unsigned char _pin, unsigned int &_demandedValue, unsigned char &_currentValue);
    BaseLevelSwitch(unsigned char _pin, unsigned int &_demandedValue, unsigned char &_currentValue, const unsigned char _minDifference);
    BaseLevelSwitch(BaseOutput *_output, unsigned char _pin, unsigned int &_demandedValue, unsigned char &_currentValue, const unsigned char _minDifference);
    virtual void update() = 0;
};

#endif
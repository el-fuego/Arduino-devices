#ifndef TURN_ON_WHEN_HIGHER_H
#define TURN_ON_WHEN_HIGHER_H

#include "./BaseLevelSwitch.h"


/**
* Set high level on pin, when current value is higher then demanded
* use minDifference when you need to on|off your device for maintaining some parameter in specific range
**/
class TurnOnWhenHigher : public BaseLevelSwitch {
  public:
    using BaseLevelSwitch::BaseLevelSwitch;
    void update();
};

#endif;
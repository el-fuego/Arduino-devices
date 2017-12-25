#ifndef TURN_ON_WHEN_LOWER_H
#define TURN_ON_WHEN_LOWER_H

#include "./BaseLevelSwitch.h"


/**
* Set high level on pin, when current value is lower then demanded
* use minDifference when you need to on|off your device for maintaining some parameter in specific range
**/
class TurnOnWhenLower : public BaseLevelSwitch {
  public:
    using BaseLevelSwitch::BaseLevelSwitch;
    void update();
};

#endif;
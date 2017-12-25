#ifndef ARDUINO_DEVICES_H
#define ARDUINO_DEVICES_H

#include "./devices/Device.h"

#include "./devices/analog/IntensityControl.h"

#include "./devices/switch-by-level/BaseLevelSwitch.h"
#include "./devices/switch-by-level/TurnOnWhenHigher.h"
#include "./devices/switch-by-level/TurnOnWhenLower.h"

#include "./devices/switch-by-time/ScheduleIntervalSwitch.h"
#include "./devices/switch-by-time/TimeIntervalSwitch.h"


#include "./sensors/Sensor.h"

#include "./sensors/clocks/DS3231.h"

#include "./sensors/joysticks/Analog.h"

#include "./sensors/temperature-and-humidity/DHT11.h"

#endif;
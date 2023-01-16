#ifndef ARDUINO_DEVICES_H
#define ARDUINO_DEVICES_H

#include "./devices/Device.h"

#include "./devices/outputs/Base.h"
#include "./devices/outputs/Pin.h"

#include "./devices/analog/IntensityControl.h"

#include "./devices/switch-by-level/BaseLevelSwitch.h"
#include "./devices/switch-by-level/TurnOnWhenHigher.h"
#include "./devices/switch-by-level/TurnOnWhenLower.h"

#include "./devices/switch-by-time/ScheduleIntervalSwitch.h"
#include "./devices/switch-by-time/ClockTimeIntervalSwitch.h"


#include "./sensors/Sensor.h"

#include "./sensors/clocks/DS3231.h"

#include "./sensors/joysticks/Analog.h"

#include "./sensors/temperature-and-humidity/BaseDHT.h"
#include "./sensors/temperature-and-humidity/BME280.h"
#include "./sensors/temperature-and-humidity/DHT11.h"
#include "./sensors/temperature-and-humidity/Si7021.h"
#include "./sensors/temperature-and-humidity/Am2320.h"

#endif
# Arduino-devices
Single interface for reading from sensors and updating devices state

- You need to control weather at your home?
- Or, maybe, watering at your greenhouse, basing on time?
- Or turn on lights, basing on moving sensor?

=== This project will provide an easy solution for you! ===

## Devices

### Switch by level

#### Turn on when higher
Will put HIGH level to specified pin, if provided value > than demanded
```cpp
TurnOnWhenHigher airConditioner(AIR_CONDITIONER_PIN, DEMANDED_TEMPERATURE, currentTemperature);
```
[full usage example](https://github.com/el-fuego/Arduino-devices/blob/master/examples/airConditioner/airConditioner.ino)

#### Turn on when lower
Will put HIGH level to specified pin, if provided value < than demanded
```cpp
TurnOnWhenLower heater(HEATER_PIN, DEMANDED_TEMPERATURE, currentTemperature);
```
[full usage example](https://github.com/el-fuego/Arduino-devices/blob/master/examples/heater/heater.ino)

#### Advantage usage
```cpp
/*
 Use minDifference as 4th argument, when you need to turn ON|OFF your few devices 
 for maintaining some parameter in specific range
 In this case, your devices will be turned OFF, if value is close to demanded
*/
TurnOnWhenHigher airConditioner(AIR_CONDITIONER_PIN, demandedTemperature, temperatureAndHumiditySensor.temperature, TEMPERATURE_RANGE / 2);
TurnOnWhenLower heater(HEATER_PIN, demandedTemperature, temperatureAndHumiditySensor.temperature, TEMPERATURE_RANGE / 2);
```
[full usage example](https://github.com/el-fuego/Arduino-devices/blob/master/examples/temperatureControl/temperatureControl.ino)


### Switch by time

#### Schedule interval switch
Will put HIGH level to specified pin, for specified time every interval time.\
Work in pair with clock sensor
```cpp
ScheduleIntervalSwitch waterPump(WATER_PUMP_PIN, wateringInterval, clock);
```
[full usage example](https://github.com/el-fuego/Arduino-devices/blob/master/examples/watering/watering.ino)

#### Time interval switch
Will put HIGH level to specified pin, for specified time every interval time.\
Work in pair with clock sensor
```cpp
TimeIntervalSwitch lamp(LAMP_PIN, lighteningInterval, clock);
```
[full usage example](https://github.com/el-fuego/Arduino-devices/blob/master/examples/lightening/lightening.ino)


### Analog devices

#### Intensity control
Will put 0-100% voltage to specified pin\
Can be used as light dimmer, fan speed control...
```cpp
IntensityControl fanSpeedController(FAN_PIN, speedPercentage);
```

Most of fans will start work from different voltage point (60%, for example), so you need to find it by measurement or testing speedPercentage value and specify this start value in percentage as 3rd parameter
```cpp
IntensityControl fanSpeedController(FAN_PIN, speedPercentage, FAN_START_PERCENTAGE);
```
[full usage example](https://github.com/el-fuego/Arduino-devices/blob/master/examples/fanSpeedControl/fanSpeedControl.ino)


### Advanced usage
```cpp
/*
 If you are using inverted relay input (LOW pin value for enabling), 
 you can invert device output before initialization 
 Also, this works with analog output devices
*/
void setup() {
  myDevice.makeOutputInverted(); # heater, conditioner, fan.. 
}

/*
 In any time, you can check current status of your device
 Use this option to indicate working process at the screen
*/
myDevice.isEnabled; # bool
```


## Sensors

### Clocks

#### DS3231 Sensor
Most used RTC clock, connected to I2C
```cpp
DS3231_Sensor clock;
```
TODO: full usage example. For a now, see: "Switch by time" section


### Joysticks

#### AnalogJoystick
```cpp
AnalogJoystick jiystick(PIN_X, PIN_Y);
```
TODO: full usage example.


### Temperature and humidity

#### DHT11 Sensor
Cheap digital humidity and temperature, used single data-pin
```cpp
DHT11_Sensor temperatureAndHumiditySensor(TEMPERATURE_SENSOR_PIN)
```
TODO: full usage example. For a now, see: "Switch by level" section


### Advanced usage
```cpp
/*
 In any time, you can check current status of your sensor
 Use this option to indicate working process at the screen
*/
mySensor.hasError; # bool
```
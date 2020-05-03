#ifndef SENSOR_ANALOG_JOYSTICK_H
#define SENSOR_ANALOG_JOYSTICK_H
#include "../Sensor.h"


enum JoystickDirections { Center, Up, Down, Left, Right };

/**
* Analog joystick
* most used for menu control
**/
class AnalogJoystick: public Sensor {
  private:
    unsigned char pinX;
    unsigned char pinY;
    JoystickDirections read();
    JoystickDirections prevDirection = Center;
    unsigned long updatedAt;
  public:
    AnalogJoystick(unsigned char _pinX, unsigned char _pinY);
    JoystickDirections direction = Center;
    void init();
    void update();
};

#endif


#include <Arduino.h>
#include "./Analog.h"


#define JOYSTICK_LONG_PRESS_TIMEOUT 500


AnalogJoystick::AnalogJoystick(unsigned char _pinX, unsigned char _pinY) : pinX(_pinX), pinY(_pinY) {};

void AnalogJoystick::init() {
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
};

void AnalogJoystick::update() {
  JoystickDirections currentDirection = read();
  unsigned long currentTime = millis();
  if (updatedAt > currentTime) {
    updatedAt = 0;
  }

  // single press
  if (currentDirection != prevDirection) {
    direction = prevDirection = currentDirection;
    updatedAt = currentTime;

  // long press
  } else if (currentTime - updatedAt > JOYSTICK_LONG_PRESS_TIMEOUT) {
      direction = currentDirection;

  } else {
      direction = JoystickDirections::Center;
  }
};

JoystickDirections AnalogJoystick::read() {
  int valueX = analogRead(pinX);
  if (valueX > 800) {
    return JoystickDirections::Right;
  }
  if (valueX < 200) {
    return JoystickDirections::Left;
  }

  int valueY = analogRead(pinY);
  if (valueY > 800) {
    return JoystickDirections::Down;
  }
  if (valueY < 200) {
    return JoystickDirections::Up;
  }
  return JoystickDirections::Center;
};


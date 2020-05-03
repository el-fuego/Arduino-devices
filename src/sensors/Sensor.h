#ifndef SENSOR_H
#define SENSOR_H


/**
* Base class for internal usage
**/
class Sensor {
  public:
    bool hasError = false;
    virtual void init() = 0;
    virtual void update() = 0;
};

#endif
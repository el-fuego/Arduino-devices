#ifndef SENSOR_H
#define SENSOR_H


/**
* Base class for internal usage
**/
class Sensor {
  public:
    bool hasError = false;
  	virtual void init();
    virtual void update();
};

#endif;
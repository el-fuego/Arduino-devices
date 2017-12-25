#ifndef DEVICE_H
#define DEVICE_H


/**
* Base class for internal usage
**/
class Device {
  protected:
  	const unsigned char pin = 13;
  	bool isOutputInverted = false;
  	void writeToPin();
  public:
  	Device(unsigned char _pin);
  	void makeOutputInverted();
  	void init();
    virtual void update();
    bool isEnabled = false;
};

#endif;
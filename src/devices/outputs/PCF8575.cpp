#include "./PCF8575.h"

PCF8575_Output::PCF8575_Output() {
  driver = I2cDiscreteIoExpander(0x20);
}

PCF8575_Output::PCF8575_Output(uint8_t port) {
  driver = I2cDiscreteIoExpander(port);
}

void PCF8575_Output::write(unsigned char pin, bool value) {
  driver.digitalRead();
  uint16_t data = driver.getPorts();

  bitWrite(data, pin, value ? 1 : 0);
  driver.digitalWrite(data);
}


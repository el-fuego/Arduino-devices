#include "./BaseDHT.h"


#define DHT_UPDATE_INTERVAL 1000

bool BaseDHT::canUpdate() {
  unsigned long currentMillis = millis();
  if (currentMillis < updatedAt) {
  	updatedAt = 0;
  }

  return currentMillis - updatedAt > DHT_UPDATE_INTERVAL;
};


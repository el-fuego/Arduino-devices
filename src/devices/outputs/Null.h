#ifndef NULL_OUTPUT_H
#define NULL_OUTPUT_H

#include <inttypes.h>
#include "./Base.h"

/**
* Do not write value anywhere
**/
class NullOutput: public BaseOutput {
  public:
    NullOutput() {}
    void init(unsigned char _) {};
    void write(unsigned char _, bool __);
    void write(unsigned char _, uint16_t __);
};

#endif
#ifndef FANCONTROLLERBASE_H
#define FANCONTROLLERBASE_H

#include <Arduino.h>

class FanControllerBase {
public:
    FanControllerBase(int fanPin, int zeroCrossingPin);
    virtual ~FanControllerBase() = default;

    void begin();
    void setSpeed(int speed); // Speed in percentage (0-100)

protected:
    virtual void platformBegin() = 0;
    virtual void platformSetSpeed(int delayTime) = 0;

    int _fanPin;
    int _zeroCrossingPin;
    volatile int _delayTime;
};

#endif // FANCONTROLLERBASE_H

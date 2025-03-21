#ifndef FANCONTROLLERBASE_H
#define FANCONTROLLERBASE_H

#include <Arduino.h>

class FanControllerBase {
protected:
    int _fanPin;
    int _zeroCrossingPin;
    int _delayTime;

public:
    FanControllerBase(int fanPin, int zeroCrossingPin)
        : _fanPin(fanPin), _zeroCrossingPin(zeroCrossingPin), _delayTime(0) {}

    virtual void begin() { // Make begin() virtual so it can be overridden
        pinMode(_fanPin, OUTPUT);
        pinMode(_zeroCrossingPin, INPUT);
    }

    void setSpeed(int speed) {
        if (speed < 0) speed = 0;
        if (speed > 100) speed = 100;
        _delayTime = map(speed, 0, 100, 8000, 0); // Map speed to delay

        platformSetSpeed(_delayTime); // Call platform-specific implementation
    }

protected:
    virtual void platformSetSpeed(int delayTime) = 0; // Must be implemented in subclasses
};

#endif // FANCONTROLLERBASE_H

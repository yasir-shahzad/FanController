#include "FanControllerBase.h"

FanControllerBase::FanControllerBase(int fanPin, int zeroCrossingPin)
    : _fanPin(fanPin), _zeroCrossingPin(zeroCrossingPin), _delayTime(0) {}

void FanControllerBase::begin() {
    pinMode(_fanPin, OUTPUT);
    pinMode(_zeroCrossingPin, INPUT);
    platformBegin();
}

void FanControllerBase::setSpeed(int speed) {
    if (speed < 0) speed = 0;
    if (speed > 100) speed = 100;
    _delayTime = map(speed, 0, 100, 8000, 0); // Map speed to delay
    platformSetSpeed(_delayTime);
}

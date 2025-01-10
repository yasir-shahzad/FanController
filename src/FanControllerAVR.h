#ifndef FANCONTROLLERAVR_H
#define FANCONTROLLERAVR_H

#include "FanControllerBase.h"

class FanControllerAVR : public FanControllerBase {
public:
    FanControllerAVR(int fanPin, int zeroCrossingPin)
        : FanControllerBase(fanPin, zeroCrossingPin) {}

protected:
    void platformBegin() override {
        attachInterrupt(digitalPinToInterrupt(_zeroCrossingPin), []() {
            delayMicroseconds(_delayTime);
            digitalWrite(_fanPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(_fanPin, LOW);
        }, RISING);
    }

    void platformSetSpeed(int delayTime) override {
        // AVR uses blocking delay, so no additional setup is required
    }
};

#endif // FANCONTROLLERAVR_H

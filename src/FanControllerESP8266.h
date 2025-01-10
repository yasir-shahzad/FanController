#ifndef FANCONTROLLERESP8266_H
#define FANCONTROLLERESP8266_H

#include "FanControllerBase.h"

class FanControllerESP8266 : public FanControllerBase {
public:
    FanControllerESP8266(int fanPin, int zeroCrossingPin)
        : FanControllerBase(fanPin, zeroCrossingPin) {}

protected:
    void platformBegin() override {
        attachInterrupt(digitalPinToInterrupt(_zeroCrossingPin), fireTriac, RISING);
    }

    void platformSetSpeed(int delayTime) override {
        // ESP8266-specific timer setup
        // Use timer1 for precise timing
    }

private:
    static void ICACHE_RAM_ATTR fireTriac() {
        digitalWrite(_fanPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(_fanPin, LOW);
    }
};

#endif // FANCONTROLLERESP8266_H

#ifndef FANCONTROLLERESP32_H
#define FANCONTROLLERESP32_H

#include "FanController.h"

class FanControllerESP32 : public FanController {
public:
    FanControllerESP32(int fanPin, int zeroCrossingPin)
        : FanController(fanPin, zeroCrossingPin), _timer(nullptr) {}

protected:
    void platformBegin() override {
        attachInterrupt(digitalPinToInterrupt(_zeroCrossingPin), fireTriac, RISING);
        _timer = timerBegin(0, 80, true); // Timer 0, prescaler 80 (1 µs per tick)
        timerAttachInterrupt(_timer, fireTriac, true);
    }

    void platformSetSpeed(int delayTime) override {
        timerAlarmWrite(_timer, delayTime, false); // Set delay time
        timerAlarmEnable(_timer);
    }

private:
    hw_timer_t *_timer;
    static void IRAM_ATTR fireTriac() {
        digitalWrite(_fanPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(_fanPin, LOW);
    }
};

#endif // FANCONTROLLERESP32_H

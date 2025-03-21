#ifndef FANCONTROLLERESP32_H
#define FANCONTROLLERESP32_H

#include "FanControllerBase.h"

class FanControllerESP32 : public FanControllerBase {
public:
    FanControllerESP32(int fanPin, int zeroCrossingPin)
        : FanControllerBase(fanPin, zeroCrossingPin), _timer(nullptr) {}

    void begin() override {
        _fanPinStatic = _fanPin; // Assign pin to static variable
        pinMode(_fanPin, OUTPUT);
        attachInterrupt(digitalPinToInterrupt(_zeroCrossingPin), fireTriacISR, RISING);

        _timer = timerBegin(0, 80, true);
        timerAttachInterrupt(_timer, timerISR, true);  // ✅ No '&' and matches function signature
    }

    void platformSetSpeed(int delayTime) override {
        timerAlarmWrite(_timer, delayTime, false);
        timerAlarmEnable(_timer);
    }

private:
    hw_timer_t *_timer;
    static int _fanPinStatic;

    // Correct ISR function for Zero Crossing Detection
    static void IRAM_ATTR fireTriacISR() {
        digitalWrite(_fanPinStatic, HIGH);  // ✅ Ensure this runs from IRAM
        delayMicroseconds(10);              // ✅ Keep short; consider replacing with NOP
        digitalWrite(_fanPinStatic, LOW);
    }
    

    // Correct ISR function for Timer Interrupt
    static void IRAM_ATTR timerISR() {  // ✅ Fixed function signature
        fireTriacISR();
    }
};

// Define static variable
int FanControllerESP32::_fanPinStatic = 0;

#endif // FANCONTROLLERESP32_H

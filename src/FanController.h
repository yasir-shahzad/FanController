#ifndef FANCONTROLLER_H
#define FANCONTROLLER_H

#include <Arduino.h>

class FanController {
public:
    FanController(int fanPin, int zeroCrossingPin);
    void begin();
    void setSpeed(int speed); // Speed in percentage (0-100)

private:
    int _fanPin;
    int _zeroCrossingPin;
    volatile int _delayTime;
    hw_timer_t *_timer;

    static void IRAM_ATTR zeroCrossingInterruptWrapper();
    static void IRAM_ATTR fireTriacWrapper();
    void IRAM_ATTR zeroCrossingInterrupt();
    void IRAM_ATTR fireTriac();

    static FanController *_instance; // Singleton instance for static ISR access
};

#endif // FANCONTROLLER_H

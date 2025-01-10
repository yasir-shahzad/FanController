#include "FanController.h"

FanController *FanController::_instance = nullptr;

FanController::FanController(int fanPin, int zeroCrossingPin)
    : _fanPin(fanPin), _zeroCrossingPin(zeroCrossingPin), _delayTime(0), _timer(nullptr) {
    _instance = this; // Set the singleton instance
}

void FanController::begin() {
    pinMode(_fanPin, OUTPUT);
    pinMode(_zeroCrossingPin, INPUT);

    // Attach zero-crossing interrupt
    attachInterrupt(digitalPinToInterrupt(_zeroCrossingPin), zeroCrossingInterruptWrapper, RISING);

    // Configure hardware timer
    _timer = timerBegin(0, 80, true); // Timer 0, prescaler 80, count in µs
    timerAttachInterrupt(_timer, fireTriacWrapper, true);
    timerAlarmDisable(_timer); // Start with the timer disabled
}

void FanController::setSpeed(int speed) {
    if (speed < 0) speed = 0;
    if (speed > 100) speed = 100;
    _delayTime = map(speed, 0, 100, 8000, 0); // Map speed to delay (0% = max delay, 100% = no delay)
}

void IRAM_ATTR FanController::zeroCrossingInterruptWrapper() {
    if (_instance) _instance->zeroCrossingInterrupt();
}

void IRAM_ATTR FanController::fireTriacWrapper() {
    if (_instance) _instance->fireTriac();
}

void IRAM_ATTR FanController::zeroCrossingInterrupt() {
    if (_delayTime > 0) {
        timerWrite(_timer, 0);               // Reset the timer
        timerAlarmWrite(_timer, _delayTime, false); // Set timer for delayTime µs
        timerAlarmEnable(_timer);           // Enable the timer alarm
    }
}

void IRAM_ATTR FanController::fireTriac() {
    digitalWrite(_fanPin, HIGH);
    delayMicroseconds(10); // Keep the TRIAC ON briefly
    digitalWrite(_fanPin, LOW);
    timerAlarmDisable(_timer); // Disable the timer after firing
}

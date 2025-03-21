#ifndef FANCONTROLLER_H
#define FANCONTROLLER_H

#include <Arduino.h>

#if defined(ESP32)
    #include "FanControllerESP32.h"
    using FanController = FanControllerESP32;
#elif defined(ESP8266)
    #include "FanControllerESP8266.h"
    using FanController = FanControllerESP8266;
#elif defined(__AVR__)
    #include "FanControllerAVR.h"
    using FanController = FanControllerAVR;
#else
    #error "Unsupported board. This library supports ESP32, ESP8266, and AVR (Arduino Uno)."
#endif

#endif // FANCONTROLLER_H

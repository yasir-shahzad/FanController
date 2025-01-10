#ifndef FANCONTROLLER_H
#define FANCONTROLLER_H

#include <Arduino.h>

#if defined(ESP32)
    #include "FanControllerESP32.h"
    typedef FanControllerESP32 FanController;
#elif defined(ESP8266)
    #include "FanControllerESP8266.h"
    typedef FanControllerESP8266 FanController;
#elif defined(__AVR__)
    #include "FanControllerAVR.h"
    typedef FanControllerAVR FanController;
#else
    #error "Unsupported board. This library supports ESP32, ESP8266, and AVR (Arduino Uno)."
#endif

#endif // FANCONTROLLER_H

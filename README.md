# FanController Library for ESP32, ESP8266, and Arduino Uno

## Description
A lightweight Arduino library to control AC fan speed using zero-crossing detection and TRIAC firing with precise timing. Compatible with ESP32, ESP8266, and Arduino Uno.

---

## Features
- Zero-crossing detection for synchronized TRIAC control.
- Hardware timer-based delay management for precise timing.
- Board compatibility: ESP32, ESP8266, and Arduino Uno.
- Easy-to-use interface for setting fan speed (0-100%).

---

## Installation
1. Clone or download the repository.
2. Place the `FanController` folder in your Arduino `libraries` directory.
3. Restart your Arduino IDE to recognize the library.

---

## Usage
### Example
```cpp
#include <FanController.h>

// Define pins
const int FAN_PIN = 22;
const int ZERO_CROSSING_PIN = 33;

// Create FanController instance
FanController fan(FAN_PIN, ZERO_CROSSING_PIN);

void setup() {
    Serial.begin(115200);
    fan.begin();
    Serial.println("Fan control ready. Enter speed (0-100):");
}

void loop() {
    if (Serial.available() > 0) {
        int speed = Serial.parseInt();
        if (speed >= 0 && speed <= 100) {
            fan.setSpeed(speed);
            Serial.println("Fan speed set to: " + String(speed) + "%");
        } else {
            Serial.println("Invalid speed. Please enter a value between 0 and 100.");
        }
    }
}
```

---

## API Reference
### `FanController` Class
#### Constructor
```cpp
FanController(int fanPin, int zeroCrossingPin);
```
- **fanPin**: GPIO pin connected to the TRIAC gate.
- **zeroCrossingPin**: GPIO pin connected to the zero-crossing detector.

#### Methods
- `void begin();`
  Initializes the library and configures the hardware.

- `void setSpeed(int speed);`
  Sets the fan speed as a percentage (0-100%).

---

## Notes
- Ensure proper isolation and safety when working with AC mains.
- Adjust delay mapping for non-50Hz mains if necessary.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Contributions
Contributions are welcome! Feel free to open issues or submit pull requests.

---

## Author
[Your Name]  
[Your Contact Information]

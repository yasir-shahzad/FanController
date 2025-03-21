# FanController Library for ESP32, ESP8266, and Arduino Uno
[![Discord](https://img.shields.io/discord/1349656889981407283?style=social&logo=discord&label=COMMUNITY)](https://discord.gg/GZ8PyxDu)
[![Ko-fi](https://img.shields.io/badge/Support%20on%20Ko--fi-F16061?style=flat&logo=kofi&logoColor=white&labelColor=%23FF5E5B)](https://buymeacoffee.com/yasirshahzad)
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


# Pin Mapping for Various Boards

The following table provides the pin mapping for different microcontroller boards, including their input and output pins for specific functionalities.

## Pin Mapping Table

| **Board**         | **INPUT Pin (Zero Cross)**       | **OUTPUT Pin**                        |
|--------------------|----------------------------------|----------------------------------------|
| **Leonardo**       | D7 (NOT CHANGABLE)              | D0-D6, D8-D13                          |
| **Mega**           | D2 (NOT CHANGABLE)              | D0-D1, D3-D70                          |
| **UNO / NANO**     | D2 (NOT CHANGABLE)              | D0-D1, D3-D20                          |
| **ESP8266**        | - D1 (IO5)                     | - D0 (IO16)                            |
|                    | - D5 (IO14)                    | - D2 (IO4)                             |
|                    | - D7 (IO13)                    | - D6 (IO12)                            |
|                    |                                 | - D8 (IO15)                            |
| **ESP32**          | - GPIO36, GPIO39, GPIO32, GPIO25 | - GPIO34, GPIO35, GPIO33, GPIO26      |
|                    | - GPIO27, GPIO12, GPIO7, GPIO2  | - GPIO14, GPIO13, GPIO15, GPIO0       |
|                    | - GPIO4, GPIO17, GPIO18, GPIO21 | - GPIO16, GPIO5, GPIO19, GPIO23       |
| **Arduino M0 / Zero** | D7 (NOT CHANGABLE)             | D0-D6, D8-D13                          |
| **Arduino Due**    | D0-D53                         | D0-D53                                 |
| **STM32 (Black Pill / Blue Pill, etc.)** | PA0-PA15, PB0-PB15, PC13-PC15 | PA0-PA15, PB0-PB15, PC13-PC15 |

## Notes for Specific Boards

### ESP8266
- **Input Pins**:  
  - D1 (IO5), D5 (IO14), D7 (IO13)  
- **Output Pins**:  
  - D0 (IO16), D2 (IO4), D6 (IO12), D8 (IO15)

### ESP32
- **Input Pins**:  
  - GPIO36, GPIO39, GPIO32, GPIO25, GPIO27, GPIO12, GPIO7, GPIO2, GPIO4, GPIO17, GPIO18, GPIO21  
- **Output Pins**:  
  - GPIO34, GPIO35, GPIO33, GPIO26, GPIO14, GPIO13, GPIO15, GPIO0, GPIO16, GPIO5, GPIO19, GPIO23  

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

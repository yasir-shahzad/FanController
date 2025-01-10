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

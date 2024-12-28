#include <Arduino.h>
#include <Gyroscope6050.h>
#include <HCSR04.h>

// Create gyroscope and ultrasonic sensor objects
Gyroscope6050 gyroscope;
HCSR04 ultrasonic(32, 33);

// Timing variables
unsigned long lastGyroUpdate = 0;
unsigned long lastUltrasonicUpdate = 0;

// Intervals (in milliseconds)
const unsigned long gyroUpdateInterval = 10;       // Update gyroscope every 10 ms
const unsigned long ultrasonicUpdateInterval = 500; // Update ultrasonic every 500 ms

void setup() {
    Serial.begin(115200);
    Wire.begin();

    // Initialize the gyroscope
    if (!gyroscope.initialize()) {
        Serial.println("Failed to initialize gyroscope. Halting...");
        while (1);
    }

    // Calibrate the gyroscope
    gyroscope.calibrate();
}

void loop() {
    unsigned long currentTime = millis();

    // Update the gyroscope frequently
    if (currentTime - lastGyroUpdate >= gyroUpdateInterval) {
        lastGyroUpdate = currentTime;
        gyroscope.update();
        float yaw = gyroscope.getYaw();
        Serial.print("Yaw: ");
        Serial.println(yaw);
    }

    // Update the ultrasonic sensor less frequently
    if (currentTime - lastUltrasonicUpdate >= ultrasonicUpdateInterval) {
        lastUltrasonicUpdate = currentTime;
        float distance = ultrasonic.getDistance();
        Serial.print("Distance: ");
        Serial.println(distance);
    }

    // Perform other tasks here (if needed)
}

#include "Gyroscope6050.h"

/**
 * @brief Constructor: initializes variables.
 */
Gyroscope6050::Gyroscope6050() 
    : gyroZOffset(0.0), yaw(0.0), lastTime(0) {
}

/**
 * @brief Initialize the MPU6050 sensor.
 * @return True if initialization was successful, false otherwise.
 */
bool Gyroscope6050::initialize() {
    if (!mpu.begin()) {
        Serial.println("Failed to initialize MPU6050.");
        return false;
    }
    return true;
}

/**
 * @brief Calibrate the gyroscope by calculating the Z-axis offset.
 */
void Gyroscope6050::calibrate() {
    Serial.println("Calibrating gyroscope... Keep the sensor stationary.");
    const int numSamples = 500;
    float sum = 0;

    for (int i = 0; i < numSamples; i++) {
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
        sum += g.gyro.z;
        delay(10); // Delay to ensure stable readings
    }

    gyroZOffset = sum / numSamples; // Compute average offset
    Serial.print("Gyro Z Offset: ");
    Serial.println(gyroZOffset);
    lastTime = millis();
}

/**
 * @brief Update yaw by integrating gyroscope Z-axis data.
 */
void Gyroscope6050::update() {
    // Read gyro Z-axis data
    float gyroZ = readGyroZ();

    // Calculate delta time (dt) in seconds
    unsigned long currentTime = millis();
    float dt = (currentTime - lastTime) / 1000.0;
    lastTime = currentTime;

    // Integrate gyro data to compute yaw in degrees
    yaw += gyroZ * dt * (180.0 / M_PI);
}

/**
 * @brief Read the Z-axis gyro value.
 * @return The Z-axis gyro value.
 */
float Gyroscope6050::readGyroZ() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return g.gyro.z - gyroZOffset;
}



/**
 * @brief Get the current yaw value.
 * @return The current yaw value.
 */
float Gyroscope6050::getYaw() const {
    return yaw;
}


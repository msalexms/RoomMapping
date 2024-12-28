#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

/**
 * @brief Gyroscope class to manage MPU6050 interactions.
 */
class Gyroscope6050 {
public:
    /**
     * @brief Constructor for the Gyroscope6050 class.
     */
    Gyroscope6050();

    /**
     * @brief Initialize the gyroscope.
     * @return True if initialization was successful, false otherwise.
     */
    bool initialize();

    /**
     * @brief Calibrate the gyroscope.
     */
    void calibrate();

    /**
     * @brief Update yaw calculations.
     */
    void update();

    /**
     * @brief Get the current yaw value.
     * @return The current yaw value.
     */
    float getYaw() const;

private:
    Adafruit_MPU6050 mpu; ///< MPU6050 object
    float gyroZOffset;    ///< Offset for Z-axis gyro
    float yaw;            ///< Calculated yaw
    unsigned long lastTime; ///< Last time yaw was updated

    /**
     * @brief Read the Z-axis gyro value.
     * @return The Z-axis gyro value.
     */
    float readGyroZ();
};

#endif // GYROSCOPE_H
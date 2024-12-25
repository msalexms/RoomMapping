#ifndef HCSR04_H
#define HCSR04_H

/**
 * @class HCSR04
 * @brief A class to interface with the HC-SR04 ultrasonic distance sensor.
 */
class HCSR04 {
public:
    /**
     * @brief Constructor for the HCSR04 class.
     * @param trigPin GPIO pin connected to the TRIG pin of the sensor.
     * @param echoPin GPIO pin connected to the ECHO pin of the sensor.
     */
    HCSR04(int trigPin, int echoPin);

    /**
     * @brief Get the distance measured by the sensor.
     * @return Distance in meters.
     */
    float getDistance();

private:
    int _trigPin;  ///< GPIO pin connected to the TRIG pin of the sensor.
    int _echoPin;  ///< GPIO pin connected to the ECHO pin of the sensor.
};

#endif  // HCSR04_H
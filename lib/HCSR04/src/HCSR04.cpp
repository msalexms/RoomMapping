#include "HCSR04.h"
#include <Arduino.h>  // Necessary for using Arduino functions like digitalWrite and pulseIn

/**
 * @brief Constructor for the HCSR04 class.
 * @param trigPin GPIO pin connected to the TRIG pin of the sensor.
 * @param echoPin GPIO pin connected to the ECHO pin of the sensor.
 */
HCSR04::HCSR04(int trigPin, int echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
    pinMode(_trigPin, OUTPUT);  // Set the TRIG pin as output
    pinMode(_echoPin, INPUT);   // Set the ECHO pin as input
}

/**
 * @brief Get the distance measured by the sensor.
 * @return Distance in meters.
 */
float HCSR04::getDistance() {
    // Send a pulse on TRIG
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    // Measure the duration of the pulse on ECHO
    long duration = pulseIn(_echoPin, HIGH);

    // Calculate the distance in meters
    float distance = (duration / 2.0) * 0.000344;  // Distance formula (time * speed of sound / 2)

    return distance;  // Return the distance
}
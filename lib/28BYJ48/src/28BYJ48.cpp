#include "28BYJ48.h"
#include <Arduino.h>

/**
 * @brief Constructor for Motor28BYJ48.
 * @param pin1 GPIO pin connected to IN1.
 * @param pin2 GPIO pin connected to IN2.
 * @param pin3 GPIO pin connected to IN3.
 * @param pin4 GPIO pin connected to IN4.
 * @param stepDelay Delay between steps in milliseconds.
 */
Motor28BYJ48::Motor28BYJ48(int pin1, int pin2, int pin3, int pin4, int stepDelay)
  : pin1(pin1), pin2(pin2), pin3(pin3), pin4(pin4), stepDelay(stepDelay) {}

/**
 * @brief Initialize the motor by setting the pin modes.
 */
void Motor28BYJ48::begin() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}

/**
 * @brief Move the motor forward by a specified number of steps.
 * @param steps Number of steps to move forward.
 */
void Motor28BYJ48::moveForward(int steps) {
    for (int i = 0; i < steps; i++) {
        stepMotor(1);  // Move one step forward
        delay(this->stepDelay);  // Control the speed (adjust delay as needed)
    }
}

/**
 * @brief Move the motor backward by a specified number of steps.
 * @param steps Number of steps to move backward.
 */
void Motor28BYJ48::moveBackward(int steps) {
    for (int i = 0; i < steps; i++) {
        stepMotor(-1);  // Move one step backward
        delay(this->stepDelay);  // Control the speed (adjust delay as needed)
    }
}

/**
 * @brief Stop the motor by setting all pins to LOW.
 */
void Motor28BYJ48::stop() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
}

/**
 * @brief Perform a single step of the motor.
 * @param step The step to perform (1 for forward, -1 for backward).
 */
void Motor28BYJ48::stepMotor(int step) {
    stepCount += step;

    // Ensure the step count is within the range of the step sequence
    if (stepCount > 7) {
        stepCount = 0;
    } else if (stepCount < 0) {
        stepCount = 7;
    }

    // Set the pins according to the step sequence
    digitalWrite(pin1, stepSequence[stepCount][0]);
    digitalWrite(pin2, stepSequence[stepCount][1]);
    digitalWrite(pin3, stepSequence[stepCount][2]);
    digitalWrite(pin4, stepSequence[stepCount][3]);
}
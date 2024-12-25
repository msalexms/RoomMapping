#ifndef MOTOR28BYJ48_H
#define MOTOR28BYJ48_H

/**
 * @class Motor28BYJ48
 * @brief A class to control a 28BYJ-48 stepper motor.
 */
class Motor28BYJ48 {
public:
    /**
     * @brief Constructor for Motor28BYJ48.
     * @param pin1 GPIO pin connected to IN1.
     * @param pin2 GPIO pin connected to IN2.
     * @param pin3 GPIO pin connected to IN3.
     * @param pin4 GPIO pin connected to IN4.
     * @param stepDelay Delay between steps in milliseconds.
     */
    Motor28BYJ48(int pin1, int pin2, int pin3, int pin4, int stepDelay);

    /**
     * @brief Initialize the motor.
     */
    void begin();

    /**
     * @brief Move the motor forward by a specified number of steps.
     * @param steps Number of steps to move forward.
     */
    void moveForward(int steps);

    /**
     * @brief Move the motor backward by a specified number of steps.
     * @param steps Number of steps to move backward.
     */
    void moveBackward(int steps);

    /**
     * @brief Stop the motor.
     */
    void stop();

private:
    // Step sequences for the motor
    const int stepSequence[8][4] = {
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    int pin1, pin2, pin3, pin4;
    int stepDelay;  // Delay between steps in milliseconds
    int stepCount = 0;  // Step counter

    /**
     * @brief Perform a single step of the motor.
     * @param step The step to perform.
     */
    void stepMotor(int step);
};

#endif // MOTOR28BYJ48_H
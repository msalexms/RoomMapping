#ifndef MOTOR28BYJ48_H
#define MOTOR28BYJ48_H

class Motor28BYJ48 {
public:
    // Constructor
    Motor28BYJ48(int pin1, int pin2, int pin3, int pin4);

    // Configuración
    void begin();

    // Movimiento del motor
    void moveForward(int steps);
    void moveBackward(int steps);
    void stop();

private:
    // Secuencias de pasos para el motor
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
    int stepCount = 0;  // Contador de pasos
    void stepMotor(int step);
};

#endif

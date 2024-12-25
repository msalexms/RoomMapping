#include "28BYJ48.h"
#include <Arduino.h>

// Constructor
Motor28BYJ48::Motor28BYJ48(int pin1, int pin2, int pin3, int pin4)
  : pin1(pin1), pin2(pin2), pin3(pin3), pin4(pin4) {}

// Inicialización de los pines
void Motor28BYJ48::begin() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}

// Movimiento hacia adelante (sentido horario)
void Motor28BYJ48::moveForward(int steps) {
    for (int i = 0; i < steps; i++) {
        stepMotor(1);  // Mover un paso hacia adelante
        delay(1);     // Controlar la velocidad (puedes ajustar el tiempo de espera)
    }
}

// Movimiento hacia atrás (sentido antihorario)
void Motor28BYJ48::moveBackward(int steps) {
    for (int i = 0; i < steps; i++) {
        stepMotor(-1);  // Mover un paso hacia atrás
        delay(1);      // Controlar la velocidad (puedes ajustar el tiempo de espera)
    }
}

// Detener el motor
void Motor28BYJ48::stop() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
}

// Función que controla la secuencia de pasos
void Motor28BYJ48::stepMotor(int step) {
    stepCount += step;

    // Asegurarse de que el contador de pasos esté dentro del rango de la secuencia
    if (stepCount > 7) {
        stepCount = 0;
    } else if (stepCount < 0) {
        stepCount = 7;
    }

    // Establecer los pines de acuerdo con la secuencia de pasos
    digitalWrite(pin1, stepSequence[stepCount][0]);
    digitalWrite(pin2, stepSequence[stepCount][1]);
    digitalWrite(pin3, stepSequence[stepCount][2]);
    digitalWrite(pin4, stepSequence[stepCount][3]);
}

#include "HCSR04.h"
#include <Arduino.h>  // Necesario para usar funciones de Arduino como digitalWrite y pulseIn

// Constructor de la clase HCSR04
HCSR04::HCSR04(int trigPin, int echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
    pinMode(_trigPin, OUTPUT);  // Configura el pin TRIG como salida
    pinMode(_echoPin, INPUT);   // Configura el pin ECHO como entrada
}

// Método para obtener la distancia
float HCSR04::getDistance() {
    // Enviar el pulso en TRIG
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    // Medir el tiempo del pulso en ECHO
    long duration = pulseIn(_echoPin, HIGH);

    // Calcular la distancia en metros
    float distance = (duration / 2.0) * 0.000344;  // Formula de distancia (tiempo * velocidad del sonido / 2)

    return distance;  // Devuelve la distancia
}

#ifndef HCSR04_H
#define HCSR04_H

class HCSR04 {
public:
    HCSR04(int trigPin, int echoPin);   // Constructor para inicializar los pines
    float getDistance();                 // Método para obtener la distancia

private:
    int _trigPin;  // Pin TRIG del sensor
    int _echoPin;  // Pin ECHO del sensor
};

#endif  // HCSR04_H

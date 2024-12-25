#include <Arduino.h>
#include <HCSR04.h>
#include <28BYJ48.h>

const int stepsPerRevolution = 200;
const int motorPin1 = 4;
const int motorPin2 = 0;
const int motorPin3 = 5;
const int motorPin4 = 15;

Motor28BYJ48 stepper(motorPin1, motorPin2, motorPin3, motorPin4);

const int trigPin = 32;
const int echoPin = 33;


HCSR04 ultrasonic(trigPin, echoPin);

void setup() {

    Serial.begin(115200);
    stepper.begin();
}

void loop() {

    Serial.print("Distance: ");
    Serial.print(ultrasonic.getDistance());
    Serial.println(" M");

    delay(1000);
    stepper.moveBackward(2048);
    delay(1000);
    stepper.moveForward(2048);
    


    delay(1000);

  
}


#include <Wire.h>
#include <U8g2lib.h>
#include <HCSR04.h>
#include <ESP32Servo.h>
#include <math.h>

#define MAX_DISTANCE 4.0
#define MAX_X 128
#define MAX_Y 64
#define NUM_POINTS 8

// Configuración de la pantalla OLED
U8G2_SSD1306_128X64_NONAME_F_HW_I2C screen(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 22, /* data=*/ 21);

// Configuración del sensor de ultrasonido
const int trigPin = 32;
const int echoPin = 33;
HCSR04 sonar(trigPin, echoPin);

const int servoPin = 14;

Servo servo;

const int centroX = 64; 
const int centroY = 32; 

float distancesMeters[NUM_POINTS] = {4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0};
float angles[NUM_POINTS] = {0, 45, 90, 135, 180, 225, 270, 315};
int coordinates[NUM_POINTS][2];


void getScreenPoints(float * array_distance_menters, float * array_angles, int num_points, int x_center, int y_center, int max_distance, int (*coordinates)[2]) {
  for(int i = 0; i < num_points; i++) {

    float rad = array_angles[i] * M_PI / 180;

    float temp_x = array_distance_menters[i] * cos(rad);
    float temp_y = array_distance_menters[i] * sin(rad);

    int x = (int) (temp_x * x_center) / max_distance;
    int y = (int) (temp_y * y_center) / max_distance;

    coordinates[i][0] = x_center + x -1;
    coordinates[i][1] = y_center + y -1;

    if (coordinates[i][0] < 0) {
      coordinates[i][0] = 0;
    } else if (coordinates[i][1] < 0) {
      coordinates[i][1] = 0;
    } 

  }

}



void setup() {
  Serial.begin(115200);
  screen.begin();
  screen.clearBuffer();

  servo.attach(servoPin);
  servo.write(0);
  getScreenPoints(distancesMeters, angles, NUM_POINTS, centroX, centroY, MAX_DISTANCE, coordinates);
    

  for (int i = 0; i < NUM_POINTS -1; i++) {
   // screen.drawPixel(coordinates[i][0], coordinates[i][1]);
    screen.drawLine(coordinates[i][0], coordinates[i][1], coordinates[i + 1][0], coordinates[i + 1][1]);  
    Serial.println("X: " + String(coordinates[i][0]) + " Y: " + String(coordinates[i][1]));
  }

    screen.sendBuffer();

  delay(1000);

  for (int i = 0 ; i < 180; i = i + 5) {
    servo.write(i);
    delay(200);
  }


  
 
}

void loop() {
  
}

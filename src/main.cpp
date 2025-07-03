#include <Arduino.h>
#include <ESP32_Servo.h>
#include "servoMotor.h"
const int servoPin1 = 19;
const int servoPin2 = 18;
const int servoPin3 = 5;
customServo Servo1 = customServo(servoPin1,90);
customServo Servo2 = customServo(servoPin2,90);
customServo Servo3 = customServo(servoPin3,90);

void setup() {
  Serial.begin(9600);
  Servo1.attach();
  Servo2.attach();
  Servo3.attach();
}

void loop() {
  Servo1.linear(0,5);
  Servo1.linear(200,5);
  Servo2.linear(0);
  Servo2.linear(180);
  Servo3.linear(0,100);
  Servo3.linear(180,100);
  delay(200);
}

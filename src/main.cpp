#include <Arduino.h>
#include <ESP32_Servo.h>
#include "servoMotor.h"
int stage = 0;
const int servoPin1 = 19;
const int servoPin2 = 18;
const int servoPin3 = 5;
customServo Servo1 = customServo(servoPin1);
customServo Servo2 = customServo(servoPin2);
customServo Servo3 = customServo(servoPin3);

void setup() {
  Serial.begin(9600);
  Servo1.attach();
  Servo2.attach();
  Servo3.attach();
}

void loop() {
  if(stage == 0){
    Servo1.linear(0);
    Servo1.linear(180);
    Servo2.linear(0);
    Servo2.linear(90);
    Servo3.linear(0);
    Servo3.linear(180);
    Servo3.linear(90);
    stage =1;
  }if(stage == 3){
    stage = 0;
  }
  if(stage == 1){
    Servo1.update();
    Servo2.update();
    if(!Servo1.isMoving()){
    Serial.print("stage2 \t");
    stage = 2;
    }
  }
  if(stage == 2){
    Servo3.update();
    if(!Servo3.isMoving()){
    Serial.println("stage3 \t");
    stage = 3;
    }
  }
}

#include <Arduino.h>
#include <Servo.h>
#include "servoMotor.h"
const int servoPin1 = 18;
int s1Pos;
Servo myservo = Servo();
customServo cusServo1 = customServo(servoPin1,0);
void translate(int servoPin, int position);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(200);
  Serial.println(cusServo1.getServoPos());
  cusServo1.linear(45);
  Serial.println(cusServo1.getServoPos());
  cusServo1.linear(180);
  Serial.println(cusServo1.getServoPos());
  cusServo1.linear(90);
}


void translate(int servoPin, int position){
  for (int pos = s1Pos; pos <= 185; pos++) {  // go from 0-180 degrees
    myservo.write(servoPin1, pos);        // set the servo position (degrees)
    delay(5);
  }
}
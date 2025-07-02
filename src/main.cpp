#include <Arduino.h>
#include <Servo.h>
const int servoPin1 = 18;
int s1Pos;
Servo myservo = Servo();

void translate(int servoPin, int position);

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int pos = 0; pos <= 185; pos++) {  // go from 0-180 degrees
    myservo.write(servoPin1, pos);        // set the servo position (degrees)
    delay(5);
  }
  for (int pos = 185; pos >= 0; pos--) {  // go from 180-0 degrees
    myservo.write(servoPin1, pos);        // set the servo position (degrees)
    delay(5);
  }
  delay(200);
  myservo.write(servoPin1,90);
  delay(200);
  myservo.write(servoPin1,0);
  delay(200);
}

void translate(int servoPin, int position){
  for (int pos = s1Pos; pos <= 185; pos++) {  // go from 0-180 degrees
    myservo.write(servoPin1, pos);        // set the servo position (degrees)
    delay(5);
  }
}
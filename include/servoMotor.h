#include <Arduino.h>
#include <ESP32_Servo.h>

class customServo
{
private:
    int servoPos;
    int servoPin;
    Servo myServo;
public:
    customServo(int Pin,int Pos){
        servoPin = Pin;
        servoPos = Pos;
    };

    int getServoPin(){return servoPin;}

    int getServoPos(){return servoPos;}
    void setServoPos(int pos){servoPos = pos;}

    void attach(){
        myServo.attach(servoPin);
    }

    void linear(int newPos,int speed = 10){
        if(newPos <= servoPos){
            for (int pos = servoPos; pos >= newPos; pos--) {
                myServo.write(pos);// set the servo position (degrees)
                delay(speed);
            }
        }else{
            for (int pos = servoPos; pos <= newPos; pos++) {
                myServo.write(pos);// set the servo position (degrees)
                delay(speed);
            }
        }
        servoPos = newPos;
    }
};
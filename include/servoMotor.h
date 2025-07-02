#include <Servo.h>

class customServo
{
private:
    int servoPos;
    int servoPin;
    Servo myservo;
public:
    customServo(int Pin,int Pos){
        servoPin = Pin;
        servoPos = Pos;
    };

    int getServoPin(){return servoPin;}

    int getServoPos(){return servoPos;}
    void setServoPos(int pos){servoPos = pos;}

    void linear(int newPos){
        if(newPos <= servoPos){
            for (int pos = servoPos; pos >= newPos; pos--) {
                myservo.write(servoPin, pos);// set the servo position (degrees)
                delay(10);
            }
        }else{
            for (int pos = servoPos; pos <= newPos; pos++) {
                myservo.write(servoPin, pos);// set the servo position (degrees)
                delay(10);
            }
        }
        servoPos = newPos;
    }
};
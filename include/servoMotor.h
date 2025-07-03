#pragma once
#include <Arduino.h>
#include <ESP32_Servo.h>

#define Max_Moves 10

class customServo
{
private:
    struct Move{
        int speed;
        int position;
    };

    int servoPos;
    int servoPin;
    Servo myServo;

    // Non-blocking movement
    int targetPos;
    int spd;
    unsigned long lastUpdate = 0;
    bool moving = false;

    //  movement list
    Move movements[Max_Moves];
    int first = 0;
    int last = 0;
public:
    customServo(int Pin){
        servoPin = Pin;
    };

    int getServoPin(){return servoPin;}

    int getServoPos(){return servoPos;}
    void setServoPos(int pos){servoPos = pos;}

    bool isMoving() {return (moving || (first != last));}

    void attach(){
        myServo.attach(servoPin);
        myServo.write(90);
        targetPos = 90;
        servoPos = 90;
    }

    void linear(int newPos,int speed = 15){
        int next = (last + 1) % Max_Moves;
        if (next != first) {  // Check if list is not full
            movements[last].position = newPos;
            movements[last].speed = speed;
            last = next;
        } else {
            // list full
        }
    }

    void update(){
        if(!moving){
            //seeing if there is a move in the list
            if(first != last){
                targetPos = movements[first].position;
                spd = movements[first].speed;
                first = (first + 1) % Max_Moves;
                moving = true;
                lastUpdate = millis();
            }
            return;
        }

        unsigned long currentMillis = millis();
        if (currentMillis - lastUpdate >= spd){
            lastUpdate = currentMillis;

            if(targetPos < servoPos){
                servoPos--;
            }else if(targetPos > servoPos){
                servoPos++;
            }   
            myServo.write(servoPos);

            if (servoPos == targetPos) {
                moving = false;
            }
        }
    }
};
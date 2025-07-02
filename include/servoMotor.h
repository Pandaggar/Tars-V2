
class customServo
{
private:
    int servoPos;
    int servoPin;
public:
    customServo(int Pin,int Pos){
        servoPin = Pin;
        servoPos = Pos;
    };

    int getServoPin(){return servoPin;}

    int getServoPos(){return servoPos;}
    void setServoPos(int pos){servoPos = pos;}
};
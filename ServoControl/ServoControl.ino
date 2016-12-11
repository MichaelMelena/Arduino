#include <Servo.h>


Pins pinsFrontLeftArm;
Pins pinsFrontRightArm;
Pins pinsBackLeftArm;
Pins pinsBackRightArm;

pinsFrontLeftArm.pin1 = 1;
pinsFrontLeftArm.pin2 = 2;
pinsFrontLeftArm.pin2 = 3;

pinsFrontRightArm.pin1 = 4;
pinsFrontRightArm.pin2 = 5;
pinsFrontRightArm.pin3 = 6;

pinsBackLeftArm.pin1 = 7;
pinsBackLeftArm.pin2 = 8;
pinsBackLeftArm.pin3 = 9;

pinsBackRightArm.pin1 = 10;
pinsBackRightArm.pin2 = 11;
pinsBackRightArm.pin3 = 12;



Arm frontLeftArm;
Arm frontRightArm
Arm backLeftArm;
Arm backRightArm



void setup() {
  // put your setup code here, to run once:

  frontLeftArm.servo1.attach(pinsFrontLeftArm.pin1);
  frontLeftArm.servo2.attach(pinsFrontLeftArm.pin2);
  frontLeftArm.servo3.attach(pinsFrontLeftArm.pin3);

  frontRightArm.servo1.attach(pinsFrontRightArm.pin1);
  frontRightArm.servo2.attach(pinsFrontRightArm.pin2);
  frontRightArm.servo3.attach(pinsFrontRightArm.pin3);

//doplnit attach pro zbytek 6 serv
}

void loop() {
  // put your main code here, to run repeatedly:

}

struct Arm
{
  Servo servo1;
  Servo servo2;
  Servo servo3;
}
struct Pins
{
  byte pin1;
  byte pin2;
  byte pin3;
}

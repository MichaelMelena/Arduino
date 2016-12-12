#include <Servo.h>


//
byte FrontLeftArmPin1 = 1;
byte FrontLeftArmPin2 = 2;
byte FrontLeftArmPin3 = 3;

//
byte FrontRightArmPin1 = 4;
byte FrontRightArmPin2 = 5;
byte FrontRightArmPin3 = 6;

//
byte BackLeftArmPin1 = 7;
byte BackLeftArmPin2 = 8;
byte BackLeftArmPin3 = 9;

//
byte BackRightArmPin1 = 10;
byte BackRightArmPin2 = 11;
byte BackRightArmPin3 = 12;

//
Servo frontLeftArmServo1;
Servo frontLeftArmServo2;
Servo frontLeftArmServo3;

//
Servo frontRightArmServo1;
Servo frontRightArmServo2;
Servo frontRightArmServo3;

//
Servo backLeftArmServo1;
Servo backLeftArmServo2;
Servo backLeftArmServo3;

//
Servo backRightArmServo1;
Servo backRightArmServo2;
Servo backRightArmServo3;



void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

//
frontLeftArmServo1.attach(FrontLeftArmPin1);
frontLeftArmServo2.attach(FrontLeftArmPin2);
frontLeftArmServo3.attach(FrontLeftArmPin3);

//
frontRightArmServo1.attach(FrontRightArmPin1);
frontRightArmServo2.attach(FrontRightArmPin2);
frontRightArmServo3.attach(FrontRightArmPin3);

//
backLeftArmServo1.attach(BackLeftArmPin1);
backLeftArmServo2.attach(BackLeftArmPin2);
backLeftArmServo3.attach(BackLeftArmPin3);

//
backRightArmServo1.attach(BackRightArmPin1);
backRightArmServo2.attach(BackRightArmPin2);
backRightArmServo3.attach(BackRightArmPin3);


}

void loop() {
  // put your main code here, to run repeatedly:

  krok();
}
void krok()
{
  //1
  otocRamenem(60,120,120,frontLeftArmServo1,frontLeftArmServo2,frontLeftArmServo3);

 //4
  otocRamenem(60,120,120,backRightArmServo1,backRightArmServo2,backRightArmServo3);
  
  //2
  otocRamenem(90,120,120,frontRightArmServo1,frontRightArmServo2,frontRightArmServo3);
  
  //3
  otocRamenem(90,120,120,backLeftArmServo1,backLeftArmServo2,backLeftArmServo3);

  posunVpred();

  //2
  otocRamenem(90,120,120,frontRightArmServo1,frontRightArmServo2,frontRightArmServo3);

   //3
  otocRamenem(90,120,120,backLeftArmServo1,backLeftArmServo2,backLeftArmServo3);

  //1
  otocRamenem(60,120,120,frontLeftArmServo1,frontLeftArmServo2,frontLeftArmServo3);

   //4
  otocRamenem(60,120,120,backRightArmServo1,backRightArmServo2,backRightArmServo3);

  posunVpred();

}
void posunVpred()
{
int pozice1 = frontLeftArmServo1.read()+30;
int pozice2 = frontRightArmServo1.read()+30;
int pozice3= backLeftArmServo1.read()+30;
int pozice4 = backRightArmServo1.read()+30;

while(frontLeftArmServo1.read() != pozice1 and frontRightArmServo1.read() != pozice2 and backLeftArmServo1.read() != pozice3 and backRightArmServo1.read()!=pozice4)
  {
    otocServo(frontLeftArmServo1.read(),pozice1,frontLeftArmServo1);
    otocServo(frontRightArmServo1.read(),pozice2,frontRightArmServo1);
    otocServo(backLeftArmServo1.read(),pozice3,backLeftArmServo1);
    otocServo(backRightArmServo1.read(),pozice4,backRightArmServo1);
  }
}
void otocRamenem(int konec1 ,int konec2,int konec3,Servo servo1,Servo servo2,Servo servo3)
{
  int pocatek1 =servo1.read();
  int pocatek2 = servo2.read();
  int pocatek3 = servo3.read();
 
  while(servo1.read()!= konec1 and servo2.read()!= konec2 and servo3.read() != konec3)
  {
  otocServo(pocatek3,konec2,servo2);
  otocServo(pocatek2,konec2,servo2);
  otocServo(pocatek1,konec1,servo1);
  }
}
void otocServo(int pocatek,int konec, Servo servo)
{
  int posun = nastavPosun(pocatek,konec);

  
    servo.write(pocatek+posun);
    pocatek++;
    
  
}
int nastavPosun(int pocatek ,int konec)
{
  if(pocatek >konec)
  {
    return 1;
    }
  else if(pocatek<konec)
  {
    return -1;
    }
  else
  {
    return 0;
    }
  }


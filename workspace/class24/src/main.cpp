#include <Arduino.h>
#include <Stepper.h>

// put function declarations here:
int myFunction(int, int);

//Stepper Stepper(steps,1,2,3,4)四相步进电机实例
int STEP=100;
int mot_pin1=8;
int mot_pin2=9;
int mot_pin3=10;
int mot_pin4=11;
Stepper mystepper(STEP,mot_pin1,mot_pin2,mot_pin3,mot_pin4);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  //stepSpeed,通过脉冲频率设置电机转速
  mystepper.setSpeed(STEP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("CW");
  //step通过脉冲数控制电机转动角度
  mystepper.step(STEP);
  delay(500);
  Serial.println("CCW");
  mystepper.step(-1*STEP);
  delay(500);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
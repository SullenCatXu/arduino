#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
//
void checkdistance()
{
  //给Trig发送一个低-高-低的脉冲，10us，触发测距
  digitalWrite(5,LOW);
  delayMicroseconds(2);
  digitalWrite(5,HIGH);
  delayMicroseconds(10);
  digitalWrite(5,LOW);
  float distance_cm;
  //储存Echo的测距高电平时间
  distance_cm=float(pulseIn(4,HIGH)*17/1000);//m/s->cm/us
  Serial.println("distance_cm=");
  Serial.println(distance_cm);
  delay(200);
}

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  //
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkdistance();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
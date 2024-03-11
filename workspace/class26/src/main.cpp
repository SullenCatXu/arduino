#include <Arduino.h>
#include <Servo.h>

// put function declarations here:
int myFunction(int, int);
//
Servo myservo;
//
int pin=9;

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  myservo.attach(pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pos=0;
  for(pos=0;pos<180;pos+=5)
  {
    myservo.write(pos);
    delay(100);
  }
  for(pos=180;pos>0;pos-=5)
  {
    myservo.write(pos);
    delay(100);
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
#include <Arduino.h>

//
int ledPin = 13;
int sensorPin = 2;
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  //
  pinMode(ledPin,OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sensorPin) == HIGH)
  {
    digitalWrite(ledPin,HIGH);
    Serial.print("sensorPin:");
    Serial.println(digitalRead(sensorPin));
    delay(500);
    digitalWrite(ledPin,LOW);
  }
  delay(10);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

int RelayPin = 8;

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  pinMode(RelayPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RelayPin,HIGH);
  delay(2000);
  digitalWrite(RelayPin,LOW);
  delay(200);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
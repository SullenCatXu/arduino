#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
//
int R[] = {2,3,4,5,6,7,8,9};
int C[] = {10,11,12,13,A1,A2,A3,A4};

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  for(int i=0;i<8;i++)
  {
    pinMode(R[i],OUTPUT);
    pinMode(C[i],OUTPUT);
  }
}

//
unsigned char love[8][8]=
{
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,1,0,0,1,0,0,
  0,1,1,1,1,1,1,0,
  0,0,1,1,1,1,0,0,
  0,0,0,1,1,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
};
//
void Clear()
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(R[i],LOW);
    digitalWrite(C[i],HIGH);
  }
}
//
void Display(unsigned char data[8][8])
{
  for(int c=0;c<8;c++)
  {
    digitalWrite(C[c],LOW);
    for(int r=0;r<8;r++)
    {
      digitalWrite(R[r],data[r][c]);
    }
    delay(1);
    Clear();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =0;i<100;i++)
  {
    Display(love);
  };
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
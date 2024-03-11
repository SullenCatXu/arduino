#include <Arduino.h>
#include <Keypad.h>
// put function declarations here:

int myFunction(int, int);
const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
//注意rowPins为从右至左，colPins为从左至右
byte rowPins[ROWS]={5,4,3,2};
byte colPins[COLS]={6,7,8,9};
Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key=keypad.getKey();
  
  if(key!=NO_KEY)
  {
    Serial.println(key);
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
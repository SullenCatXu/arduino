#include <Arduino.h>
#include <IRremote.h>
// put function declarations here:
int myFunction(int, int);
//由于红外线接收到的信号无规律，因此无法识别按键信号
//数字口-pin11
int RECV_PIN = 11;
int LedPin = LED_BUILTIN;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  //int result = myFunction(2, 3);
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  //红外接收开始
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  pinMode(LedPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //检查是否可以接收红外信号
  if(irrecv.decode(&results))
  {
    //输出指令信息
    Serial.println(results.value,HEX);
    //
    if(results.value != 0XFF)
    {
      Serial.println("Turn on");
      digitalWrite(LedPin,HIGH);
    }
    else
    {
      Serial.println("Turn off");
      digitalWrite(LedPin,LOW);
    }
    //接收下一指令
    irrecv.resume();
  }
  delay(100);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
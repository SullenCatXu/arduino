#include <Arduino.h>
/*对太极创客的24 MC猜数字的测试
功能：每次按键后闪动随机图案，最后停留在一个数字上面
*/

// put function declarations here:
int getRandomNumber(int, int);
void displayRandom();
void displayNumber(int);
void displayClear();

void setup() {
  //引脚初始化
  //按键高阻态
  pinMode(2,INPUT_PULLUP);
  //数码管引脚输出态
  int pinNumber = 3;
  while(pinNumber <= 9)
  {
    pinMode(pinNumber,OUTPUT);
    pinNumber += 1;
  }
  //随机数种子获取
  randomSeed(analogRead(A0));
  //串口设置
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //按键识别
  int myNumber;
  if(!digitalRead(2))
  {
    myNumber = getRandomNumber(0,10);//[0,10)
  }
  //数码管显示
  displayNumber(myNumber);
}

// put function definitions here:
/*随机数获取函数*/
int getRandomNumber(int min, int max)
{
  int randomNumber;
  for(int i=0;i<15;i++)
  {
    randomNumber = random(min,max);
    displayRandom();
    delay(100);
    displayClear();
    delay(100);
    //串口显示
    Serial.print(" i = ");
    Serial.println(i);
    Serial.print("randomNumber = ");
    Serial.println(randomNumber);
    Serial.println("");
  }
  return randomNumber;
}

/*随机数显示函数*/
void displayRandom()
{
  int randomPin = random(3,9);
  digitalWrite(randomPin,HIGH);
}

/*数码管显示函数*/
void displayNumber(int Number)
{
  switch(Number)
  {
    case 1: //显示1
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      break;
    case 2: //显示2
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      break;
    case 3: //显示3
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;  
    case 4:  //显示4
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      break;  
    case 5:  //显示5
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;
    case 6:  //显示6
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;    
    case 7:  //显示7
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(7, HIGH);  
      break;
    case 8:  //显示8
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;
    case 9:  //显示9
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;
    case 0:  //显示默认
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;
    default:
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
  };
}

/*数码管清理函数*/
void displayClear()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
#include <Arduino.h>
#include <DHT.h>
// put function declarations here:
int myFunction(int, int);
//
int dhtpin=8;
DHT dht(dhtpin,DHT11);
//
void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float humidity=dht.readHumidity();
  float temperature=dht.readTemperature();
  Serial.print("humidity:");
  Serial.println(humidity);
  Serial.print("temperature:");
  Serial.println(temperature);
  delay(500);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
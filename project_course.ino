#include <dht11.h>
#define DHT11_PIN 7
dht11 DHT11;
#include <Servo.h>
Servo myservo;
int pos = 0;
#include <LiquidCrystal.h> 
int Contrast=80;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int photocellPin = 0;   
void setup() {
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  myservo.attach(13);
  Serial.begin(9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
}

void loop() {
  int lux = analogRead(photocellPin);
  int chk = DHT11.read(DHT11_PIN);
  Serial.print("brightness=");
  Serial.print(lux);
  Serial.print(" Temp=");
  Serial.print((float)DHT11.temperature);
  Serial.print(" C");
  Serial.print(" Humidity=");
  Serial.print((float)DHT11.humidity);
  Serial.print("%");
  Serial.print("\n");
  if(lux>=100){
    digitalWrite(10,HIGH);
    digitalWrite(8,LOW);
    myservo.write(90);
  }
  if(lux<100){
    digitalWrite(10,LOW);
    digitalWrite(8,HIGH);
    myservo.write(0);
  }
   lcd.setCursor(0,0); 
   lcd.print("Temp: ");
   lcd.print(DHT11.temperature);
   lcd.print((char)223);
   lcd.setCursor(0, 1);
   lcd.print("Humidity: ");
   lcd.print(DHT11.humidity);
   lcd.print("%");
   delay(200);
}

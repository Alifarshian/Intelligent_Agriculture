#include <Servo.h>
Servo myservo;
int pos = 0;
int photocellPin = 0;
int humidityPin=1;    
void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(A0,INPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  int lux = analogRead(photocellPin);
  Serial.print("brightness=");
  Serial.print(lux);
  Serial.print(" humidity=");
  if(lux>=100){
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    myservo.write(90);
  }
  if(lux<100){
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    myservo.write(0);
  }
}

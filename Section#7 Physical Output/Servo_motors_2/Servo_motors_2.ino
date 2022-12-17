#include <Servo.h>
Servo myservo;
const int potPin = A0;

void setup(){
  myservo.attach(9);
  pinMode(potPin, INPUT);
  
}
void loop(){
  int potValue = analogRead(potPin);
  int servoAngle = map(potValue, 0, 1023, 0, 180);
  myservo.write(servoAngle);
  delay(50);
}

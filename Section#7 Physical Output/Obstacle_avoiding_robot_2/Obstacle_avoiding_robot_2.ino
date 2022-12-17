const int MotorLeftIN = 2;
const int MotorLeftPWM = 3;
const int MotorRightIN = 4;
const int MotorRightPWM = 5;

const int trigPin = 8;
const int echoPin = 9;
long value = 0;
int cm = 0;

void setup(){
  pinMode(MotorLeftIN, OUTPUT);
  pinMode(MotorLeftPWM, OUTPUT);
  pinMode(MotorRightIN, OUTPUT);
  pinMode(MotorRightPWM, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}
void loop(){
  getdistance();

  if(cm<20 && cm>0){
    stopMovement();
    moveBackward(-150);
    delay(1000);
    turnRight(140);
    delay(400);
  }else{
    moveForward(155);
  }
  
}

void moveForward(int motorSpeed){
  //motorSpeed should be 1 to 255
  analogWrite(MotorLeftPWM, motorSpeed);
  digitalWrite(MotorLeftIN, 0);
  analogWrite(MotorRightPWM, motorSpeed);
  digitalWrite(MotorRightIN, 0);
}

void stopMovement(){
  analogWrite(MotorLeftPWM, 0);
  digitalWrite(MotorLeftIN, 0);
  analogWrite(MotorRightPWM, 0);
  digitalWrite(MotorRightIN, 0);
}

void moveBackward(int motorSpeed){
  //motorSpeed should be -255 to -1
  analogWrite(MotorLeftPWM, motorSpeed);
  digitalWrite(MotorLeftIN, 1);
  analogWrite(MotorRightPWM, motorSpeed);
  digitalWrite(MotorRightIN, 1);
}

void turnRight(int motorSpeed){
  analogWrite(MotorLeftPWM, motorSpeed);
  digitalWrite(MotorLeftIN, 0);
  analogWrite(MotorRightPWM, motorSpeed*-1);
  digitalWrite(MotorRightIN, 1);
}

void turnLeft(int motorSpeed){
  analogWrite(MotorLeftPWM, motorSpeed*-1);
  digitalWrite(MotorLeftIN, 1);
  analogWrite(MotorRightPWM, motorSpeed);
  digitalWrite(MotorRightIN, 0);
}

void getdistance(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  value = pulseIn(echoPin, HIGH, 50000);
  cm = value / 58;
  Serial.print(value);
  Serial.print(" ; ");
  Serial.println(cm);
}

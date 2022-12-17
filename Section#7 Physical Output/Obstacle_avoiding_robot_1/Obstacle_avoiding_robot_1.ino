const int MotorLeftIN = 2;
const int MotorLeftPWM = 3;
const int MotorRightIN = 4;
const int MotorRightPWM = 5;

void setup(){
  pinMode(MotorLeftIN, OUTPUT);
  pinMode(MotorLeftPWM, OUTPUT);
  pinMode(MotorRightIN, OUTPUT);
  pinMode(MotorRightPWM, OUTPUT);
  Serial.begin(9600);

  moveForward(150);
  delay(1000);
  moveBackward(150);
}
void loop(){
  
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

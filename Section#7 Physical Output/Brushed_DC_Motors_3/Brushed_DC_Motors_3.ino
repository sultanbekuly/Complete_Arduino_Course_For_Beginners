const int MOTOR1_IN = 2;
const int MOTOR1_PWM = 3;
const int MOTOR2_IN = 4;
const int MOTOR2_PWM = 5;
const int pot = A0;
const int motorLowest = 100;

void setup(){
  pinMode(MOTOR1_IN, OUTPUT);
  pinMode(MOTOR1_PWM, OUTPUT);
  pinMode(MOTOR2_IN, OUTPUT);
  pinMode(MOTOR2_PWM, OUTPUT);
  Serial.begin(9600);
  pinMode(pot, INPUT);
}
void loop(){
  int potReading = analogRead(pot);//0-1023
  int motorSpeed = map(potReading, 0, 1023, -255, 255);
  
  Serial.print(potReading);
  Serial.print(" = ");
  Serial.println(motorSpeed);

  if(motorSpeed > 20){
    motorSpeed = map(motorSpeed, 0, 255, motorLowest, 255);
    analogWrite(MOTOR1_PWM, motorSpeed);
    digitalWrite(MOTOR1_IN, 0);
  }else if(motorSpeed < -20){
    motorSpeed = map(motorSpeed, -255, 0, -255, motorLowest * -1);
    analogWrite(MOTOR1_PWM, motorSpeed);
    digitalWrite(MOTOR1_IN, 1);
  }else{
    analogWrite(MOTOR1_PWM, 0);
    digitalWrite(MOTOR1_IN, 0);
  }  
}

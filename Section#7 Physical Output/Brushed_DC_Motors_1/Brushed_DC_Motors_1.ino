const int MOTOR1_IN = 2;
const int MOTOR1_PWM = 3;
const int MOTOR2_IN = 4;
const int MOTOR2_PWM = 5;

void setup(){
  pinMode(MOTOR1_IN, OUTPUT);
  pinMode(MOTOR1_PWM, OUTPUT);
  pinMode(MOTOR2_IN, OUTPUT);
  pinMode(MOTOR2_PWM, OUTPUT);
  Serial.begin(9600);

  //Spin in one direciton
  analogWrite(MOTOR1_PWM, 255);
  digitalWrite(MOTOR1_IN, 0);
  delay(2000);

  //Spin in opposite direction
  analogWrite(MOTOR1_PWM, -255);
  digitalWrite(MOTOR1_IN, 1);
  delay(2000);

  //Stop motors
  analogWrite(MOTOR1_PWM, 0);
  digitalWrite(MOTOR1_IN, 0);

}
void loop(){
  
}

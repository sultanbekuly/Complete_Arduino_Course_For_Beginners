const int pot_pin = A0;
const int led_pin = 13;

void setup(){
  pinMode(pot_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop(){
  int sensorValue = analogRead(pot_pin);
  
  digitalWrite(led_pin, HIGH);
  delay(sensorValue);
  digitalWrite(led_pin, LOW);
  delay(sensorValue);
}

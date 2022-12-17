const int pot_pin = A0;

void setup(){
  Serial.begin(9600);
  pinMode(pot_pin, INPUT);
}

void loop(){
  int sensorValue = analogRead(pot_pin);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
}

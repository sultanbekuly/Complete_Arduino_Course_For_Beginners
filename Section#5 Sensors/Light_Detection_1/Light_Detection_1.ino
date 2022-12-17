const int ldrPin = A0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println( analogRead(ldrPin) );
  delay(100);
}

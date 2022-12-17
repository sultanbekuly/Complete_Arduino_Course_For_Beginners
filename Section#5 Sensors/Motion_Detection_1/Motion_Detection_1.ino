const int pirPin = 2;

void setup(){
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println( digitalRead(pirPin) );
  delay(100);
}

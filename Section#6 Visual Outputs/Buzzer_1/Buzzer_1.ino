const int buzzerPin = 9;

void setup(){
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  tone(buzzerPin, 440, 500);
  delay(1000);

  tone(buzzerPin, 440);
  delay(500);
  noTone(buzzerPin);
  delay(500);
}

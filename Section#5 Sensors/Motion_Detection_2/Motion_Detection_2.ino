const int pirPin = 2;
const int ledPin = 13;

void setup(){
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  bool pirReading = digitalRead(pirPin);
  digitalWrite(ledPin, pirReading);
  delay(100);
}

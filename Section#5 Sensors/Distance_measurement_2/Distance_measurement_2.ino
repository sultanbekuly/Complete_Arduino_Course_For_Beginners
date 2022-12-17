const int trigPin = 4;
const int echoPin = 3;
const int ledPin = 13;

long value = 0;
int cm = 0;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  value = pulseIn(echoPin, HIGH, 50000);
  cm = value / 58;
  Serial.print(value);
  Serial.print(";");
  Serial.println(cm);

  digitalWrite(ledPin, HIGH);
  delay(cm * 10);
  digitalWrite(ledPin, LOW);
  delay(cm * 10);
}

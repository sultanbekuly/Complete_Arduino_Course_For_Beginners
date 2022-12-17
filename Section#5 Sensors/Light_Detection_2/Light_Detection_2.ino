const int ldrPin = A0;
const int ledPin = 13;
const int darknessTreshold = 500;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  Serial.println( analogRead(ldrPin) );

  if(analogRead(ldrPin) < darknessTreshold){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  //analogWrite(led_pin, led_value);
}
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(11, 0);
  delay(500);
  analogWrite(11, 128);
  delay(500);
  analogWrite(11, 255);
  delay(500);
}

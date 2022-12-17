void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello");
  Serial.print("1");
  Serial.print("2");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!");
  delay(1000);
}

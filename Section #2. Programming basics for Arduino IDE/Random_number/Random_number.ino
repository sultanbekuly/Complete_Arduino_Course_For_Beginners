void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //random(fromNumber, tillNumber);
  randomSeed(analogRead(A0));
  for(int i=0; i<5; i++){
    Serial.print(random(1,11));
    Serial.print(" ");
  }
  Serial.println("Done!");
  
}
void loop() {
  // put your main code here, to run repeatedly:
  
}

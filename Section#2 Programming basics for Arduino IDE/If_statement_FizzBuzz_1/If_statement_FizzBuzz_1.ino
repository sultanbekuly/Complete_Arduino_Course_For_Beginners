void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int x = 0;
void loop() {
  // put your main code here, to run repeatedly:
  x = x+1;
  delay(500);
  if(x%3==0){
    Serial.println("Fizz");
  }else{
    Serial.println(x);
  }
}

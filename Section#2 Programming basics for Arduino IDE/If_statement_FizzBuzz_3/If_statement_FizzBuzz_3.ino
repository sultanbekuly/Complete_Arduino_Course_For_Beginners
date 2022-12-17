void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int x = 0;
void loop() {
  // put your main code here, to run repeatedly:
  x = x+1; //incrementing 
  delay(500);

  if(x%3==0 && x%5==0){
    Serial.println("FizzBuzz");
  }else if(x%3==0){
    Serial.println("Fizz");
  }else if(x%5==0){
    Serial.println("Buzz");
  }else{
    Serial.println(x);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int x = sum(20,11);
  Serial.println(x);

  Serial.println(sum(53,67));
  Serial.println("setup finished");
  
}

int z =0;
int y = 5;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(sum(z,y));
  z++;
  y += 3;
  delay(500);
}
/*
ReturnType functionName (parameterType parameterName, ...){
  Function body
  Optionally returnValue
}
*/

int sum(int a, int b){
  int c = a + b;
  return c;
}

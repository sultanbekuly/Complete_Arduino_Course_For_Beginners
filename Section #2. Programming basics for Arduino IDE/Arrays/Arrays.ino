void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int x[5];
  Serial.println(x[0]);
  
  int y[2] = {11,22};
  Serial.println(y[0]);
  Serial.println(y[1]);

  y[0] = 33;

  Serial.println("y[0] changed");
  Serial.println(y[0]);

  
}

void loop() {
  // put your main code here, to run repeatedly:

}

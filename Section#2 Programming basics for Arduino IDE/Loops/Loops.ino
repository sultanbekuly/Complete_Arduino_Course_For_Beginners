void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*
  for(initialization; condition; expression){
    //Do Something
  }
  */
  Serial.println("for loop");
  for(int j=0; j<4; j++){
    Serial.println(j);
  }
  /*
  while(expression){
    //Do Something
  }
  */
  int j = 0;
  Serial.println("while loop");
  while (j<4){
    Serial.println(j);
    j++;
  }

  /*
  do{
    //Do Something
  }while(expression)
  */
  int k = 4;
  Serial.println("do while test");
  do{
    Serial.println(k);
    k++;
  }while (k<4);
  Serial.println("done");
  
}
void loop() {
  // put your main code here, to run repeatedly:
  
}

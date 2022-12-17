void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int j = 0;
  while (j<5){
    if(j==2){
      Serial.println("Break!");
      break;
    }
    Serial.println(j);
    j++;
  }
  Serial.println("Done!");

  Serial.println("--for loop start--");
  for(int j = 0; j<5; j++){
    if(j==2){
      Serial.println("continue");
      continue;
    }
    Serial.println(j);
  }
  Serial.println("--for loop done!--");
  
}
void loop() {
  // put your main code here, to run repeatedly:
  
}

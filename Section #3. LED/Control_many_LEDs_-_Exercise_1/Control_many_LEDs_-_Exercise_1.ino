int led[6] = {8,9,10,11,12,13};

void setup()
{ 
  for(int i=0;i<6;i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  for(int i=0;i<6;i=i+2){
    digitalWrite(led[i], HIGH);
  }
  for(int i=1;i<6;i=i+2){
    digitalWrite(led[i], LOW);
  }
  delay(500); 
  for(int i=0;i<6;i=i+2){
    digitalWrite(led[i], LOW);
  }
  for(int i=1;i<6;i=i+2){
    digitalWrite(led[i], HIGH);
  }
  delay(500);
  
  //OR
  
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], HIGH);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], HIGH);
  digitalWrite(led[5], LOW);
  delay(500);
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], HIGH);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], HIGH);
  digitalWrite(led[4], LOW);
  digitalWrite(led[5], HIGH);
  delay(500);
}

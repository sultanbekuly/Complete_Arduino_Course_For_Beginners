int led[6] = {8,9,10,11,12,13};

void setup()
{ 
  for(int i=0;i<6;i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  int j = 5;
  for(int i=0 ;i<3;i++){
    digitalWrite(led[i], HIGH);
    digitalWrite(led[i+j], HIGH);
    delay(300); 
    j=j-2;
    
  }

  j = 5;
  for(int i=0 ;i<3;i++){
    digitalWrite(led[i], LOW);
    digitalWrite(led[i+j], LOW);
    delay(300); 
    j=j-2;
    
  }
  
}

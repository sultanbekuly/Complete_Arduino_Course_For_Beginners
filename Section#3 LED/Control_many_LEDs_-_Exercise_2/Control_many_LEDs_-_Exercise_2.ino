// C++ code

int led[6] = {8,9,10,11,12,13};

void setup()
{ 
  for(int i=0;i<6;i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  for(int i=0;i<6;i++){
    digitalWrite(led[i], HIGH);
    delay(300); 
    digitalWrite(led[i], LOW);
  }
  for(int i=5;i>0;i--){
    digitalWrite(led[i], HIGH);
    delay(300); 
    digitalWrite(led[i], LOW);
  }

}

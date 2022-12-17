/*int led_13 = 13;
int led_12 = 12;
int led_11 = 11;
int led_10 = 10;
int led_9 = 9;
int led_8 = 8;*/

int led[6] = {8,9,10,11,12,13};

void setup() {
  // put your setup code here, to run once:
  /*pinMode(led_13, OUTPUT);
  pinMode(led_12, OUTPUT);
  pinMode(led_11, OUTPUT);
  pinMode(led_10, OUTPUT);
  pinMode(led_9, OUTPUT);
  pinMode(led_8, OUTPUT);*/

  for(int i=0; i<6; i++){
    pinMode(led[i], OUTPUT);
  }
  
}
void loop() {
  // put your main code here, to run repeatedly:
  //#1 example
  /*
  for(int i=0; i<6; i++){
    digitalWrite(led[i], HIGH);
    delay(200);
    digitalWrite(led[i], LOW);
  }*/
  //#2 example
  for(int i=0; i<6; i++){
    digitalWrite(led[i], HIGH);
    delay(200);
  }
  for(int i=0; i<6; i++){
    digitalWrite(led[i], LOW);
  }
  delay(200);
}

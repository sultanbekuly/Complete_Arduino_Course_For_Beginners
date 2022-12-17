int btn_pullup = 2;
int led = 13;

void setup(){ 
  pinMode(btn_pullup, INPUT);
  digitalWrite(btn_pullup, HIGH);
  
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  bool btn_state = digitalRead(btn_pullup);
  if(btn_state == LOW){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  delay(200);
}

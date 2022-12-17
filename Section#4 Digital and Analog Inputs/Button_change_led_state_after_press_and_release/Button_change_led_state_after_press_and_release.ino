int btn_pullup = 2;
int led = 13;
bool prev_btn_state;
bool led_state = false;

void setup(){ 
  pinMode(btn_pullup, INPUT);
  digitalWrite(btn_pullup, HIGH);
  
  pinMode(led, OUTPUT);
  Serial.begin(9600);  
}

void loop(){
  bool btn_state = digitalRead(btn_pullup);
  //Serial.println(btn_state);
  
  if(btn_state == HIGH && prev_btn_state == LOW){
    led_state = !led_state;
  }
  digitalWrite(led, led_state);
  prev_btn_state = btn_state;
}

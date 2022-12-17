const int btn_pullup = 2;
const int led = 13;
const int debounce_delay = 50; // ms

bool btn_state;
bool prev_btn_state;
bool led_state = LOW;
unsigned long btn_last_debounce = 0;

void setup(){
  pinMode(btn_pullup, INPUT);
  digitalWrite(btn_pullup, HIGH);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  bool btn_state_reading = digitalRead(btn_pullup);
  if(btn_state_reading == HIGH && prev_btn_state == LOW){
    btn_last_debounce = millis();
  }
  if(millis() > (btn_last_debounce + debounce_delay) ){
    if(btn_state != btn_state_reading){
      btn_state = btn_state_reading;
      if(btn_state_reading == HIGH){
        led_state = ! led_state;
      }
    }
  }
  digitalWrite(led, led_state);
  prev_btn_state = btn_state_reading;
}

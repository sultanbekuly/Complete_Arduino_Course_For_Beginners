#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

byte customChar[] = {
  B11111,
  B10101,
  B11111,
  B11111,
  B01110,
  B01010,
  B01010,
  B11011
};

const int btnLeft = 9;
const int btnRight = 8;

const int debounce_delay = 50;  // ms

bool btnL_state=HIGH;
bool prev_btnL_state;
unsigned long btnL_last_debounce = 0;

bool btnR_state=HIGH;
bool prev_btnR_state;
unsigned long btnR_last_debounce = 0;

int position = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, customChar);
  Serial.begin(9600);
  
  pinMode(btnLeft, INPUT);
  pinMode(btnRight, INPUT);
  digitalWrite(btnLeft, HIGH);
  digitalWrite(btnRight, HIGH);
  
  customCharShow();
}

  

void loop(){
  bool btnL_state_reading = digitalRead(btnLeft);
  bool btnR_state_reading = digitalRead(btnRight);
  
  if(btnL_state_reading == HIGH && prev_btnL_state == LOW){
    btnL_last_debounce = millis();
  }  
  if(btnR_state_reading == HIGH && prev_btnR_state == LOW){
    btnR_last_debounce = millis();
  } 
  
  if ( millis() > (btnL_last_debounce + debounce_delay) ) {
    if(btnL_state != btnL_state_reading){
      btnL_state = btnL_state_reading;
      if(btnL_state_reading == HIGH){        
        Serial.println("LEFT");
        movechar('L');
      }
    }
  }
  if ( millis() > (btnR_last_debounce + debounce_delay) ) {
    if(btnR_state != btnR_state_reading){
      btnR_state = btnR_state_reading;
      if(btnR_state_reading == HIGH){        
        Serial.println("RIGHT");
        movechar('R');
      }
    }
  }
    
    
  prev_btnL_state = btnL_state_reading;
  prev_btnR_state = btnR_state_reading;
}

void movechar(char direction){
  if(direction=='L' ){
    if(position>=1){
      position = position - 1;
      Serial.println("position changed");
      customCharShow();
    }
  }else if(direction=='R' ){
    if(position<=14){
      position = position + 1;
      Serial.println("position changed");
      customCharShow();
    }
  }
}

void customCharShow(){
  lcd.clear();
  lcd.setCursor(position,1);
  lcd.write((byte)0);
}

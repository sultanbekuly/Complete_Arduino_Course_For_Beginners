int led_G = 9;
int led_B = 10;
int led_R = 11;

void setup(){ 
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  pinMode(led_R, OUTPUT);
}

void loop(){
  /*
  digitalWrite(led_G, HIGH);
  delay(1000);
  digitalWrite(led_G, LOW);
  
  digitalWrite(led_B, HIGH);
  delay(1000);
  digitalWrite(led_B, LOW);
  
  digitalWrite(led_R, HIGH);
  delay(1000);
  digitalWrite(led_R, LOW);
  */
  /*
  digitalWrite(led_B, HIGH);
  digitalWrite(led_G, HIGH);
  delay(1000);
  digitalWrite(led_B, LOW);
  digitalWrite(led_G, LOW);
  
  digitalWrite(led_B, HIGH);
  digitalWrite(led_R, HIGH);
  delay(1000);
  digitalWrite(led_B, LOW);
  digitalWrite(led_R, LOW);

  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, HIGH);
  delay(1000);
  digitalWrite(led_R, LOW);
  digitalWrite(led_G, LOW);

  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, HIGH);
  digitalWrite(led_B, HIGH);
  delay(1000);
  digitalWrite(led_R, LOW);
  digitalWrite(led_G, LOW);
  digitalWrite(led_B, LOW);
  */
  rgb_led(255,153,0);
  delay(1000);

  rgb_led(153,153,255);
  delay(1000);

  rgb_led(51,51,153);
  delay(1000);

  rgb_led(153,51,0);
  delay(1000);

  rgb_led(153,204,255);
  delay(1000);
  
}

void rgb_led(int r, int, g, int b){
  analogWrite(led_R, r);
  analogWrite(led_G, g);
  analogWrite(led_B, b);
  
}

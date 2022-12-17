int btn_pullup = 4;
int btn_pulldown = 10;

void setup(){ 
  pinMode(btn_pullup, INPUT);
  pinMode(btn_pulldown, INPUT);
  Serial.begin(9600);
}

void loop(){
   Serial.print( digitalRead(btn_pulldown) );
   Serial.print(" ");
   Serial.println( digitalRead(btn_pullup) );
   delay(200);
}

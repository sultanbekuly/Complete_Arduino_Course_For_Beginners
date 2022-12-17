const int segmentPins[8] = {2,3,4,6,7,8,9,5}; //A,B,C,D,E,F,G,dp

void setup(){
  for(int i = 0; i<8 ; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop(){
  for(int i=0; i<8; i++){
    digitalWrite(segmentPins[i], HIGH);
    delay(1000);
    digitalWrite(segmentPins[i], LOW);
  }
}

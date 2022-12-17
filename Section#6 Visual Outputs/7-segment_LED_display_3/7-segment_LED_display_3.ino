const int segmentPins[8] = {2,3,4,6,7,8,9,5};
                          //A,B,C,D,E,F,G,dp
                          //0,1,2,3,4,5,6,7
const int loading[8] = {0,1,6,4,3,2,6,5};
                      //A,B,G,E,D,C,G,F
                          
void setup(){
  for(int i = 0; i<8; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop(){
  for(int i=0; i<8; i++){
    for(int segment=0; segment<8; segment++){
      bool isBitSet = loading[i]==segment;
      //isBitSet = !isBitSet; //for common Anode
      digitalWrite(segmentPins[segment], isBitSet);
    }
    delay(200);
  }
}

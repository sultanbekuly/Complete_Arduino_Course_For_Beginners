const byte numeral[10][8] = {
    {1,1,1,1,1,1,0,0}, // 0
    {0,1,1,0,0,0,0,0}, // 1
    {1,1,0,1,1,0,1,0}, // 2
    {1,1,1,1,0,0,1,0}, // 3
    {0,1,1,0,0,1,1,0}, // 4
    {1,0,1,1,0,1,1,0}, // 5
    {0,0,1,1,1,1,1,0}, // 6
    {1,1,1,0,0,0,0,0}, // 7
    {1,1,1,1,1,1,1,0}, // 8
    {1,1,1,0,0,1,1,0} // 9
}; //A,B,C,D,E,F,G,dp
const int segmentPins[8] = {9, 2, 3, 5, 6, 8, 7, 4};//Arduino pins
                          //A, B, C, D, E, F, G, dp
                          //11,7, 4, 2, 1, 10,5, 3  //4-digit 7-segment LED display pins

const int digitPins[4] = {13, 12, 11, 10};//Arduino pins
                        //4,  3,  2,  1   //Digits
                        //6,  8,  9,  12  //4-digit 7-segment LED display pins

unsigned long count = 0;

void setup(){
  for(int i=0; i<8; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
  for(int i=0; i<4; i++){
    pinMode(digitPins[i], OUTPUT);
  }
}

void loop(){
  if(millis()/100 > count){
    count++;
  }
  showNumber(count);
}

void showNumber(int num){
  for(int i=0; i<4; i++){
    showDigit(num %10,i);
    num = num / 10;
  }
}

void showDigit(int digit, int pos){
  if(digit>=0 && digit <=9){
    for(int segment=0; segment<8; segment++){
      digitalWrite(segmentPins[segment], numeral[digit][segment]);
    }
    digitalWrite(digitPins[pos], LOW);
    //delay(300);
    delayMicroseconds(300);
    digitalWrite(digitPins[pos], HIGH);
  }
}

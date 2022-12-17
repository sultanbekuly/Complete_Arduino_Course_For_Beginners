#include <IRremote.h> //adds the library code to the sketch
const int irReceiverPin = 2; //pin the receiver is connected

const int NUM_OF_BUTS = 21;

unsigned long BUTTON_CODES[NUM_OF_BUTS] = {
  3910598400, //button 0
  4077715200, //button 1
  3877175040, //button 2
  2707357440, //button 3
  4144561920, //button 4
  3810328320, //button 5
  2774204160, //button 6
  3175284480, //button 7
  2907897600, //button 8
  3041591040, //button 9
  3860463360, //button 100+/DOWN
  4061003520, //button 200+/UP
  4161273600, //button VOL-
  3927310080, //button VOL+
  4127850240, //button EQ/MENU
  3141861120, //button PREV/LEFT
  3208707840, //button NEXT/RIGHT
  3158572800, //button PAUSE/MUTE
  3125149440, //button CH-
  3108437760, //button CH/POWER
  3091726080  //button CH+
};

String BUTTON_NAMES[NUM_OF_BUTS] = {
  "0","1","2","3","4","5","6","7","8","9",
  "100+/DOWN","200+/UP","VOL-","VOL+",
  "EQ/MENU","PREV/LEFT","NEXT/RIGHT",
  "PAUSE/MUTE","CH-","CH/POWER","CH+"
};

void setup(){
  IrReceiver.begin(irReceiverPin, ENABLE_LED_FEEDBACK); // Start the receiver object
  Serial.begin(9600);
}
void loop(){
  if(IrReceiver.decode()){ //true if message received
    //Serial.println(IrReceiver.decodedIRData.decodedRawData);
    int button_id = findButton(IrReceiver.decodedIRData.decodedRawData);
    if(button_id < 0){
      Serial.println("Unknown button is pressed!");
      Serial.println(IrReceiver.decodedIRData.decodedRawData);
    }else{
      Serial.print("Button ");
      Serial.print(BUTTON_NAMES[button_id]);
      Serial.println(" is pressed");
    }
    delay(100);
    IrReceiver.resume(); //watch out for another message
  }
}

int findButton(unsigned long val){
  for(int i=0; i< NUM_OF_BUTS; i++){
    if(val == BUTTON_CODES[i]){
      return i;
    }
  }
  return -1;
}

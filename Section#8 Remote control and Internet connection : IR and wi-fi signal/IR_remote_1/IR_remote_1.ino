#include <IRremote.h> //adds the library code to the sketch
const int irReceiverPin = 2; //pin the receiver is connected

void setup(){
  IrReceiver.begin(irReceiverPin, ENABLE_LED_FEEDBACK); // Start the receiver object
  Serial.begin(9600);
}
void loop(){
  if(IrReceiver.decode()){ //true if message received
    Serial.println(IrReceiver.decodedIRData.decodedRawData);
    delay(100);
    IrReceiver.resume(); //watch out for another message
  }
  
}

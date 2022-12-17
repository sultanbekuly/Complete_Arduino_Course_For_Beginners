#include <SoftwareSerial.h>
SoftwareSerial wifiSerial(10,9);//TX, RX

void setup(){
  Serial.begin(9600);
  wifiSerial.begin(115200); //can't be faster than 115200
  wifiSerial.setTimeout(5000);
}
void loop(){
  while(Serial.available()){
    wifiSerial.print((char)Serial.read());
  }
  while(wifiSerial.available()){
    Serial.print((char)wifiSerial.read());
  }
}

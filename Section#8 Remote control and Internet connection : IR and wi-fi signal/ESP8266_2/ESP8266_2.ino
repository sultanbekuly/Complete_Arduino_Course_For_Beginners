#include <SoftwareSerial.h>
SoftwareSerial wifiSerial(10,9);//TX, RX

//WiFi config
String ssid = "iPhone";
String password = "12345678";

//Server, file, and port
const String hostname = "example.com";
const String uri = "/index.html";
const int port = 80;

void setup(){
  Serial.begin(9600);
  wifiSerial.begin(115200); //can't be faster than 115200
  wifiSerial.setTimeout(5000);

  //Talk to ESP8266
  Serial.println("AT");
  wifiSerial.println("AT");
  delay(10);
  if(wifiSerial.find("OK") == 0){
    Serial.println("ESP8266 not found");
    while(1);
  }

  //Connect to WiFi
  Serial.println("Connecting to WiFi..");
  wifiSerial.println("AT+CWJAP=\""+ssid+"\",\""+password +"\"");
  delay(10);
  if(wifiSerial.find("OK") == 0){
    Serial.println("Could not connect to the WiFi");
    while(1);
  }
  Serial.println("Connected to the WiFi");

  //Open TCP connection
  Serial.println("AT+CIPSTART=\"TCP\""+hostname+"\","+port);
  wifiSerial.println("AT+CIPSTART=\"TCP\""+hostname+"\","+port);
  delay(50);
  if(wifiSerial.find("OK") == 0){
    Serial.println("Error");
    while(1);
  }
  
  //Construct HTTP request
  String req = "GET "+uri+" HTTP/1.1\r\n"+
        "Host: "+ hostname + "\r\n" +
        "Connection: close\r\n"+
        "\r\n";
  int len = req.length();
  
  //Send our request length
  wifiSerial.print("AT+CIPSEND=");
  wifiSerial.println(len);
  Serial.print("AT+CIPSEND=");
  Serial.println(len);
  delay(10);
  if(wifiSerial.find(">") == 0){
    Serial.println("Error");
    while(1);
  }

  //Send our http request
  wifiSerial.println(req);
  Serial.println(req);
  delay(10);
  if(wifiSerial.find("SEND OK\r\n") == 0){
    Serial.println("Error");
    while(1);
  }

  //wait for a response from the server
  while(wifiSerial.available() == 0){
    delay(5);
  }

  //print reply from the server
  while(wifiSerial.available()){
    String message = wifiSerial.readStringUntil('\r');
    Serial.println(message);
  }

  //Close TCP connection
  wifiSerial.println("AT+CIPCLOSE=0");
  delay(50);
  if(wifiSerial.find("OK") == 0){
    Serial.println("Error");
  }else{
    Serial.println("Connection closed!");
  }
}
void loop(){
  while(Serial.available()){
    wifiSerial.print((char)Serial.read());
  }
  while(wifiSerial.available()){
    Serial.print((char)wifiSerial.read());
  }
}

#include <ESP8266WiFi.h>

//wi-fi settings
const char ssid[] = "iPhone";
const char password[] = "12345678";
//const char ssid[] = "Bibigul";
//const char password[] = "09061965B";

//Server, file, and port
const String hostname = "example.com";
const String uri = "/index.html";
const int port = 80;

//WiFi client
WiFiClient client; // here will be stored the TCP connection

void setup(){
  Serial.begin(9600);
  delay(100);
  //no need to start the software serial
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected");

  //Print IP address
  Serial.println(WiFi.localIP());

  //Connect to the server
  Serial.print("Connecting to ");
  Serial.println(hostname);
  if(client.connect(hostname, port)==0){
    Serial.println("Connection failed");
  }

  //Send the GET request
  client.print("GET "+uri+" HTTP/1.1\r\n"+
                "Host: "+hostname+"\r\n"+
                "Connection: close\r\n"+
                "\r\n");
  delay(500);

  //Print reply from the server
  while(client.available()){
    String response = client.readStringUntil('\r');
    Serial.println(response);
  }

  //Close the TCP connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");
}
void loop(){
  
}

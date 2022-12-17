#include <ESP8266WiFi.h>

//wifi client
WiFiClientSecure httpsClient;

//wi-fi settings
const char ssid[] = "iPhone";
const char password[] = "12345678";

//API and city name
const char *authorization = "cc...a2";//place here your API key
const char *cityName = "San Francisco";

const char *host = "api.openweathermap.org";
const int httpsPort = 443;
int httpsClientTimeout = 5000; //in millis

void setup() {
  Serial.begin(9600);

  //Connect to the WiFi
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to wifi: ");
  Serial.print(ssid);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to wifi: ");
  Serial.println(ssid);

  //Connect to the Server
  httpsClient.setInsecure();
  httpsClient.setTimeout(httpsClientTimeout);
  delay(1000);
  int retry = 0;
  while( (!httpsClient.connect(host, httpsPort) ) && (retry <15) ){
    delay(100);
    Serial.print(".");
    retry++;
  }
  if(retry==15){ Serial.println("Connection failed"); }
  else{ Serial.println("Connected to Server"); }

  //Send the GET requst
  String req = String("GET /data/2.5/weather?q=")+cityName+"&appid="+authorization+
      " HTTP/1.1\r\n"+ 
      "Host: api.openweathermap.org\r\n"+
      "Connection: close\r\n"+
      "\r\n";
  Serial.println(req);
  httpsClient.print(req);

  //Print reply from the server
  Serial.println("Response:");
  while(httpsClient.connected()){
    String line = httpsClient.readStringUntil('\r');
    Serial.print(line);
    if(line == "\r"){
      break;
    }
  }

  //Close the TCP connection
  httpsClient.stop();
  Serial.println();
  Serial.println("Connection closed");
    
}

void loop() {

}

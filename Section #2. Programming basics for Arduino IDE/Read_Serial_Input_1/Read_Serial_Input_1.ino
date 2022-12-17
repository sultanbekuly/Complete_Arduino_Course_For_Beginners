void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(200);
  //Serial.setTimeout(1);//message will be devided into parts.
  
}
void loop() {
  // put your main code here, to run repeatedly:
  String mystr = "";
  while (mystr==""){
    mystr = Serial.readString();
    
  }
  Serial.println(mystr);
  
}

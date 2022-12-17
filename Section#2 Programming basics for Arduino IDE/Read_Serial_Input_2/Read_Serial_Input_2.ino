void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(200);
  //Serial.setTimeout(1);//message will be devided into parts.
  pinMode(13, OUTPUT);
  Serial.println("Hello. Please enter H or L to control the led");
  Serial.print(">");
  Serial.print("test");
  Serial.println("<");
}
void loop() {
  // put your main code here, to run repeatedly:
  String mystr = "";
  while (mystr==""){
    mystr = Serial.readString(); 
  }
  mystr.trim();
  
  Serial.print(">");
  Serial.print(mystr);
  Serial.println("<");
  
  if(mystr == "H"){
    digitalWrite(13, HIGH);
  }else if(mystr == "L"){
    digitalWrite(13, LOW);
  }else{
    Serial.println("Error input. Please enter H or L to control the LED");
  }
  
}

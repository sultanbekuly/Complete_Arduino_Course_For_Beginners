void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  fullColor('g');
}
void loop() {
  // put your main code here, to run repeatedly:
}
/*
ReturnType functionName (parameterType parameterName, ...){
  Function body
  Optionally returnValue
}
*/

void fullColor(char color){
  if(color == 'r'){
    Serial.println("red");
  }else if(color == 'g'){
    Serial.println("green");
  }else if(color == 'b'){
    Serial.println("blue");
  }
  
  if(color == 'g'){
    fullColor('b');
  }
}

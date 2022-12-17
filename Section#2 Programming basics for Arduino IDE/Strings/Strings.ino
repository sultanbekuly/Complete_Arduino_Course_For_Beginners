void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char c_string[8] = "Arduino";
  int c_length = strlen(c_string);
  Serial.println(c_length);
  //strcpy(destination, source);
  //copy string source to destination.
  char c_string2[8];
  strcpy(c_string2, c_string);
  Serial.println(c_string2);

  //strcat(destination, source);
  //append source string to the end of the destination string
  char c_string3[8] = "z";
  strcat(c_string3, c_string);
  Serial.println(c_string3);

  //if(strcmp(str, "Arduino") == 0)
  // do something if the variable str is equal to "Arduino"
  if(strcmp(c_string, "Arduino13") == 0){
    Serial.println("They are equal");
  }else{
    Serial.println("They are NOT equal");
  }
  String cppstring = "Arduino";
  Serial.println(cppstring);

  //message.length()
  //provides the number of characters in the string

  Serial.println(cppstring.length());

  //message.concat(anotherMessage)
  //appends the contents of anotherMessage to the message
  cppstring.concat("UNO");
  Serial.println(cppstring);
  Serial.println(cppstring.length());
  //message.substring(2, 5);
  //returns a substring starting from 2 till 5
  //indexOf and lastIndexOf functions are used to find an instance of a 
    //particular character in a string
  Serial.println(cppstring.substring(2,5));
  Serial.println(cppstring.indexOf("i"));
  Serial.println(cppstring[4]);
  
  
}
void loop() {
  // put your main code here, to run repeatedly:
  
}

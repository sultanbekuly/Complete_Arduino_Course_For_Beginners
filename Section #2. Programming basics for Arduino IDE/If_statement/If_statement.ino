void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*
  if(condition){
    action / statements
  }
  */
  int x = 2;
  if(x>2){
    Serial.println("x greater than 2");
  }else if (x<2){
    Serial.println("x less than 2");
  }else{
    Serial.println("x is equal to 2");
  }

  /*
  == equals to
  != not equal to
  >  greater than
  <  less than
  >= greater than or equals to
  <= less than or equals to
  */
  Serial.println("2==3");
  if(2==3){
    Serial.println("True");
  }else{
    Serial.println("False");
  }

  Serial.println("2!=3");
  if(2!=3){
    Serial.println("True");
  }else{
    Serial.println("False");
  }

  Serial.println("2>3");
  if(2>3){
    Serial.println("True");
  }else{
    Serial.println("False");
  }

  Serial.println("2<3");
  if(2<3){
    Serial.println("True");
  }else{
    Serial.println("False");
  }
  
  Serial.println("2>=2");
  if(2>=2){
    Serial.println("True");
  }else{
    Serial.println("False");
  }

  Serial.println("4<=3");
  if(4<=3){
    Serial.println("True");
  }else{
    Serial.println("False");
  }
  
  /*
  && - AND
  || - OR
  !  - NOT
  */
  Serial.println("--Logical operators--");
  if(1==1 && 1==2){
    Serial.println("True");
  }else{
    Serial.println("False");
  }
  
  if(1==2 || 3==2){
    Serial.println("True");
  }else{
    Serial.println("False");
  }

  if(!(1==1)){
    Serial.println("True");
  }else{
    Serial.println("False");
  }

  if( (1==2 && 2==2) || (3==3 || 2<1)){
    Serial.println("True");
  }else{
    Serial.println("False");
  }
  


  

}

void loop() {
  // put your main code here, to run repeatedly:

}

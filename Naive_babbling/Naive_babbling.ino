//to do list: 
//1. solder a pig tail
//2. fix a connecting port
//3. fix broken tendon
//4. fix broken motor (cap on the top plate)

#include <stdio.h>
//Motor pins
const int pwm1 = 4 ;  //initializing pin 4 as pwm
const int in_1 = 30 ;
const int in_2 = 31 ;
const int pwm2 = 5 ;  
const int in_3 = 28 ;
const int in_4 = 29 ;
const int pwm3 = 6 ;  
const int in_5 = 32 ;
const int in_6 = 33 ;
const int pwm4 = 7 ;  
const int in_7 = 34 ;
const int in_8 = 35 ;
const int pwm5 = 8 ;  
const int in_9 = 36 ;
const int in_10 = 37 ;
const int pwm6 = 9 ;  
const int in_11 = 38 ;
const int in_12 = 39 ;

//Random arrays
int randomArray1;
int randomArray2;
int randomArray3;
int randomArray4;
int randomArray5;
int randomArray6;


//For providing logic to L298 IC to choose the direction of the DC motor 

void setup()
{
pinMode(pwm1,OUTPUT) ;   //set PWM pin as output
pinMode(in_1,OUTPUT) ;  //Logic pins set as output
pinMode(in_2,OUTPUT) ;
pinMode(pwm2,OUTPUT) ;   
pinMode(in_3,OUTPUT) ; 
pinMode(in_4,OUTPUT) ;
pinMode(pwm3,OUTPUT) ;   
pinMode(in_5,OUTPUT) ;  
pinMode(in_6,OUTPUT) ;
pinMode(pwm4,OUTPUT) ;   
pinMode(in_7,OUTPUT) ; 
pinMode(in_8,OUTPUT) ;
pinMode(pwm5,OUTPUT) ;   
pinMode(in_9,OUTPUT) ;  
pinMode(in_10,OUTPUT) ;
pinMode(pwm6,OUTPUT) ;  
pinMode(in_11,OUTPUT) ;  
pinMode(in_12,OUTPUT) ;

randomSeed(analogRead(0));
}

void loop()
{
randomArray1=random(-2,2);
randomArray2=random(-2,2);
randomArray3=random(-2,2);
randomArray4=random(-2,2);
randomArray5=random(-2,2);
randomArray6=random(-2,2);

//For Clock wise motion , in_1 = High , in_2 = Low
analogWrite(pwm1,100) ;                                   //1
if(randomArray1 > 0){
  digitalWrite(in_1,HIGH) ;
  digitalWrite(in_2,LOW) ;
  //Clockwise for 0.5 secs
//  delay(500) ;    
}else if(randomArray1 < 0){
  //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
  digitalWrite(in_1,LOW) ;
  digitalWrite(in_2,HIGH) ;
//  delay(500) ;
}else{
  digitalWrite(in_1,HIGH) ;
  digitalWrite(in_2,HIGH) ;
//  delay(500) ;
}

analogWrite(pwm2,100) ;                                   //2
if(randomArray2 > 0){
  digitalWrite(in_3,HIGH) ;
  digitalWrite(in_4,LOW) ;

  //Clockwise for 0.5 secs
//  delay(500) ;    
}else if(randomArray2 < 0){
  //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
  digitalWrite(in_3,LOW) ;
  digitalWrite(in_4,HIGH) ;
//  delay(500) ;
}else{
  digitalWrite(in_3,HIGH) ;
  digitalWrite(in_4,HIGH) ;
//  delay(500) ;
}

analogWrite(pwm3,100) ;                                     //3
if(randomArray3 > 0){
  digitalWrite(in_5,HIGH) ;
  digitalWrite(in_6,LOW) ;

  //Clockwise for 0.5 secs
  delay(500) ;    
}else if(randomArray3 < 0){
  //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
  digitalWrite(in_5,LOW) ;
  digitalWrite(in_6,HIGH) ;
  delay(500) ;
}else{
  digitalWrite(in_5,HIGH) ;
  digitalWrite(in_6,HIGH) ;
  delay(500) ;
}

analogWrite(pwm4,100) ;                                     //4
if(randomArray4 > 0){
  digitalWrite(in_7,HIGH) ;
  digitalWrite(in_8,LOW) ;

  //Clockwise for 0.5 secs
  delay(500) ;    
}else if(randomArray4 < 0){
  //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
  digitalWrite(in_7,LOW) ;
  digitalWrite(in_8,HIGH) ;
  delay(500) ;
}else{
  digitalWrite(in_7,HIGH) ;
  digitalWrite(in_8,HIGH) ;
  delay(500) ;
}

analogWrite(pwm5,100) ;                                     //3
if(randomArray5 > 0){
  digitalWrite(in_9,HIGH) ;
  digitalWrite(in_10,LOW) ;

  //Clockwise for 0.5 secs
  delay(500) ;    
}else if(randomArray5 < 0){
  //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
  digitalWrite(in_9,LOW) ;
  digitalWrite(in_10,HIGH) ;
  delay(500) ;
}else{
  digitalWrite(in_9,HIGH) ;
  digitalWrite(in_10,HIGH) ;
  delay(500) ;
}

analogWrite(pwm6,100) ;                                     //3
if(randomArray6 > 0){
  digitalWrite(in_11,HIGH) ;
  digitalWrite(in_12,LOW) ;

  //Clockwise for 0.5 secs
  delay(500) ;    
}else if(randomArray6 < 0){
  //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
  digitalWrite(in_11,LOW) ;
  digitalWrite(in_12,HIGH) ;
  delay(500) ;
}else{
  digitalWrite(in_11,HIGH) ;
  digitalWrite(in_12,HIGH) ;
  delay(500) ;
}
}
   


#include <stdio.h>
#include <Encoder.h>


//Motor pins
const int motor_1 = 4 ;  //initializing pin 4 as pwm
const int in_1 = 30 ;
const int in_2 = 31 ;
const int motor_2 = 6 ;  
const int in_3 = 32;
const int in_4 = 33 ;
const int motor_3 = 5 ;  
const int in_5 = 28;
const int in_6 = 29;


const int motor_4 = 8 ;  //9
const int in_7 = 38;
const int in_8 = 39;
const int motor_5 = 9 ;  
const int in_9 = 36 ;
const int in_10 = 37 ;
const int motor_6 = 7 ;  
const int in_11 = 34 ;
const int in_12 = 35 ;

//Random arrays
int randomArray1;
int randomArray2;
int randomArray3;
int randomArray4;
int randomArray5;
int randomArray6;

int direction1;
int direction2;
int direction3;
int direction4;
int direction5;
int direction6;



//PWM_Values
float pwmVal_1;
float pwmVal_2;
float pwmVal_3;
float pwmVal_4;
float pwmVal_5;
float pwmVal_6;

//Encoders 
Encoder left_hip_encoder(42,43);
Encoder right_hip_encoder(40,41);
Encoder left_knee_encoder(44,45);
Encoder right_knee_encoder(48,49);


long lhe = -999;
long rhe = -999;
long lke = -999;
long rke = -999;


//For providing logic to L298 IC to choose the direction of the DC motor 

void setup()
{
pinMode(motor_1,OUTPUT) ;   //set PWM pin as output
pinMode(in_1,OUTPUT) ;  //Logic pins set as output
pinMode(in_2,OUTPUT) ;
pinMode(motor_2,OUTPUT) ;   
pinMode(in_3,OUTPUT) ; 
pinMode(in_4,OUTPUT) ;
pinMode(motor_3,OUTPUT) ;   
pinMode(in_5,OUTPUT) ;  
pinMode(in_6,OUTPUT) ;
pinMode(motor_4,OUTPUT) ;   
pinMode(in_7,OUTPUT) ; 
pinMode(in_8,OUTPUT) ;
pinMode(motor_5,OUTPUT) ;   
pinMode(in_9,OUTPUT) ;  
pinMode(in_10,OUTPUT) ;
pinMode(motor_6,OUTPUT) ;  
pinMode(in_11,OUTPUT) ;  
pinMode(in_12,OUTPUT) ;

randomSeed(analogRead(0));
Serial.begin(9600);
}

void loop()
{

long new_lhe, new_rhe, new_lke, new_rke;


randomArray1=random(100);
randomArray2=random(100);
randomArray3=random(100);
randomArray4=random(100);
randomArray5=random(100);
randomArray6=random(100);

//Generating PWM values
pwmVal_1=(randomArray1*255)/100;
pwmVal_2=(randomArray2*255)/100;
pwmVal_3=(randomArray3*255)/100;
pwmVal_4=(randomArray4*255)/100;
pwmVal_5=(randomArray5*255)/100;
pwmVal_6=(randomArray6*255)/100;

analogWrite(motor_1,pwmVal_1);  //Motor 1
  digitalWrite(in_1,HIGH) ;
  digitalWrite(in_2,LOW) ;
  Serial.print(randomArray1);
  Serial.print(",");
  //Serial.print("0");
  //delay(500) ; 


analogWrite(motor_2,pwmVal_2); //Motor 2
  digitalWrite(in_3,HIGH) ;
  digitalWrite(in_4,LOW) ;
  Serial.print(randomArray2);
  Serial.print(",");
  //Serial.print("0");
  //delay(500) ; 


analogWrite(motor_3,pwmVal_3); //Motor 3
  digitalWrite(in_5,HIGH) ;
  digitalWrite(in_6,LOW) ;
  Serial.print(randomArray3);
  Serial.print(",");
  //Serial.print("0");
  //delay(500) ; 


analogWrite(motor_4,pwmVal_4); //Motor 4
  digitalWrite(in_7,HIGH) ;
  digitalWrite(in_8,LOW) ;
  Serial.print(randomArray4);
  Serial.print(",");
  //Serial.print("0");
  //delay(500) ; 


analogWrite(motor_5,pwmVal_5); //Motor 5
  digitalWrite(in_9,HIGH) ;
  digitalWrite(in_10,LOW) ;
  Serial.print(randomArray5);
  Serial.print(",");
  //Serial.print("0");
  //delay(500) ; 

analogWrite(motor_6,pwmVal_6); //Motor 6
  digitalWrite(in_11,HIGH) ;
  digitalWrite(in_12,LOW) ;
  Serial.print(randomArray6);
  Serial.print(",");
  

delay(500) ;
new_lhe = left_hip_encoder.read();
new_rhe = right_hip_encoder.read();
new_lke = left_knee_encoder.read();
new_rke = right_knee_encoder.read();


if (new_lhe != lhe || new_rhe != rhe || new_lke !=lke || new_rke !=rke) {
    lhe = new_lhe;
    rhe = new_rhe;
    lke = new_lke;
    rke = new_rke;
  }

//Serial.print("Left = ");
Serial.print(new_lhe);
Serial.print(",");

//Serial.print(", Right = ");
Serial.print(new_rhe);
Serial.print(",");
//Serial.print(", Left knee= ");
Serial.print(new_lke);
Serial.print(",");
//Serial.print(", Right knee= ");
Serial.print(new_rke);

Serial.println();

}
   

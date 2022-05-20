/*
  360RotaryEncoder

  Read a rotary encoder with interrupts
  Encoder&Switch hooked up with common to +5V
  Read the press action with digitalread

  ENCODER_A_PIN to pin 2
  ENCODER_A_PIN to pin 3
  SWITCH_PIN to pin 4  
*/

//#include <PinChangeInterrupt.h>
#include <stdio.h>

#define ENCODER_A_PIN4 48
#define ENCODER_B_PIN4 49
#define ENCODER_A_PIN6 52
#define ENCODER_B_PIN6 53


volatile long position_4 = 0;
volatile long position_6 = 0;

long protectedCount_4 = 0;
long previousCount_4 = 0;
long protectedCount_6 = 0;
long previousCount_6 = 0;

const float convRatio = 1; //degrees

//Motor Right Swing
float PWM_[36] = {17.36, 34.20,  50.00,  64.27,  76.60,  86.60,  93.96,  98.48,  100, 98.48,  93.96,  86.60,  76.60,  64.27,  50.00,  34.20,  17.36,  1.22,  -17.36, -34.20, -50.00, -64.27, -76.60, -86.60, -93.96, -98.48, -100, -98.48, -93.96, -86.60, -76.60, -64.278, -50.00, -34.20, -17.36, -2.44};
int enB=3;  // PWM pin
int in1=22;
int in2=24;
//float pwmValA=(PWM_*255)/100;

volatile int flag = 0 ;

int values[100];
float pivalues[100];

//Motor Right Knee
//int PWM = 50;
//int enB=3;  // PWM pin
//int in1=22;
//int in2=24;
//float pwmValA=(PWM*255)/100;

void setup(){

  pinMode(ENCODER_A_PIN4, INPUT);
  pinMode(ENCODER_B_PIN4, INPUT);
  pinMode(ENCODER_A_PIN6, INPUT);
  pinMode(ENCODER_B_PIN6, INPUT);

  attachInterrupt(digitalPinToInterrupt(ENCODER_A_PIN4), read_quadrature4A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B_PIN4), read_quadrature4B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A_PIN6), read_quadrature6A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B_PIN6), read_quadrature6B, CHANGE);

  pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  //setup our serial 
  Serial.begin(9600);
}

void loop(){

  noInterrupts();
  protectedCount_4 = position_4;
  protectedCount_6 = position_6;
  interrupts();
   
  //if(protectedCount_4 != previousCount_4) {    Serial.print("Position4: ");    Serial.println(protectedCount_4);  }
  //if(protectedCount_4 != previousCount_4) 
  {    Serial.print(protectedCount_4); Serial.print("\t");    Serial.println( protectedCount_6 );} // Serial.print(" "); Serial.println(protectedCount_6); }
  //if(protectedCount_6 != previousCount_6) {    Serial.print("Position6: ");    Serial.println(protectedCount_6);  }
  //if(protectedCount_6 != previousCount_6) 
  //{    Serial.print(" ");    Serial.println(protectedCount_6);  }

for (int i=0; i<=36; i++)
{
  analogWrite (enB, PWM_[i]+100);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
}

  previousCount_4 = protectedCount_4;
  previousCount_6 = protectedCount_6;
  
}


void read_quadrature4A(){  
  if (digitalRead(ENCODER_A_PIN4) == LOW){   
    if (digitalRead(ENCODER_B_PIN4) == LOW){
      position_4++;
    }
    else{
      position_4--;
    }
  }
  else{
    if (digitalRead(ENCODER_B_PIN4) == LOW){
      position_4--;
    }
    else{
      position_4++;
    }
  }
}

void read_quadrature4B(){  
  if (digitalRead(ENCODER_B_PIN4) == LOW){   
    if (digitalRead(ENCODER_A_PIN4) == HIGH){
      position_4++;
    }
    else{
      position_4--;
    }
  }
  else{
    if (digitalRead(ENCODER_A_PIN4) == HIGH){
      position_4--;
    }
    else{
      position_4++;
    }
  }
}



void read_quadrature6A(){  
  if (digitalRead(ENCODER_A_PIN6) == LOW){   
    if (digitalRead(ENCODER_B_PIN6) == LOW){
      position_6++;
    }
    else{
      position_6--;
    }
  }
  else{
    if (digitalRead(ENCODER_B_PIN6) == LOW){
      position_6--;
    }
    else{
      position_6++;
    }
  }
}

void read_quadrature6B(){  
  if (digitalRead(ENCODER_B_PIN6) == LOW){   
    if (digitalRead(ENCODER_A_PIN6) == HIGH){
      position_6++;
    }
    else{
      position_6--;
    }
  }
  else{
    if (digitalRead(ENCODER_A_PIN6) == HIGH){
      position_6--;
    }
    else{
      position_6++;
    }
  }
}

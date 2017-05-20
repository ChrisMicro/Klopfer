/*
  BPM Klopfer

  Klopfer Percusive Controller

  May 2017, ChrisMicro

*/

#include "klopfer_pin_definitions.h"

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(TRIG1, INPUT_ANALOG);
  pinMode(TRIG2, INPUT_ANALOG);
  pinMode(TRIG3, INPUT_ANALOG);
  pinMode(TRIG4, INPUT_ANALOG);

  pinMode(POTI1, INPUT_ANALOG);
  pinMode(POTI2, INPUT_ANALOG);
  pinMode(POTI3, INPUT_ANALOG);
  pinMode(POTI4, INPUT_ANALOG);
  pinMode(POTI5, INPUT_ANALOG);
  pinMode(POTI6, INPUT_ANALOG);

  pinMode(PWM_MOTOR1, PWM);
  pinMode(PWM_MOTOR2, PWM);
  pinMode(PWM_MOTOR3, PWM);
  pinMode(PWM_MOTOR4, PWM);

}

uint8_t MotorList[] = {PWM_MOTOR1, PWM_MOTOR2, PWM_MOTOR2, PWM_MOTOR2};

// motorNumber: 1..4
// force -1000..1000
void motorSet(int motorNumber, int force)
{
  motorNumber--;
  if (force == 0)
  {
    //pinMode(MotorList[motorNumber], INPUT); // input turns motor off
    analogWrite(MotorList[motorNumber], 65536 / 2);
  }
  else
  {
    //pinMode(MotorList[motorNumber], PWM);
    analogWrite(MotorList[motorNumber], map(force, -1000, 1000, 0, 65535) );
  }
}

void loop()
{
  int hit_force1;
  int hit_force2;
  int back_force;
  int bpm;

  hit_force1 = map(analogRead( POTI1 ), 0, 4095, 1, 200); // map analog range 0..4094 to values 20..1000
  hit_force2 = map(analogRead( POTI2 ), 0, 4095, 1, 200);
  back_force = map(analogRead( POTI3 ), 0, 4095, 1, 200);
  bpm        = map(analogRead( POTI4 ), 0, 4095, 500, 3000);

  digitalWrite(LED1, 1); // led on
  motorSet(1, 1000); // full speed forward
  delay(hit_force1);
  digitalWrite(LED1, 0); // led off

  digitalWrite(LED2, 1); // led on
  motorSet(1, -1000); // full speed forward
  delay(hit_force2);
  digitalWrite(LED2, 0); // led off

  digitalWrite(LED3, 1); // led on
  motorSet(1, 0); // full speed forward
  delay(bpm);
  digitalWrite(LED3, 0); // led off
  
  
}



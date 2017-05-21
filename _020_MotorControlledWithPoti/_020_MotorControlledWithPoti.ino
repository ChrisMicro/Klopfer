/*
  BPM Klopfer

  Klopfer Percusive Controller

  May 2017, ChrisMicro, Elektrouwe, Cecille

*/

#include "klopfer_pin_definitions.h"

#define POT_BACKFORCE1 POTI1
#define POT_BPM   POTI2
#define POT_HITFORCE1  POTI3
#define POT_HITFORCE2  POTI4
#define POT_PATTERN1  POTI5
#define POT_PATTERN2  POTI6

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


// Motor Force Potentiometers
  pinMode(POT_BACKFORCE1, INPUT_ANALOG);   
  pinMode(POT_HITFORCE1, INPUT_ANALOG);
  pinMode(POT_HITFORCE2, INPUT_ANALOG);
  
  pinMode(POT_BPM, INPUT_ANALOG);
  
// Rythm PATTERN selection left & right motor
  pinMode(POT_PATTERN1, INPUT_ANALOG);
  pinMode(POT_PATTERN2, INPUT_ANALOG);

  pinMode(PWM_MOTOR1, PWM);
  pinMode(PWM_MOTOR2, PWM);
  pinMode(PWM_MOTOR3, PWM);
  pinMode(PWM_MOTOR4, PWM);

}



// motorNumber: 1..4
// force -1000..1000
void motorSet(int motorPwmPin, int force)
{
  if (force == 0)
  {
    analogWrite(motorPwmPin, 65536 / 2);
  }
  else
  {
    analogWrite(motorPwmPin, map(force, -1000, 1000, 0, 65535) );
  }
}

#define HITTIME_MS 100

void loop()
{
  int hit_force1;
  int hit_force2;
  int back_force;
  int bpm;

  hit_force1 = map(analogRead( POT_HITFORCE1 ), 0, 4095, 100, 1000);
  hit_force2 = map(analogRead( POT_HITFORCE2 ), 0, 4095, 100, 1000);
  back_force = map(analogRead( POT_BACKFORCE1 ), 0, 4095, 100, -1000);
  
  
  bpm        = map(analogRead( POT_BPM ), 0, 4095, 40, 240); // beats per minute ( slow walz till gabber )

  digitalWrite(LED4,1); // toggle led

  motorSet(PWM_MOTOR1, hit_force1); // apply hit force
  motorSet(PWM_MOTOR2, hit_force2); // apply hit force
  delay(HITTIME_MS);

  motorSet(PWM_MOTOR1, back_force ); // back
  motorSet(PWM_MOTOR2, back_force ); // back

  delay(HITTIME_MS);
  digitalWrite(LED4,0); // toggle led

  int    delay_bpm_ms = (1000*60) / bpm - 2* HITTIME_MS;
  delay( delay_bpm_ms );
 
}



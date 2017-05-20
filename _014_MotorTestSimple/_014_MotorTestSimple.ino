/*
 dimple Motor test

 turn motors forwared and backward
 
 Klopfer Percusive Controller

  May 2017, ElektroUwe,ChrisMicro
*/

#define PWM_MOTOR1  PB6
#define PWM_MOTOR2  PB7
#define PWM_MOTOR3  PB8
#define PWM_MOTOR4  PB9

void setup() 
{
  pinMode(PWM_MOTOR1, PWM);
  pinMode(PWM_MOTOR2, PWM);
  pinMode(PWM_MOTOR3, PWM);
  pinMode(PWM_MOTOR4, PWM);
}

void loop() 
{
    analogWrite(PWM_MOTOR1,65000);
    analogWrite(PWM_MOTOR2,65000);
    analogWrite(PWM_MOTOR3,65000);
    analogWrite(PWM_MOTOR4,65000);
    delay(500);
    analogWrite(PWM_MOTOR1,0);
    analogWrite(PWM_MOTOR2,0);
    analogWrite(PWM_MOTOR3,0);
    analogWrite(PWM_MOTOR4,0);
    delay(500);
}

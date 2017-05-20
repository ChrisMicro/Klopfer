/*
  hardware test for the

  Klopfer Percusive Controller

  May 2017, ChrisMicro
*/


#include "klopfer_pin_definitions.h"

#define POTI_BACKWARD_MOTOR1   PA5
#define POTI_VORWARD_MOTOR1    PA6
#define POTI_CYCLETIME_MOTOR1  PA7
#define VOLTAGE_MOTOR1         PA17


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
}


void loop()
{
    digitalWrite(LED1, !digitalRead(LED1)); // toggle led
    delay(100);

}

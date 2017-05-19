#define POTI_BACKWARD_MOTOR1   A0
#define POTI_VORWARD_MOTOR1    A1
#define POTI_CYCLETIME_MOTOR1  A2
#define VOLTAGE_MOTOR1         13

void setup()
{
  pinMode(POTI_CYCLETIME_MOTOR1, INPUT);
  pinMode(VOLTAGE_MOTOR1, OUTPUT);
}

unsigned long Time_ms  = 0;
int           Timer1_ms = 0;

void loop()
{
  int timerLimit = analogRead(POTI_CYCLETIME_MOTOR1);

  int zero_voltage_motor1 = 128;
  int vorward_voltage_motor1 = 200;
  int backward_voltage_motor1 = 20;

  if ( Timer1_ms >= timerLimit )
  {

    analogWrite(VOLTAGE_MOTOR1, vorward_voltage_motor1);
    delay(10);
    analogWrite(VOLTAGE_MOTOR1, backward_voltage_motor1);
    Timer1_ms = 0;
  }

  while (Time_ms == millis()); // wait for next millisecond
  Time_ms = millis();

  Timer1_ms++;


}

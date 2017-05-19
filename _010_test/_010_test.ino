//#define BLUEPILL


#ifdef BLUEPILL

#define POTI_BACKWARD_MOTOR1   PA5
#define POTI_VORWARD_MOTOR1    PA6
#define POTI_CYCLETIME_MOTOR1  PA7
#define VOLTAGE_MOTOR1         PA17

#define LED0 PB6
#define LED1 PB7
#define LED2 PB8
#define LED3 PB9

#else

#define POTI_BACKWARD_MOTOR1   A0
#define POTI_VORWARD_MOTOR1    A1
#define POTI_CYCLETIME_MOTOR1  A2
#define VOLTAGE_MOTOR1         12

#define LED0 3
#define LED1 4
#define LED2 5
#define LED3 6

#endif

void setup()
{
#ifdef BLUEPILL
  pinMode(POTI_CYCLETIME_MOTOR1, INPUT_ANALOG);
  pinMode(VOLTAGE_MOTOR1, PWM);
#else
  pinMode(POTI_CYCLETIME_MOTOR1, INPUT);
  pinMode(VOLTAGE_MOTOR1, OUTPUT);
#endif

  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED0, 1);
  digitalWrite(LED1, 1);
  digitalWrite(LED2, 1);
  digitalWrite(LED2, 1);

}

unsigned long Time_ms  = 0;
int           Timer1_ms = 0;

void loop()
{
  int timerLimit = analogRead(POTI_CYCLETIME_MOTOR1);

  int zero_voltage_motor1     = 128;
  int vorward_voltage_motor1  = 200;
  int backward_voltage_motor1 = 20;

  if ( Timer1_ms >= timerLimit )
  {
    digitalWrite(LED0,1);
    analogWrite(VOLTAGE_MOTOR1, vorward_voltage_motor1);
    delay(10);
    digitalWrite(LED0,0);
    analogWrite(VOLTAGE_MOTOR1, backward_voltage_motor1);
    Timer1_ms = 0;
  }

  while (Time_ms == millis()); // wait for next millisecond
  Time_ms = millis();

  Timer1_ms++;


}

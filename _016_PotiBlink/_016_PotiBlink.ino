/*
  read potientiometer and influence the blink time
  of a LED

  The blink time is implemented with the help of software timers.

  Klopfer Percusive Controller

  May 2017, ChrisMicro

*/

#define POTI1 PA4
#define POTI2 PA5
#define POTI3 PA6
#define POTI4 PA7
#define POTI5 PB0
#define POTI6 PB1

#define LED1 PB12
#define LED2 PB13
#define LED3 PB11
#define LED4 PB10

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(POTI1, INPUT_ANALOG);
  pinMode(POTI2, INPUT_ANALOG);
  pinMode(POTI3, INPUT_ANALOG);
  pinMode(POTI4, INPUT_ANALOG);

}

unsigned long Time_ms  = 0;

int Timer1_ms = 0;
int Timer2_ms = 0;
int Timer3_ms = 0;
int Timer4_ms = 0;

void loop()
{
  int v1;
  int v2;
  int v3;
  int v4;

  v1 = map(analogRead( POTI1 ), 0, 4095, 20, 1000); // map analog range 0..4094 to values 20..1000
  v2 = map(analogRead( POTI2 ), 0, 4095, 20, 1000);
  v3 = map(analogRead( POTI3 ), 0, 4095, 20, 1000);
  v4 = map(analogRead( POTI4 ), 0, 4095, 20, 1000);

  if (Timer1_ms > v1)
  {

    digitalWrite(LED1, !digitalRead(LED1)); // toggle led

    // reset timer
    Timer1_ms = 0;
  }

  if (Timer2_ms > v2)
  {

    digitalWrite(LED2, !digitalRead(LED2)); // toggle led

    // reset timer
    Timer2_ms = 0;
  }

  if (Timer3_ms > v3)
  {

    digitalWrite(LED3, !digitalRead(LED3)); // toggle led

    // reset timer
    Timer3_ms = 0;
  }

  if (Timer4_ms > v4)
  {

    digitalWrite(LED4, !digitalRead(LED4)); // toggle led

    // reset timer
    Timer4_ms = 0;
  }


  while (Time_ms == millis()); // wait for next millisecond
  Time_ms = millis();

  Timer1_ms++;
  Timer2_ms++;
  Timer3_ms++;
  Timer4_ms++;

}

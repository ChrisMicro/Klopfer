/*
  read potientiometer and influence the blink time
  of a LED

  turn motors forwared and backward

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


  pinMode(POTI1, INPUT_ANALOG);

}

void loop()
{
  int v1;

  v1 = map(analogRead( POTI1 ), 0, 4095, 20, 1000); // map analog range 0..4094 to values 20..1000
  
  digitalWrite(LED1, 0);
  delay( v1  );
  digitalWrite(LED1, 1);

  delay(100);

}

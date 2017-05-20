/*
  read the VC-inputs and turn on led if value > TRIGGERLEVEL

  The blink time is implemented with the help of software timers.

  Klopfer Percusive Controller

  May 2017, ChrisMicro

*/

#define TRIGGERLEVEL 200

#define TRIG1 PA0
#define TRIG2 PA1
#define TRIG3 PA2
#define TRIG4 PA3

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

  pinMode(TRIG1, INPUT_ANALOG);
  pinMode(TRIG2, INPUT_ANALOG);
  pinMode(TRIG3, INPUT_ANALOG);
  pinMode(TRIG4, INPUT_ANALOG);
}

void loop() 
{
  int v1;
  int v2;
  int v3;
  int v4;

  v1 = map(analogRead( TRIG1 ), 0, 4095, 0, 1000); // map analog range 0..4094 to values 20..1000
  v2 = map(analogRead( TRIG2 ), 0, 4095, 0, 1000);
  v3 = map(analogRead( TRIG3 ), 0, 4095, 0, 1000);
  v4 = map(analogRead( TRIG4 ), 0, 4095, 0, 1000);

  if( v1 > TRIGGERLEVEL ) digitalWrite(LED1,0);
  else digitalWrite(LED1,1);
  
  if( v2 >TRIGGERLEVEL ) digitalWrite(LED2,0);
  else digitalWrite(LED2,1);
  
  if( v3 > TRIGGERLEVEL ) digitalWrite(LED3,0);
  else digitalWrite(LED3,1);
  
  if( v4 > TRIGGERLEVEL ) digitalWrite(LED4,0);
  else digitalWrite(LED4,1);

}

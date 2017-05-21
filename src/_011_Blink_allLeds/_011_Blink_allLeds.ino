/*
 blink all LEDs 
 Klopfer Percusive Controller

  May 2017, ChrisMicro
*/

#define LED1 PB12
#define LED2 PB13
#define LED3 PB11
#define LED4 PB10

#define NUMLEDS 4
const uint8_t Led[] = {LED1, LED2, LED3, LED4};

void setup()
{
  for (int n = 0; n < NUMLEDS; n++)  pinMode(Led[n], OUTPUT);
}

void setLed(uint8_t n, uint8_t state)
{
  if(n==4)digitalWrite(Led[n], !state);
  else digitalWrite(Led[n], state);
}

void loop()
{
  for (int n = 0; n < NUMLEDS; n++)
  {
    setLed(n, HIGH);
    delay(100);
    setLed(n, LOW);
    delay(100);
  }
}

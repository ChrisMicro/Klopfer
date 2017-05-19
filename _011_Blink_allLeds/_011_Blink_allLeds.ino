// blink all LEDs 
// Klopfer Percusive Controller

#define LED0 PB6
#define LED1 PB7
#define LED2 PB8
#define LED3 PB9

#define NUMLEDS 4
const uint8_t Led[] = {LED0, LED1, LED2, LED3};

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

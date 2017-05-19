#define POTI_BACKWARD_MOTOR1   A0
#define POTI_VORWARD_MOTOR1    A1
#define POTI_CYCLETIME_MOTOR1  A2

#define SER Serial

void setup() 
{
  pinMode(POTI_CYCLETIME_MOTOR1, INPUT_ANALOG);

  SER.begin(9600);
  delay(4000);
  
}

void loop() 
{
  SER.println(analogRead(POTI_CYCLETIME_MOTOR1);
  delay(100);

}

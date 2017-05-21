// serial print all ADCs
// Klopfer Percusive Controller

#define BLUEPILL

#ifdef BLUEPILL
  #define POTI_CYCLETIME_MOTOR1  PB1
  #define POTI_CYCLETIME_MOTOR2  PB0

  #define POTI_VORWARD_MOTOR2    PA7
  #define POTI_VORWARD_MOTOR1    PA6

  #define POTI_BACKWARD_MOTOR1   PA5
  #define POTI_BACKWARD_MOTOR2   PA4
#else
  #define POTI_CYCLETIME_MOTOR1  A0
  #define POTI_CYCLETIME_MOTOR2  A1
  
  #define POTI_VORWARD_MOTOR2    A2
  #define POTI_VORWARD_MOTOR1    A3
  
  #define POTI_BACKWARD_MOTOR1   A4
  #define POTI_BACKWARD_MOTOR2   A5
#endif


#define SER Serial

void setup()
{
  #ifdef BLUEPILL
    pinMode(POTI_CYCLETIME_MOTOR1, INPUT_ANALOG);
    pinMode(POTI_CYCLETIME_MOTOR2, INPUT_ANALOG);

    pinMode(POTI_VORWARD_MOTOR2, INPUT_ANALOG);
    pinMode(POTI_VORWARD_MOTOR1, INPUT_ANALOG);

    pinMode(POTI_BACKWARD_MOTOR1, INPUT_ANALOG);
    pinMode(POTI_BACKWARD_MOTOR2, INPUT_ANALOG);
  #endif

  SER.begin(9600);
  for (int n = 0; n < 5; n++)
  {
    SER.print(".");
    delay(1000);
  }
  SER.println("");

}

void loop()
{
  SER.print("POTI_CYCLETIME_MOTOR1\t");
  SER.print(analogRead(POTI_CYCLETIME_MOTOR1));

  SER.print("\tPOTI_CYCLETIME_MOTOR2\t");
  SER.print(analogRead(POTI_CYCLETIME_MOTOR2));

  SER.print("\tPOTI_VORWARD_MOTOR2\t");
  SER.println(analogRead(POTI_VORWARD_MOTOR2));

  SER.print("POTI_VORWARD_MOTOR1\t");
  SER.print(analogRead(POTI_VORWARD_MOTOR1));

  SER.print("\tPOTI_BACKWARD_MOTOR1\t");
  SER.print(analogRead(POTI_VORWARD_MOTOR2));

  SER.print("\tPOTI_BACKWARD_MOTOR2\t");
  SER.println(analogRead(POTI_VORWARD_MOTOR1));

  delay(1000);

}

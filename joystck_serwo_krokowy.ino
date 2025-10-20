#include <Servo.h>
#define XPIN A0
#define YPIN A1
#define P1 10
#define P2 11
#define P3 12
#define P4 13

Servo servo_9;

float pozycja;
float valueX;

void setup() 
{
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);

  pinMode (XPIN, INPUT);
  pinMode (YPIN, INPUT);
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  pinMode(P4, OUTPUT);
}

void loop() 
{
  /* Serial.print ("X: ");
  Serial.print (analogRead(XPIN));
  Serial.print("\tpozycja: ");
  Serial.println (pozycja);*/
  if (analogRead(YPIN) > 530)
  {
    przod(2);

    valueX = analogRead(XPIN);
    pozycja = (valueX/1023)*180;
    servo_9.write(pozycja);
  }

  else if (analogRead(YPIN) < 510)
  {
    wsteczny(2);

    valueX = analogRead(XPIN);
    pozycja = (valueX/1023)*180;
    servo_9.write(pozycja);
  }

  else
  {
    valueX = analogRead(XPIN);
    pozycja = (valueX/1023)*180;
    servo_9.write(pozycja);
  }
}

void przod (int dly)
{
  digitalWrite (P1, HIGH);
  delay (dly);
  digitalWrite (P1, LOW);
  digitalWrite (P2, HIGH);
  delay (dly);
  digitalWrite (P2, LOW);
  digitalWrite (P3, HIGH);
  delay (dly);
  digitalWrite (P3, LOW);
  digitalWrite (P4, HIGH);
  delay (dly);
  digitalWrite (P4, LOW);
}

void wsteczny (int dly)
{
  digitalWrite (P4, HIGH);
  delay (dly);
  digitalWrite (P4, LOW);
  digitalWrite (P3, HIGH);
  delay (dly);
  digitalWrite (P3, LOW);
  digitalWrite (P2, HIGH);
  delay (dly);
  digitalWrite (P2, LOW);
  digitalWrite (P1, HIGH);
  delay (dly);
  digitalWrite (P1, LOW);
}
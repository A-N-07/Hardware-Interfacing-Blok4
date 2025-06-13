// includeert de servo library
#include <Servo.h>

Servo myServo;

// initialiseert de pin nummers voor de led en de servo
const int lButPin = 10;
const int rButPin = 6;
const int servoPin = 9;

// dit is voor de button states en hier word gebruikt gemaakt voor edge detectie
bool lBut = false, lButLast = false;
bool rBut = false, rButLast = false;
bool hold = false;

unsigned long startTime = 0;

// setup voor de buttons als input en initialiseert de servo
void setup() 
{
  pinMode(lButPin, INPUT);
  pinMode(rButPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0); // start de servo bij de nul waarde
}

// twee knoppen drie functionaliteiten
// linker knop zorgt voor het draaien van positie 0 naar 120 in vijf sevonden en weer terug
// rechter knop zorgt voor het draain van positie 0 naar 120 in een halve seconde en weer terug
// Het indrukken van beide knoppen zorgt voor het draaien van positie 0 naar 120 in 5 seconden, wacht 2 seconden en gaat weer terug in een halve seconde. 
void loop() 
{
  lBut = digitalRead(lButPin);
  rBut = digitalRead(rButPin);

  delay(200);
  // beide knoppen 
  if (lBut == HIGH && rBut == HIGH && lButLast == LOW && rButLast == LOW)
  {
    if (!hold)
    {
      startTime = millis();
      hold = true;
    }
    if ( millis() - startTime >= 2000)
    {
      servoDo(0, 120, 5000);
      delay(2000);
      servoDo(120, 0 , 500);
      hold = false;
    }
    return;
  }
  else
  {
    hold = false;
  }

  // knop 1
  if (lBut == HIGH && lButLast == LOW)
  {
    servoDo(0, 120, 5000);
    servoDo(120, 0, 5000);
  }

  //knop 2
  if (rBut == HIGH && rButLast == LOW)
  {
    servoDo(0, 120, 500);
    servoDo(120, 0, 500);
  }

  lButLast = lBut;
  rButLast = rBut;

  delay(200);
}

// functionaliteit voor het bewegen van de servo. 
// je kan de start positie invoern, eind positie en hoeveel milliseconde dat moet duren
// deze functie is dus bruikbaar voor alle mogelijke bewegingen van de servo 
void servoDo(int startPos, int endPos, int duration) {
  int steps = abs(endPos - startPos);
  int delayTime = duration / steps;

  // kijkt of de beweging van start naar eind een positieve beweging is of een negatieve beweging en pakt de goede for loop zodat de beweging goed wordt uitgevoert
  // ook checkt het elke iteratie of er wel een knop is ingedrukt zodat het alleen werkt wanneer je het indrukt
  if (startPos < endPos) 
  {
    for (int i = startPos; i <= endPos; i++) 
    {
      if (digitalRead(lButPin) == HIGH || digitalRead(rButPin) == HIGH)
      {
        myServo.write(i);
        delay(delayTime);
      }
      else
      {
        break;
      }
    }
  } 
  else 
  {
    for (int i = startPos; i >= endPos; i--) 
    {
      if (digitalRead(lButPin) == HIGH || digitalRead(rButPin) == HIGH)
      {
        myServo.write(i);
        delay(delayTime);
      }
      else
      {
        break;
      }
    }
  }
}

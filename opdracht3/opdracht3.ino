// initialiseert alle pin nummers, en benodigde variabelen voor het gebruik van buttons
int butPin = 12;
int rLPin = 10;
int gLPin = 8;
int butCount = 0;
int lastBut = LOW;
int curBut = LOW

// setup voor de knop als input en de led pinnetje als output
void setup() 
{
  pinMode(butPin, INPUT);
  pinMode(rLPin, OUTPUT);
  pinMode(gLPin, OUTPUT);
}

// kijkt of er op de knop is gedrukt en zorgt dat wanneer je op de knop drukt het andere ledje aan gaat.
void loop() 
{ 
  // logica voor het goed lezen van een druk op de knop en het tellen van het aantal keer dat op een knop is gedrukt
  int curBut = digitalRead(butPin);
  Serial.println(butCount);

  if (curBut == HIGH && lastBut == LOW) 
  {
    delay(50);
    if (digitalRead(butPin) == HIGH) 
    {
      butCount++;
    }

  }

  lastBut = curBut;

  // logica voor het aanzetten van het ene lampje en het uitzetten van het ander gebaseerd op hoeveel keer op de knop er is gedrukt en of dat deelbaar is door 2 of niet.
  if (butCount % 2 != 0)
  {
    digitalWrite(gLPin, LOW);
    delay(50);  
    digitalWrite(rLPin, HIGH); 
  } 
  else
  {
    digitalWrite(rLPin, LOW);
    delay(50);
    digitalWrite(gLPin, HIGH);  
  }
}

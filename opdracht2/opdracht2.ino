// initialiseer hoeveelheid led lampjes + alle pin nummers in een array
const int ledAmount = 6;
int ledPins[ledAmount] = {12, 10, 8, 6, 4, 2};


// initialiseert alle pin nummers als output
void setup() 
{
  for (int i = 0; i < ledAmount; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() 
{
  knightRider(100);
}

// Laat de lampjes branden van links naar rechts en dan van rechts naar links net zoals de auto in KnightRider
void knightRider(int ms)
{ 
  leftToRight(ms);
  rightToLeft(ms);
}

// zet eerst alle lampjes uit en dan de eerste 1e aan en vervolgens doet het weer hetzelfde maar brand het volgende lampje en gaat zo alle lampjes af
void leftToRight(int ms)
{
  for(int i = 0; i < ledAmount; i++)
  {
    for(int j = 0; j < ledAmount; j++)
    {
      digitalWrite(ledPins[j], LOW);
    }
    digitalWrite(ledPins[i], HIGH);
    delay(ms);
  }
}

// Doet precies hetzelfde wat leftToRight doet maar dan in de tegengestelde richting
void rightToLeft(int ms)
{
  for(int i = ledAmount - 1; i >= 0; i--)
  {
    for(int j = 0; j < ledAmount; j++)
    {
      digitalWrite(ledPins[j], LOW);
    }
    digitalWrite(ledPins[i], HIGH);
    delay(ms);
  }
}

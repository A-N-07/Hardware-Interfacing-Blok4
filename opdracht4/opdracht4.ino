// initialiseren van de hoeveelheid ledjes en de pin nummers in een array + benodigde waardes zoals led index en potwaarde
#define LED_NUM 6
int leds[LED_NUM] = {13, 11, 8, 5, 3, 2};
int pot = A0;
int lIndx = 0;
int potVal 0;

// setup van alle ledjes als input. De potmeter is automatisch aangesloten op A0
void setup() 
{
  Serial.begin(9600);
  for (int i = 0; i < LED_NUM; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

// Leest de potwaarde vertalt het naar een waarde tussen 0 en 6 en op die waardes is een lampje verbonden die dan aan moet gaan en de rest uit
void loop() 
{
  potVal = analogRead(pot);
  Serial.println(potVal);

  // vertaalt potwaarde naar een iteratie nummer waarde
  lIndx = map(potValue, 0, 1023, 0, LED_NUM);
  if (lIndx >= LED_NUM) 
  {
    lIndx = LED_NUM - 1; // -1 ter correctie
  }

  // Zet een lampje als de ledIndex gelijk is aan het iteratie nummer
  for (int i = 0; i < LED_NUM; i++) 
  {
    digitalWrite(leds[i], i == lIndx ? HIGH : LOW);
  }
}

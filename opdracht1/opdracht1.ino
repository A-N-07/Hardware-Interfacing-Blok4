 // initialiseer pin nummers
 int g  = 13;
 int r = 10;

// setup de pins als output en zet de baudraute op 9600 bits per seconde 
void setup() 
{
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);
  Serial.begin(9600);
}

// Laat de Leds knipperen, wanneer de ene led aan staat, staat de andere uit
void loop()
{
  digitalWrite(g, HIGH);
  digitalWrite(r, LOW);
  delay(1000);
  digitalWrite(g, LOW);
  digitalWrite(r, HIGH);
  delay(1000);
}

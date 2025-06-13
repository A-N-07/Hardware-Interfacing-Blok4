// includeert de files uit de library die nodig zijn
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// initialiseert het ldc object
LiquidCrystal_I2C lcd(0x27, 16, 2);

// initialiseert de button pins 
const int but1 = 12; 
const int but2 = 8;  

// benodigde variabelen voor de staat en de tijden van de stopwatch
bool running = false;
bool paused = false;
unsigned long startTime = 0;
unsigned long lapTime = 0;
unsigned long pausedTime = 0;
int lapCount = 0;

bool b1 = false, b1Last = false, b1New = false;
bool b2 = false, b2Last = false, b2New = false;

// setup de buttons als input en zet de baudrate op 9600 bit per seconde
// initialiseert de stopwatch
void setup() 
{
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch Gereed");
}

// checkt welke buttons ingedrukt zijn en voert daarna de functie van die button uit 
void loop() 
{
  b1 = digitalRead(but1);
  b2 = digitalRead(but2);

  b1New = (b1 == HIGH && b1Last == LOW);
  b2New = (b2 == HIGH && b2Last == LOW);

  if (b1New && b2New) 
  {
    reset();
    return;
  } 
  if (b1New)
  { 
    button1();
  }
  if (b2New)
  {
    button2();
  }

  updateDisplay();

  b1Last = b1;
  b2Last = b2;

  delay(200);
}

// handelt de eerte button
void button1() 
{
  if (!running) // start de stopwatch
  {
    startTime = millis();
    running = true;
    paused = false;
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("start");
  } 
  else // weergeeft een lap nummer + tijd
  {
    lapTime = millis() - startTime;
    lapCount++;
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("Lap ");
    lcd.print(lapCount);
    lcd.print(": ");
    lcd.print(lapTime / 1000.0, 2);
  }
}

// handelt de tweede button
void button2() 
{
  if (!running) //voor wanneer de stopwatch niet is gestart en de tweede knop is ingedrukt 
  {
    return;
  }

  paused = !paused; //pauzeert de stopwatch als tweede knop niet is ingedrukt en wel als dat al wel eens is gebeurt
  if (paused) 
  {
    pausedTime = millis();
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("Gepauzeerd");
  } 
  else 
  {
    startTime += millis() - pausedTime;
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("Lap ");
    lcd.print(lapCount);
    lcd.print(": ");
    lcd.print(lapTime / 1000.0, 2);
  }
}

// reset de stopwatch 
void reset() 
{
  running = false;
  paused = false;
  startTime = 0;
  lapTime = 0;
  lapCount = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reset Stopwatch");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch Gereed");
}


// laat de telling van de stopwatch zien
void updateDisplay() 
{
  if (running && !paused) 
  {
    unsigned long time = millis() - startTime;
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.print(time / 1000.0, 2);
  }
}

# Arduino Project – Opdrachten 1 t/m 6

Dit project bevat zes Arduino-opdrachten die zijn uitgevoerd als oefening in elektronica en programmeren met de Arduino. Elke opdracht bouwt voort op de vorige en introduceert nieuwe componenten en logica.

---

## ✅ Opdracht 1 – Wisselend knipperende LED’s

- Twee LED’s aangesloten op pin 10 en 13.
- De LED’s knipperen om en om, telkens 1.5 seconden aan/uit.
- Stappen:
  - Sketch geschreven.
  - Gesimuleerd en getest in Tinkercad.
  - Vervolgens op de fysieke Arduino opgebouwd en getest.

---

## ✅ Opdracht 2 – Lopend licht met 8 LED’s

- Acht LED’s aangesloten op externe poorten.
- De LED’s lopen heen en weer zoals in deze video: [ArduinoOpdracht3](http://bit.ly/ArduinoOpdracht3).
- Stappen:
  - Sketch geschreven.
  - Gesimuleerd in Tinkercad.
  - Opgebouwd op een breadboard en getest.

---

## ✅ Opdracht 3 – LED-besturing met drukknop

- Twee LED’s aangesloten op pin 8 en 10.
- Een drukknop aangesloten op pin 12.
- Functionaliteit:
  - Eerste LED schakelt aan/uit bij elke druk op de knop.
  - Tweede LED reageert tegenovergesteld aan de eerste.

---

## ✅ Opdracht 4 – LED-besturing via potmeter

- Zes LED’s worden aangestuurd afhankelijk van de stand van een potentiometer.
- Ingangen en uitgangen zijn zelf gekozen.
- Sketch is eerst in Tinkercad getest en daarna op de Arduino opgebouwd.

---

## ✅ Opdracht 5 – Servomotor aangestuurd met 2 drukknoppen

- Twee drukknoppen aangesloten op de Arduino.
- Functionaliteit:
  - Drukknop 1: Servo draait in 5s van 0° naar 120° en weer terug.
  - Drukknop 2: Servo draait in 0.5s van 0° naar 120° en weer terug.
  - Beide knoppen tegelijk:
    - Servo draait in 5s naar 120°, blijft 2s staan, keert in 0.5s terug naar 0°.
- De servo-aansturing is in één functie/methode verwerkt.
- Ingangen en uitgangen zijn vrij gekozen.

---

## ✅ Opdracht 6 – Stopwatch met I2C LCD en 2 knoppen

- Stopwatch gesimuleerd op een I2C LCD scherm.
- Twee knoppen zorgen voor de bediening:
  - Korte druk op knop 1: start de stopwatch.
  - Lange druk op knop 1 (2s): registreert een lap time.
  - Korte druk op knop 2: pauzeert de stopwatch.
  - Beide knoppen tegelijk: reset stopwatch en lap time.
- LCD is aangesloten via de SDA en SCL poorten.
- Vooraf is onderzoek gedaan naar het gebruik van I2C LCD in Tinkercad en het Arduino-kitje.

---

## 💡 Opmerkingen

- Alle opdrachten zijn eerst getest in Tinkercad en daarna fysiek opgebouwd met een Arduino Uno.
- De code is geschreven in de Arduino IDE en is gestructureerd per opdracht.
- Dit project was een leerzame introductie in digitale output, input, PWM, analoge input en I2C-communicatie.


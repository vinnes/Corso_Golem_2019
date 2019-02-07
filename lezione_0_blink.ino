/*
  esercizio per la Lezione 0 del corso Arduino 2019 del GOLEM

  Accendere e spegnere un LED con pause che vanno da 1 a 5 secondi e poi tornare decrescendo  fino a 1 secondo

  by Vincenzo Nesta
  07/02/2019

*/

//inizializzazione costanti e variabili
const byte Led = LED_BUILTIN;
int pausa = 1000; // 1 second
int incremento;
int decremento;

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Led, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
  digitalWrite(Led, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);             // wait for a second
  digitalWrite(Led, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);             // wait for a second
}
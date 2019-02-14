/*
  esercizio per la Lezione 0 del corso Arduino 2019 del GOLEM

  Accendere e spegnere un LED con pause che vanno da 1 a 5 secondi e poi tornare decrescendo fino a 1 secondo

  by Vincenzo Nesta
  14/02/2019

*/

//inizializzazione costanti e variabili
const byte pinLed = LED_BUILTIN;
int pausa = 1000; // 1 secondo
boolean ciclo = 1; // ciclo uguale 1 incremento della pausa, ciclo = 0 decremento della pausa
int inc_dec = 0; // incremento/decremento - variabile da 0s a 4s
int max_inc_dec = 5000; // incremento/decremento massimo (+/- 5s)
int min_inc_dec = 1000; // incremento/decremento minimo (+/- 1s)

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pinLed, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
  if (ciclo = 1) { // inizio ciclo con incremento
  digitalWrite(pinLed, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(pausa + inc_dec);             // wait for "pausa + inc_dec"
  digitalWrite(pinLed, LOW);  // turn the LED off by making the voltage LOW
  delay(pausa + inc_dec);             // wait for "pausa" - variabile da 1000 a 5000
  inc_dec = inc_dec + 1000; // incremento di 1s
  pausa = pausa + inc_dec; // incremento intervallo
  if (pausa > max_inc_dec) {  // fine ciclo con incremento
    ciclo = !ciclo; // inverto il ciclo
    }
  }
  else { // ciclo = 0 ?!?
    // inizio ciclo decremento
    inc_dec = 0; // azzero l'inc/dec
    pausa = max_inc_dec; // setto la pausa al massimo NON VA BENE!?!
    digitalWrite(pinLed, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(pausa + inc_dec);             // wait for "pausa" - variabile da 1000 a 5000
    digitalWrite(pinLed, LOW);  // turn the LED off by making the voltage LOW
    delay(pausa + inc_dec);             // wait for "pausa" - variabile da 1000 a 5000
    inc_dec = inc_dec - 1000; // decremento di 1s
    pausa = pausa + inc_dec;
    if (pausa < min_inc_dec) {
      pausa = 1000; // ho raggiunto 1 s, riporto la pausa a 1 s
      ciclo = !ciclo; // ed inverto il ciclo
      inc_dec = 0;  // azzero l'inc/dec
      }
    } // fine ciclo con decremento
  }

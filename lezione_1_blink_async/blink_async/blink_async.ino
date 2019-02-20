/*
  Blink async, rosso  ogni 500 ms, verde ogni 700 ms

 esercitazione lezione 1 corso Arduino 2019 Golem
  
*/
// led rosso
boolean stato_rosso = LOW;
const byte pinLedRosso = 11;
int contatore_rosso = 0;

// led verde
boolean stato_verde = LOW;
const byte pinLedVerde = 12;
int contatore_verde = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(pinLedRosso, OUTPUT);           // initialize digital pin led rosso as an output.
  digitalWrite(pinLedRosso, stato_rosso); // initialize led LOW.
  pinMode(pinLedVerde, OUTPUT);           // initialize digital pin led verde as an output.
  digitalWrite(pinLedVerde, stato_verde); // initialize led LOW.

  pinMode(pinLedBlu, OUTPUT);
  pinMode(pinBtn, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  // agisce sul led rosso
  if (contatore_rosso == 500) {
    stato_rosso = !stato_rosso;            // inverte lo stato del led
    digitalWrite(pinLedRosso, stato_rosso);
    contatore_rosso = 0;                  // azzera il contatore
  }
  contatore_rosso++;                      // incrementa contatore (al di fuori del ciclo if)

  // agisce sul led verde
  if (contatore_verde == 700) {
    stato_verde = !stato_verde;             // inverte lo stato del led
    digitalWrite(pinLedVerde, stato_verde);
    contatore_verde = 0;                    // azzera il contatore
  }
  contatore_verde++;

  delay(1);                                 // pausa fatta ad ogni ciclo, alrimenti non funziona
  
}

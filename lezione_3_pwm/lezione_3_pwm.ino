/*
  LED dimming with PWM (Pulse Width Modulation

 esercitazione lezione 3 corso Arduino 2019 Golem

  Vincenzo Nesta
*/

const byte PWMpin = 11;

void setup() {
  pinMode(PWMpin, OUTPUT);
  }
  
void loop() {// Accensione
  for (byte dim = 0; dim < 255; dim++) {
      analogWrite(PWMpin, dim);
      delay(10);
      }
    // Spegnimento
    for (byte dim = 255; dim > 0; dim--) {
      analogWrite(PWMpin, dim);
      delay(10);
      }
  }

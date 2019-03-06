/*
  Display alfanumerico 2x16
  
 esercitazione lezione 4 corso Arduino 2019 Golem

  Vincenzo Nesta
*/

// utilizza la libreria LiquidCristal
#include <LiquidCrystal.h>

// pin display:   RS  E   D4 D5 D6 D7
LiquidCrystal lcd(12, 11 , 5, 4, 3, 2);

void setup() {
  // imposta colonne e righe del diplay
  lcd.begin(16, 2);
  // stampa un messaggio
  lcd.print("Lezione 4 GOLEM");

}

void loop() {
  // sposta il cursore alla colonna 0, linea 1
  lcd.setCursor(0, 1);
  //stampa una stringa
  lcd.print("Display time: ");
  // sposta il cursore alla colonna 14, linea 1
  lcd.setCursor(14, 1);
  //stampa il numero di secondo dall'accensione
  lcd.print(millis()/1000);
    
  delay(1000);
}

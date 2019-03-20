/*
  Termostato intelligente col sensore DHT11
  
 esercitazione finale corso Arduino 2019 Golem

  Vincenzo Nesta
*/


#include <LiquidCrystal.h>  // libreria LiquidCristal display 2x16
#include <DHT.h>            // libreria DHT sensore temperatura e umidità
#define DHTTYPE DHT11       // modello di sensore

const byte DHTPIN = 8;      // pin a cui è connesso il sensore
DHT dht(DHTPIN, DHTTYPE);

// pin display:   RS  E   D4 D5 D6 D7
LiquidCrystal lcd(12, 11 , 5, 4, 3, 2);

// bottoni e led
boolean statoBtn;
boolean statoBtn_old;
const byte pinLedVerde = 10;
const byte pinBtn = 7;

void setup() {
  // put your setup code here, to run once:

  // imposta colonne e righe del diplay
  lcd.begin(16, 2);
  // stampa un messaggio
  lcd.print("Termostato");
  // sposta il cursore alla colonna 2, linea 1
  lcd.setCursor(2, 1);
  lcd.print("Intelligente");
  
  Serial.begin(9600); // inizializzo seriale

  dht.begin();        // accendo sensore
  delay(5000);        // pausa per messa a regime

  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinBtn, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  float umidita = dht.readHumidity();
  float temperatura = dht.readTemperature();
  // validazione valori
  if (isnan(umidita) || isnan(temperatura)) {
    Serial.println("Lettura fallita!");
    return;         // interrompe il loop
  }
  // stampo i dati sulla seriale
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");
  Serial.print(" - U.R.: ");
  Serial.print(umidita);
  Serial.print("%");
  Serial.print("\n");
  // stampo i dati sul display
  // sposta il cursore alla colonna 0, linea 1
  lcd.setCursor(0, 0);
  lcd.print("Temper.: ");
  lcd.print(temperatura);
  lcd.print((char)223);
  lcd.print("C");
  // sposta il cursore alla colonna 0, linea 1
  lcd.setCursor(0, 1);
  lcd.print("Umidita: ");
  lcd.print(umidita);
  lcd.print(" %");
  
  statoBtn = digitalRead(pinBtn);
  if (statoBtn == HIGH) {
    digitalWrite(pinLedVerde, LOW);
  }
  else {
    digitalWrite(pinLedVerde, HIGH);
  }
  // pausa
  delay(50);
  }

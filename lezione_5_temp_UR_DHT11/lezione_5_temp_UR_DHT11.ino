/*
  Temperatura e umidità col sensore DHT11
  
 esercitazione lezione 5 corso Arduino 2019 Golem

  Vincenzo Nesta
*/

#include <DHT.h>
// modello di sensore
#define DHTTYPE DHT11
// pin a cui è connesso il sensore
const byte DHTPIN = 2;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); // inizializzo seriale

  dht.begin();        // accendo sensore
  delay(2000);        // pausa per messa a regime
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
  // stampo i dati
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");
  Serial.print(" - U.R.: ");
  Serial.print(umidita);
  Serial.print("%");
  Serial.print("\n");
  // pausa
  delay(1000);
  }

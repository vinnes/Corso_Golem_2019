/*
  leggo il valore di illuminazione tramite una fotoresistenza
  e lo stampo sulla seriale

 esercitazione 3 lezione 1 corso Arduino 2019 Golem
  
*/

const byte pinFoto = A0;
const float resistFissa = 10.0;    // 10 kOhm
int valoreSensore;
float resistenzaSensore;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinFoto, INPUT);
  Serial.begin(9600);             // avvia la comunicazione seriale

}

void loop() {
  // put your main code here, to run repeatedly:
  // legge il valore del sensore dall'ingresso analogico
  valoreSensore = analogRead(pinFoto);
  Serial.print("Valore illuminazione = ");
  Serial.println(valoreSensore);

  resistenzaSensore = resistFissa/(1024.0/valoreSensore - 1);
  //Serial.print("Valore resistenza in kOhm = ");
  //Serial.println(resistenzaSensore);

  delay(50);                   // ritardo per leggere i valori sulla seriale
  
}

/*
  premo un pulsante e accendo il led

 esercitazione 2 lezione 1 corso Arduino 2019 Golem
  
*/

boolean statoBtn;
boolean statoBtn_old;
const byte pinLedBlu = 10;
const byte pinBtn = 7;


void setup() {
  // put your setup code here, to run once:

  pinMode(pinLedBlu, OUTPUT);
  pinMode(pinBtn, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  statoBtn = digitalRead(pinBtn);
  if (statoBtn == HIGH) {
    digitalWrite(pinLedBlu, HIGH);
  }
  else {
    digitalWrite(pinLedBlu, LOW);
  }
  delay(10);
}

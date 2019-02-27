/*
  Motore servo

 esercitazione lezione 3 corso Arduino 2019 Golem

  Vincenzo Nesta
*/

#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (byte p=0; p<180; p++) {
    myservo.write(p);
    delay(10);
  }
  delay(1000);
  for (byte p=180; p>0; p--) {
    myservo.write(p);
    delay(10);
  }
  delay(1000);
}

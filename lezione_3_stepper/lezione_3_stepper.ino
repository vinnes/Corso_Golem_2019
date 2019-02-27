/*
  Motore stepper

 esercitazione lezione 3 corso Arduino 2019 Golem

  Vincenzo Nesta
*/

#include <UnipolarStepper.h>
const int STEPS = 4096;  //passi per giro
const byte VEL_MIN = 1;  // rpm
const byte VEL_MAX = 20; // rpm
UnipolarStepper stepper(STEPS, 8, 9, 10, 11);

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(VEL_MIN);
  stepper.step(1000); // 1000 passi avanti
  stepper.step(-1000); // 1000 passi indietro
}

void loop() {
  // put your main code here, to run repeatedly:
  for (byte v=VEL_MIN; v<=VEL_MAX; v+=1) {
    stepper.setSpeed(v);  // cambia velocità
    stepper.step(500);    // 500 passi avanti
  }

}

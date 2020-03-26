#include <Servo.h>
Servo servo;

void setup() {
  serialSetup();  
  stateMachineSetup();
}

void loop() {
  stateMachineLoop();
}

const int SERVOPIN = 3;

void servoSetup() {
  servo.attach(SERVOPIN);
  servoWrite(0);
}

void servoWrite(int servoStand) {
  servo.write(servoStand);
}

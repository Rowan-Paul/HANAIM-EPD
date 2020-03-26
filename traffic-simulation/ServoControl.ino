const int SERVOPIN = 13;

void servoSetup() {
  servo.attach(SERVOPIN);
  servoWrite(0);
}

void servoWrite(int servoStand) {
  servo.write(servoStand);
}

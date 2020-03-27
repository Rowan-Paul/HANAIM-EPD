const int LDRPIN = A2;

void ldrSetup() {
  pinMode(LDRPIN, INPUT);
  int ldrValue = analogRead(LDRPIN);
}

int ldrGetValue() {
  return analogRead(LDRPIN);
}

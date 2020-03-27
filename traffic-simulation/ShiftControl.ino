const int LED_COUNT = 8;
const int PIN_ST_CP = 6;
const int PIN_SH_CP = 7;
const int PIN_DS = 4;

void shiftSetup() {
  pinMode(PIN_ST_CP, OUTPUT);
  pinMode(PIN_SH_CP, OUTPUT);
  pinMode(PIN_DS, OUTPUT);
}

void shiftSetPattern(byte pattern) {
  digitalWrite(PIN_ST_CP, LOW);
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(PIN_SH_CP, LOW);
    digitalWrite(PIN_DS, bitRead(pattern, i));
    digitalWrite(PIN_SH_CP, HIGH);
  }
  digitalWrite(PIN_ST_CP, HIGH);
  digitalWrite(PIN_ST_CP, LOW);
}

void shiftSetAllOn() {
  digitalWrite(PIN_ST_CP, LOW);
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(PIN_SH_CP, LOW);
    digitalWrite(PIN_DS, HIGH);
    digitalWrite(PIN_SH_CP, HIGH);
  }
  digitalWrite(PIN_ST_CP, HIGH);
  digitalWrite(PIN_ST_CP, LOW);
}

void shiftSetAllOff() {
  digitalWrite(PIN_ST_CP, LOW);
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(PIN_SH_CP, LOW);
    digitalWrite(PIN_DS, LOW);
    digitalWrite(PIN_SH_CP, HIGH);
  }
  digitalWrite(PIN_ST_CP, HIGH);
  digitalWrite(PIN_ST_CP, LOW);
}

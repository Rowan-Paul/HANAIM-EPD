const int LEDPINSIZE = 6;
const int LEDPINARRAY [LEDPINSIZE] = {8,9,10,11,12,13};

// Setup all LEDs
void ledControlSetup() {
  for (int ledNumber = 0; ledNumber < LEDPINSIZE; ledNumber++) {
    pinMode(LEDPINARRAY[ledNumber], OUTPUT);
  }
}

// Set a specific LED ON
void ledControlSetLedOn(int ledNumber) {
  digitalWrite(ledNumber, HIGH);
}

// Set a specific LED OFF
void ledControlSetLedOff(int ledNumber) {
  digitalWrite(ledNumber, LOW);
}

// Set ALL LEDs ON
void ledControlSetAllLedsOn() {
  for (int ledNumber = 0; ledNumber < LEDPINSIZE; ledNumber++) {
    digitalWrite(LEDPINARRAY[ledNumber], HIGH);
  }
}

// Set ALL LEDs OFF
void ledControlSetAllLedsOff() {
  for (int ledNumber = 0; ledNumber < LEDPINSIZE; ledNumber++) {
    digitalWrite(LEDPINARRAY[ledNumber], LOW);
  }
}

// Getter voor LEDPINSIZE
int ledGetCount() {
  return LEDPINSIZE;
}

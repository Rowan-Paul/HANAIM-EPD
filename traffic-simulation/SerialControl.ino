// Start the Serial reader
void serialSetup() {
  Serial.begin(9600);
}

// Is there a letter present? TRUE | FALSE
boolean serialAvailable() {
  return Serial.available() > 0;
}

// Empty the serial
void serialFlush() {
  while (serialAvailable()) {
    Serial.read();
  }
}

// Read the character and return it, if there is one
char serialRead() {
  if (serialAvailable()) {
    return Serial.read();
  } else {
    return 0;
  }
}

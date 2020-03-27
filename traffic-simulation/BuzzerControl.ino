const int BUZZER = 5;

// timers
unsigned long buzzerTimer;
const unsigned long SLOW_TIMER_INTERVAL = 1000;
const unsigned long FAST_TIMER_INTERVAL = 500;

void buzzerSetup() {
  pinMode(BUZZER, OUTPUT);
}

void buzzerSlowSound() {
  noTone(BUZZER);
  
  if (timerIsPassed(buzzerTimer, SLOW_TIMER_INTERVAL)) {
    buzzerTimer = timerReset();

    tone(BUZZER, 1000);
  }
}

void buzzerFastSound() {
  noTone(BUZZER);
  
  if (timerIsPassed(buzzerTimer, FAST_TIMER_INTERVAL)) {
    buzzerTimer = timerReset();

    tone(BUZZER, 1000);
  }
}

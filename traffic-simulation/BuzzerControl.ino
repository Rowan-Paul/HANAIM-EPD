const int buzzer = 2;

// timers
unsigned long buzzerTimer;
const unsigned long SLOW_TIMER_INTERVAL = 1000;
const unsigned long FAST_TIMER_INTERVAL = 500;

void buzzerSetup() {
  pinMode(buzzer, OUTPUT);
}

void buzzerSlowSound() {
  noTone(buzzer);
  
  if (timerIsPassed(buzzerTimer, SLOW_TIMER_INTERVAL)) {
    buzzerTimer = timerReset();

    tone(buzzer, 1000);
  }
}

void buzzerFastSound() {
  noTone(buzzer);
  
  if (timerIsPassed(buzzerTimer, FAST_TIMER_INTERVAL)) {
    buzzerTimer = timerReset();

    tone(buzzer, 1000);
  }
}

const int TRAFFIC_LIGHT1_DATA_PIN = A5;
const int TRAFFIC_LIGHT2_DATA_PIN = A4;
const int PEDESTRIAN_CROSSING_DATA_PIN = A3;

int currentStateTrafficLight1 = 3;
int currentStateTrafficLight2 = 3;
int currentStatePedestrianCrossing = 3;

// timers
unsigned long trafficTimer;
const unsigned long ORANGE_TIMER_INTERVAL = 5000;
const unsigned long RED_TIMER_INTERVAL = 2000;

void stateMachineSetup() {
  buttonSetup(TRAFFIC_LIGHT1_DATA_PIN);
  buttonSetup(TRAFFIC_LIGHT2_DATA_PIN);
  buttonSetup(PEDESTRIAN_CROSSING_DATA_PIN);
  ledControlSetup();
  buzzerSetup();
  servoSetup();
}

void stateMachineLoop() {
  // Pedestrian crossing
  switch (currentStatePedestrianCrossing) {
    case 1:
      servoWrite(180);
      buzzerFastSound();
      break;
    case 2:

      break;
    case 3:
      servoWrite(0);
      buzzerSlowSound();
  }

  if (buttonPressed(PEDESTRIAN_CROSSING_DATA_PIN)) {
    currentStatePedestrianCrossing = 1;
  }

  // Traffic Light 1
  switch (currentStateTrafficLight1) {
    case 1:
      setTrafficLightGreen("trafficLight1");

      // Wait 5 seconds and switch to orange
      if (timerIsPassed(trafficTimer, ORANGE_TIMER_INTERVAL)) {
        trafficTimer = timerReset();

        currentStateTrafficLight1 = 2;
      }
      break;
    case 2:
      setTrafficLightOrange("trafficLight1");

      // Wait 2 seconds and switch to orange
      if (timerIsPassed(trafficTimer, RED_TIMER_INTERVAL)) {
        currentStateTrafficLight1 = 3;
      }
      break;
    case 3:
      setTrafficLightRed("trafficLight1");

      // Check if button is pressed and all lights are red
      // then switch to green
      if (buttonPressed(TRAFFIC_LIGHT1_DATA_PIN) && checkTrafficLightsRed()) {
        trafficTimer = timerReset();

        currentStateTrafficLight1 = 1;
      }
      break;
  }

  // Traffic Light 2
  switch (currentStateTrafficLight2) {
    case 1:
      setTrafficLightGreen("trafficLight2");

      // Wait 5 seconds and switch to orange
      if (timerIsPassed(trafficTimer, ORANGE_TIMER_INTERVAL)) {
        trafficTimer = timerReset();

        currentStateTrafficLight2 = 2;
      }
      break;
    case 2:
      setTrafficLightOrange("trafficLight2");

      // Wait 2 seconds and switch to orange
      if (timerIsPassed(trafficTimer, RED_TIMER_INTERVAL)) {
        currentStateTrafficLight2 = 3;
      }
      break;
    case 3:
      setTrafficLightRed("trafficLight2");

      // Check if button is pressed and all lights are red
      // then switch to green
      if (buttonPressed(TRAFFIC_LIGHT2_DATA_PIN) && checkTrafficLightsRed()) {
        trafficTimer = timerReset();

        currentStateTrafficLight2 = 1;
      }
      break;
  }
}

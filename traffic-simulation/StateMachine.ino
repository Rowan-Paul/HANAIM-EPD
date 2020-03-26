const int TRAFFIC_LIGHT1_DATA_PIN = 4;
const int TRAFFIC_LIGHT2_DATA_PIN = 8;

int currentStateTrafficLight1 = 3;
int currentStateTrafficLight2 = 3;


// timers
unsigned long trafficTimer;
const unsigned long ORANGE_TIMER_INTERVAL = 5000;
const unsigned long RED_TIMER_INTERVAL = 2000;

void stateMachineSetup() {
  buttonSetup(TRAFFIC_LIGHT1_DATA_PIN);
  buttonSetup(TRAFFIC_LIGHT2_DATA_PIN);
  ledControlSetup();
}

void stateMachineLoop() {
  // Traffic Light 1
  switch (currentStateTrafficLight1) {
    case 1:
      setTrafficLightGreen("trafficLight1");

      // Wait 5 seconds and switch to orange
      if (timerIsPassed(trafficTimer, ORANGE_TIMER_INTERVAL)) {
        currentStateTrafficLight1 = 2;

        trafficTimer = timerReset();
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
        currentStateTrafficLight2 = 2;

        trafficTimer = timerReset();
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
        currentStateTrafficLight2 = 1;
      }
      break;
  }
}

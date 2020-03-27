const int GREEN_LIGHT1_PIN = 8;
const int ORANGE_LIGHT1_PIN = 9;
const int RED_LIGHT1_PIN = 10;

const int GREEN_LIGHT2_PIN = 11;
const int ORANGE_LIGHT2_PIN = 12;
const int RED_LIGHT2_PIN = 13;

boolean checkTrafficLightsRed() {
  if (currentStateTrafficLight1 == 3 && currentStateTrafficLight2 == 3
      && currentStatePedestrianCrossing == 3) {
    return true;
  } else {
    return false;
  }
}

void setTrafficLightGreen(String trafficLight) {
  // set light to green
  if (trafficLight == "trafficLight1") {
    ledControlSetLedOff(RED_LIGHT1_PIN);
    ledControlSetLedOff(ORANGE_LIGHT1_PIN);

    ledControlSetLedOn(GREEN_LIGHT1_PIN);
    currentStateTrafficLight1 = 1;
  } else if (trafficLight == "trafficLight2") {
    ledControlSetLedOff(RED_LIGHT2_PIN);
    ledControlSetLedOff(ORANGE_LIGHT2_PIN);

    ledControlSetLedOn(GREEN_LIGHT2_PIN);
    currentStateTrafficLight2 = 1;
  }
}

void setTrafficLightOrange(String trafficLight) {
  currentStatePedestrianCrossing = 3;
  if (trafficLight == "trafficLight1") {
    ledControlSetLedOff(RED_LIGHT1_PIN);
    ledControlSetLedOff(GREEN_LIGHT1_PIN);

    ledControlSetLedOn(ORANGE_LIGHT1_PIN);
    currentStateTrafficLight1 = 2;
  } else if (trafficLight == "trafficLight2") {
    ledControlSetLedOff(RED_LIGHT2_PIN);
    ledControlSetLedOff(GREEN_LIGHT2_PIN);

    ledControlSetLedOn(ORANGE_LIGHT2_PIN);
    currentStateTrafficLight2 = 2;
  }
}

void setTrafficLightRed(String trafficLight) {
  if (trafficLight == "trafficLight1") {
    ledControlSetLedOff(ORANGE_LIGHT1_PIN);
    ledControlSetLedOff(GREEN_LIGHT1_PIN);

    ledControlSetLedOn(RED_LIGHT1_PIN);
    currentStateTrafficLight1 = 3;
  } else if (trafficLight == "trafficLight2") {
    ledControlSetLedOff(ORANGE_LIGHT2_PIN);
    ledControlSetLedOff(GREEN_LIGHT2_PIN);

    ledControlSetLedOn(RED_LIGHT2_PIN);
    currentStateTrafficLight2 = 3;
  }
}

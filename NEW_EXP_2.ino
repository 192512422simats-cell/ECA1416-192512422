
/*
 EXPERIMENT 2:
 FORMAL DESIGN OF AN EMBEDDED CONTROLLER USING
 STATE MACHINE (STATECHART) MODELING
 TRAFFIC LIGHT CONTROLLER

 Board: Arduino UNO
 Simulation: Proteus

 Pin assignments:
 D2 = North-South Red
 D3 = North-South Yellow
 D4 = North-South Green
 D5 = East-West Red
 D6 = East-West Yellow
 D7 = East-West Green

 Virtual Terminal:
 Arduino TX (D1) -> RXD
 Baud rate: 9600
*/

const int NS_RED    = 2;
const int NS_YELLOW = 3;
const int NS_GREEN  = 4;

const int EW_RED    = 5;
const int EW_YELLOW = 6;
const int EW_GREEN  = 7;

// FSM states
enum TrafficState {
  S0,  // NS Green, EW Red
  S1,  // NS Yellow, EW Red
  S2,  // NS Red, EW Green
  S3   // NS Red, EW Yellow
};

TrafficState currentState = S0;

// Set all traffic light outputs LOW
void clearLights() {
  digitalWrite(NS_RED, LOW);
  digitalWrite(NS_YELLOW, LOW);
  digitalWrite(NS_GREEN, LOW);

  digitalWrite(EW_RED, LOW);
  digitalWrite(EW_YELLOW, LOW);
  digitalWrite(EW_GREEN, LOW);
}

// Apply outputs and print active state
void executeState(TrafficState state) {
  clearLights();

  switch (state) {
    case S0:
      digitalWrite(NS_GREEN, HIGH);
      digitalWrite(EW_RED, HIGH);
      Serial.println("STATE S0: NS GREEN - EW RED");
      break;

    case S1:
      digitalWrite(NS_YELLOW, HIGH);
      digitalWrite(EW_RED, HIGH);
      Serial.println("STATE S1: NS YELLOW - EW RED");
      break;

    case S2:
      digitalWrite(NS_RED, HIGH);
      digitalWrite(EW_GREEN, HIGH);
      Serial.println("STATE S2: NS RED - EW GREEN");
      break;

    case S3:
      digitalWrite(NS_RED, HIGH);
      digitalWrite(EW_YELLOW, HIGH);
      Serial.println("STATE S3: NS RED - EW YELLOW");
      break;
  }
}

// Return the duration of the active state
unsigned long stateDuration(TrafficState state) {
  switch (state) {
    case S0:
    case S2:
      return 10000UL;  // 10 seconds green

    case S1:
    case S3:
      return 3000UL;   // 3 seconds yellow
  }

  return 1000UL;
}

void setup() {
  pinMode(NS_RED, OUTPUT);
  pinMode(NS_YELLOW, OUTPUT);
  pinMode(NS_GREEN, OUTPUT);

  pinMode(EW_RED, OUTPUT);
  pinMode(EW_YELLOW, OUTPUT);
  pinMode(EW_GREEN, OUTPUT);

  Serial.begin(9600);

  currentState = S0;
}

void loop() {
  // Enter current FSM state and activate its outputs
  executeState(currentState);

  // Wait for the duration associated with the state
  delay(stateDuration(currentState));

  // State transition: S0 -> S1 -> S2 -> S3 -> S0
  switch (currentState) {
    case S0:
      currentState = S1;
      break;

    case S1:
      currentState = S2;
      break;

    case S2:
      currentState = S3;
      break;

    case S3:
      currentState = S0;
      break;
  }
}

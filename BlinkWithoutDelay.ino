const int LED = LED_BUILTIN;
int pinState;

// Beat {300->OFF, 200->ON};
int pattern[] = {300, 200, 300, 200, 300, 300, 150, 50, 150, 50, 150, 500, 200, 100, 200, 100, 200, 100, 200, 400, 200, 100, 200, 1000};
int PATTERN_SIZE = sizeof(pattern)/sizeof(pattern[1]);
int currentPatternPosition;
unsigned long storedTime;

void setup() {
  pinMode(LED, OUTPUT);
  pinState = HIGH;
  storedTime = 0;
  currentPatternPosition = 0;
  Serial.begin(9600);
}

void loop() {
  unsigned long timeSinceChange = getTimeSinceChange(storedTime);
  
  if(timeSinceChange >= pattern[currentPatternPosition]){
    pinState = changePinState(pinState);
    currentPatternPosition = changeCurrentPosition(PATTERN_SIZE, currentPatternPosition);
    storedTime = millis();
  }
  digitalWrite(LED, pinState);
}

unsigned long getTimeSinceChange(unsigned long prevTime){
  return millis() - prevTime;
}

int changePinState(int pinState){
  if(pinState == HIGH){
    return LOW;
  }
  return HIGH;
}

int changeCurrentPosition(int len, int currentPosition){
  if(currentPosition == len - 1){
    return 0;
  }
  return ++currentPosition;
}

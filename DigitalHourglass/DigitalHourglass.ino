// Tilt switch pin.
const int switchPin = 8;

// Create a variable to hold the time the LED was last changed.
unsigned long previousTime = 0;

// Create a variable to store the previous switch state. This will
// be used to compare the switch's position from one loop to the next.
int prevSwitchState = 0;

// Create a variable to count which LED is the next to turn on.
int nextLED = 2;

// Interval between each LED turning on. 10 min = 600,000 ms.
const long interval = 600000;

void setup() {
  // Set the LED pins modes to OUTPUT.
  for(int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }

  // Set the tilt switch pin mode to INPUT.
  pinMode(switchPin, INPUT);
}

void loop() {
  // Get the amount of time the Ardunio has been running.
  const unsigned long currentTime = millis();

  // Check if enough time has passed to turn on an LED.
  if(currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(nextLED, HIGH);
    nextLED++;
  }

  if(nextLED == 7) {
    // All lights are on, so all time has passed.
  }

  // If the switch state has changed, reset the hourglass.
  const int switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState) {
    resetLEDs();
    previousTime = currentTime;
  }

  // Set previousSwitchState to the current switchState so you can
  // compare it to the value you get for switchState in the next loop().
  prevSwitchState = switchState;
}

void resetLEDs() {
  // Turn off all the LEDs.
  for(int i = 2; i < 8; i++) {
    digitalWrite(i, LOW);
  }
  
  nextLED = 2;
}

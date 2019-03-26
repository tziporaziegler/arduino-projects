const int switchPin = 2;
const int motorPin = 9;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  const int switchState = digitalRead(switchPin);

  // If the switch is pressed (HIGH), acitvate the transitor (HIGH).
  // This will complete the motor circuit and turn the motor on.
  // When the switch is not pressed (LOW), and the transistor pin is
  // set to LOW, the motor will not spin. 
  digitalWrite(motorPin, switchState);
}

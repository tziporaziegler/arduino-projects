// Create constants for the output and input pins.
const int onOffSwitchStatePin = 5;
const int directionSwitchPin = 4;
const int motorEnablePin = 9;
const int potPin = A0;
const int controlPin1 = 2;
const int controlPin2 = 3;

int previousOnOffSwitchState = 0;
int previousDirectionSwitchState = 0;
bool motorEnabled = false; // Keeps track of whether the motor is spinning or not.
int motorDirection = 0; // Keeps track of which direction the motor is spinning.

void setup() {
  pinMode(onOffSwitchStatePin, INPUT);
  pinMode(directionSwitchPin, INPUT);
  pinMode(motorEnablePin, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);

  // Set the motor enabled pin to LOW so the motor isn't spinning right away.
  digitalWrite(motorEnablePin, LOW);
}

void loop() {
  // Use the first button to toggle the motor on/off state.
  const int onOffSwitchState = digitalRead(onOffSwitchStatePin);
  if(onOffSwitchState != previousOnOffSwitchState) {
    if(onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  delay(1);

  // Use the second button to toggle the motor spinning direction.
  const int directionSwitchState = digitalRead(directionSwitchPin);
  if(directionSwitchState != previousDirectionSwitchState) {
    if(directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  // To set the direction, set one control pin to HIGH and the other to LOW.
  // Reversing the control pins will reverse the motor spinning direction.
  if(motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);    
  }

  // If the motor is enabled, get the speed of the motor from the potentiometer.
  // Divide by 4 to convert the potentiometer range to the motor range.
  // If the motor is disabled, set the speed to 0.
  const int motorSpeed = motorEnabled ? analogRead(potPin) / 4 : 0;
  analogWrite(motorEnablePin, motorSpeed);

  // Save the current state of the switches to the previous state variables for the
  // next run through the program.
  previousOnOffSwitchState = onOffSwitchState;
  previousDirectionSwitchState = directionSwitchState;
}

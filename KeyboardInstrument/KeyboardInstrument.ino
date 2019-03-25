// This project demonstrates using a resistor ladder to create a musical keyboard.

int const piezoPin = 8;

// Frequencies for middle piano octave (Hz).
const long noteC4 = 261.6256;
const long noteD4 = 293.6648;
const long noteE4 = 329.6276;
const long noteF4 = 349.2282;
const long noteG4 = 391.9954;
const long noteA4 = 440.0000;
const long noteB4 = 493.8833;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  // Since each button is connected to a different resistor, use the input value
  // to determine which button was pressed and map the value to a musical note.
  // Use a range since the circuit can be a little "noisy" and the values may
  // fluctuate a bit while a button is being pressed.
  if(keyVal >= 5 && keyVal <= 15){
    tone(piezoPin, noteC4);
  }
  else if(keyVal >= 508 && keyVal <= 515){
    tone(piezoPin, noteD4);
  }
  else if(keyVal >= 692 && keyVal <= 697){
    tone(piezoPin, noteE4);
  }
  else if(keyVal >= 922 && keyVal <= 929){
    tone(piezoPin, noteF4);
  }
  else if(keyVal >= 963 && keyVal <= 970){
    tone(piezoPin, noteG4);
  }
  else if(keyVal >= 990 && keyVal <= 1003){
    tone(piezoPin, noteA4);
  }
  else if(keyVal >= 1011){
    tone(piezoPin, noteB4);
  }
  else {
    noTone(piezoPin);
  }
}

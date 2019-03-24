int const photoresistorSensorPin = A0;
int photoresistorSensorValue;

// The sensor's high and low values will be used to scale the frequency.
// Set the low to default to 1023 and the high to default to 0.
// When the program runs for the first time, these min and max values
// will adjust according to the sensor's readings.
int photoresistorSensorLow = 1023;
int photoresistorSensorHigh = 0;

// Use the on-board LED connected to pin 13.
const int ledPin = 13;

int const piezoPin = 8;

// Set the range of frequencies the Ardunio will output.
int const piezoFrequencyLow = 50;
int const piezoFrequencyHigh = 4000;

int const noteDuration  = 20; // Play the note for 20 milliseconds.

void setup() {
  // Use the LED to indicate the sensor's calibration state.
  pinMode(ledPin, OUTPUT);

  // Turn the LED on to indicate that the sensor is calibrating.
  digitalWrite(ledPin, HIGH);

  // Calibrate the sensor's maximum and minimum values for 5 seconds.
  // millis() reports how long the Ardunio has been running since it
  // was last powered on or reset.
  // During this duration, move your hand up and down over the
  // photoresitor to change the amount of light that reaches it.
  // The closer you replicate the motions you expect to use while
  // playing the instrument, the better the calibration will be.
  while(millis() < 5000) {
    photoresistorSensorValue = analogRead(photoresistorSensorPin);
    if(photoresistorSensorValue > photoresistorSensorHigh) {
      photoresistorSensorHigh = photoresistorSensorValue;
    }
    if(photoresistorSensorValue < photoresistorSensorLow) {
      photoresistorSensorLow = photoresistorSensorValue;
    }
  }

  // Turn the LED off to indicate that the sensor finished calibarating.
  digitalWrite(ledPin, LOW);
}

void loop() {
  photoresistorSensorValue = analogRead(photoresistorSensorPin);

  // Map the photoresitor sensor value to the piezo frequency value.
  int pitch = map(photoresistorSensorValue, photoresistorSensorLow,
    photoresistorSensorHigh, piezoFrequencyLow, piezoFrequencyHigh);

  // Call the tone() function to play a sound.
  // 3 args: pin to play sound on, frequency to play, how long to play note
  tone(piezoPin, pitch, noteDuration);

  // Call delay() for 10 milliseconds to give the sound some time to play.
  delay(10);
}

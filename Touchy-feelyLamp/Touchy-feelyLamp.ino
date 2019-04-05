#include <CapacitiveSensor.h>

// Capacitance = a measure of how much electrical charge something can store.
// The library checks two pins, 1 sender and 1 receiver, and measures the time
// it takes for them to have the same state. Pin 4 sends to the conductive
// sensor material through the resistor, and pin 2 is the sense pin.
const int senderPin = 4;
const int receiverPin = 2;
CapacitiveSensor capSensor = CapacitiveSensor(senderPin, receiverPin);

// Variable for sensing threshold at which the LED will turn on.
const int threshold = 450;

const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // If you read too few samples, you'll see a lot of variation in the sensor.
  // Too many samples could introduce a lag as it reads the sensor multiple times.
  // 30 samples is a good starting value.
  const int numberOfSamplesToRead = 30;
  const long sensorValue = capSensor.capacitiveSensor(numberOfSamplesToRead);

  Serial.println(sensorValue);

  // If the sensor value if above the threshold, turn the LED on.
  if(sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}

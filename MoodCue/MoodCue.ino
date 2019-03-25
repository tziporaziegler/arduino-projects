#include <Servo.h>

Servo myServo;

const int potentiometerPin = A0;
int potentiometerVal;
int angle;

void setup() {
  // Tell the Arduino what pin the servo is attached to.
  myServo.attach(9);

  // Include a serial connection to check the values from the potentiometer.
  Serial.begin(9600);
}

void loop() {
  potentiometerVal = analogRead(potentiometerPin);

  // Use the map() function to change the potentiometer analog 0-1023 value to the servo 0-179 degree value.
  // 5 args: numberToBeScaled, minValOfInput, maxValOfInput, minValOfOutput, maxValOfOutput
  angle = map(potentiometerVal, 0, 1023, 0, 179);

  // Print values to the serial monitor.
  Serial.print("potentiometerVal: ");
  Serial.print(potentiometerVal);
  Serial.print(", angle: ");
  Serial.println(angle);

  // Move the servo motor to the specified angle.
  myServo.write(angle);

  // Add a delay so the servo has time to move to its position.
  delay(15);
}

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

const int redLEDPin = 11;
const int greenLEDPin  = 9;
const int blueLEDPin = 10;

void setup() {
  // Begin serial communication at 9600 bps.
  Serial.begin(9600);

  // Define the LED pins as outputs.
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  // Read the sensor values.
  // Put a smally delay() between each analogRead() as the ADC takes a millisecond to do its work.
  float redSensorValue = analogRead(redSensorPin);
  delay(5);
  float greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  float blueSensorValue = analogRead(blueSensorPin);

  // Print the sensor values to the serial monitor.
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);

  // The analogRead() function, that reads the sensor values, can be a number between 0-1023.
  // The analogWrite() function, that changes the LED value via PWM, requires a value between
  // 0-255, which represents the duty cycle the Arduino will output on the specified pin.
  // To convert the sensor reading value from a value between 0-1023 to a value between 0-55,
  // divide the sensor reading by 4.
  float redValue = redSensorValue / 4;
  float greenValue = greenSensorValue / 4;
  float blueValue = blueSensorValue / 4;

  // Print the new mapped sensor values to the serial monitor.
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  // Set the LED light levels.
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}

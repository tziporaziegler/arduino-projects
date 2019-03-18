const int tempSensorPin = A0;

// Set the baseline temperature to 24 degrees celcius. This can be changed to whatever room
// temperature is detected.
const float baselineTemp = 24;

void setup() {
  // Open a serial port connection between the Arduino and the computer to read analog input
  // values from the temperature sensor.
  // 9600 is the speed at which the Arduino will communicate - 9,600 bits per second.
  Serial.begin(9600);

  // Set the three red LED pins to OUTPUT and turn the LEDs off.
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // anologRead() will return a value between 0 and 1023, representing the voltage of the pin.
  int tempSensorVal = analogRead(tempSensorPin);

  // Convert the ADC (Analog-to-Digital Converter) reading to voltage.
  // The pin voltage will be a value between 0 and 5 volts.
  float voltage = (tempSensorVal / 1024.0) * 5;

  // Every 10 millivolts of change from the sensor is equivalent to a temperature change of
  // 1 degree Celsius. The sensor can read temperatures below 0 degrees (freezing), so the
  // value needs to be offset.
  float temperature = (voltage - .5) * 100;
  
  // Print the information to the Ardunio IDE's serial monitor.
  Serial.print("Temperature Sensor Value: ");
  Serial.print(tempSensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", Degrees (C): ");
  Serial.println(temperature);
 
  // Turn on one LED for every 2 degrees of temperature increase above the baseline.
  float difTemp = temperature - baselineTemp;
  if (difTemp >= 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } else if (difTemp >= 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (difTemp >= 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  delay(1);
}

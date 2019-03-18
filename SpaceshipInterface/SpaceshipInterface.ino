int switchState = 0;

void setup() {
  pinMode(2, INPUT); // push button
  pinMode(3, OUTPUT); // green LED
  pinMode(4, OUTPUT); // red LED
  pinMode(5, OUTPUT); // red LED
}

void loop() {
  // Check the voltage level of the push button input
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // The button is not pressed

    // Turn the green LED on
    digitalWrite(3, HIGH);

    // Turn the red LEDs off
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    // The button is pressed

    // Turn the green LED on
    digitalWrite(3, LOW);

    // Turn one red LED on and one red LED \off
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    // Wait for a quatar second
    delay(250);

    // Toggle the red LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    // Wait for a quatar second
    delay(250);
  }
}

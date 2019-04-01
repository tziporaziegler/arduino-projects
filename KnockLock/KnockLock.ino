#include <Servo.h>

Servo myServo;

const int piezoPin = A0;
const int switchPin = 2;
const int greenLedPin = 3;
const int yellowLedPin = 4;
const int redLedPin = 5;
const int servoPin = 9;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  myServo.attach(servoPin);
  Serial.begin(9600);

  unlock();
}

void loop() {
  if(locked) {
    const int knockVal = analogRead(piezoPin);

    if(numberOfKnocks < 3 && knockVal > 0) {
      if(isValidKnock(knockVal)) {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go.");
    }

    if(numberOfKnocks >= 3) {
      unlock();
    }
  }
  else {
    const int switchVal = digitalRead(switchPin);

    if(switchVal == HIGH) {
      lock();      
      delay(1000);
    }
  }
}

void lock() {
  locked = true;
  
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, HIGH);

  myServo.write(90);

  Serial.println("The box is locked.");
}

void unlock() {
  locked = false;
  
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(redLedPin, LOW);

  myServo.write(0);

  Serial.println("The box is unlocked!");

  numberOfKnocks = 0;
}


boolean isValidKnock(int value) {
  if(value > quietKnock && value < loudKnock) {
    // The knock is valid if it is within the high/loud and low/quiet range.
    // Flash the yellow light if the knock is valid.
    digitalWrite(yellowLedPin, HIGH);
    delay(50);
    digitalWrite(yellowLedPin, LOW);

    // Print the knock value detected by the piezo to the serial monitor.
    Serial.print("Valid knock of value ");
    Serial.println(value);

    return true;
  }
  
  Serial.print("Bad knock of value ");
  Serial.println(value);

  return false;
}

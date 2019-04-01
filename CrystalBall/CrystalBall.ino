#include <LiquidCrystal.h>

const int RSPin = 11;
const int ENPin = 12;

const int LCDD7Pin = 5;
const int LCDD6Pin = 4;
const int LCDD5Pin = 3;
const int LCDD4Pin = 2;

LiquidCrystal lcd(RSPin, ENPin, LCDD4Pin, LCDD5Pin, LCDD6Pin, LCDD7Pin);

// Tilt switch
const int switchPin = 6;
int prevSwitchState = 0;

void setup() {
  // Start the LCD library, and tell it how large the screen is.
  lcd.begin(16, 2);

  // Set the tilt switch pin to INPUT.
  pinMode(switchPin, INPUT);

  // The cursor is automatically set to the beginning of the top line.
  lcd.print("Ask the");

  // Tell the screen where to move the cursor in order to write to the next line.
  // Since start counting from zero, 0 = first column; 1 = second row;
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop() {
  const int switchState = digitalRead(switchPin);

  // Use the tilt switch to replicate shaking a crystal ball.
  if(switchState != prevSwitchState) {
    if(switchState == LOW) {;;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);
      lcd.print(getMessage());
    }
  }

  // Assign switchState's value to prevSwitchState to track changes in the switch
  // the next time the loop runs.
  prevSwitchState = switchState;
}

String getMessage() {
  switch(random(8)) {
    case 0:
     return "Yes";
    case 1:
     return "Most likely";
    case 2:
     return "Certainly";
    case 3:
     return "Possibly";
    case 4:
     return "Unsure";
    case 5:
     return "Ask again";
    case 6:
     return "Doubtful";
    case 7:
     return "Nope";
  }
}

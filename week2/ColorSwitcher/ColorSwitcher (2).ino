/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledRPin =  9;      // the number of the LED pin
const int ledGPin =  10;      // the number of the LED pin
const int ledBPin =  11;      // the number of the LED pin
int ledIdx = 9;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int pressed = false;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void switcher() {
  pressed = true;
  digitalWrite(ledRPin, LOW);
  digitalWrite(ledGPin, LOW);
  digitalWrite(ledBPin, LOW);
  digitalWrite(ledIdx, HIGH);
  next();
}
void next() {
  if (ledIdx == 11) {
    ledIdx = 9;
  } else {
    ledIdx++;
  }
}
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && !pressed) {
    // turn LED on:
    switcher();
  } else if ( buttonState == LOW && pressed ){
    pressed = !pressed;
  }
}

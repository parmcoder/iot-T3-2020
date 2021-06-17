const int LEDpin = 26;
const int buttonPin = 18;
int lastState = HIGH;
int ledState = LOW;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDpin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  int currentState = digitalRead(buttonPin);

  if (currentState == LOW && lastState == HIGH) {
    ledState = !ledState;
    digitalWrite(LEDpin, ledState);   // turn the LED on (HIGH is the voltage level)

  }
  lastState = currentState;
  delay(10);                // wait for a second
}

const int buttonPin = 2;      // the pin that the LED is attached to
const int ledPin = 3;      // the pin that the LED is attached to

int voltage = 0;
bool isClicked = false;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(buttonPin, INPUT_PULLUP);
}
void circulate() {
  if (voltage == 100) {
    voltage = 0;

  } else {
    voltage += 50;
  }
  analogWrite(ledPin, voltage);
}
void loop() {
  int getButton = digitalRead(buttonPin);
  if ((isClicked == false) && (getButton == LOW)) {
    delay(20);

    getButton = digitalRead(buttonPin);
    if (getButton == LOW) { // fall edge and stays low
      circulate();
      Serial.println(voltage);
      delay(20);
    }
    isClicked = true;
  } else if ((isClicked == true) && (getButton == HIGH)) {
    isClicked = false;
  }
  //  delay(10);
}

const int buttonPin = 2;      // the pin that the LED is attached to

int voltage = 0;
bool isClicked = false;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int getButton = digitalRead(buttonPin);
  if ((isClicked == false) && (getButton == LOW)) {
    //    Serial.println("Circulating");
    int readFromAnalog = analogRead(A0);
    Serial.println(readFromAnalog);
    isClicked = true;
  } else if ((isClicked == true) && (getButton == HIGH)){
    isClicked = false;
  }
  delay(10);
}

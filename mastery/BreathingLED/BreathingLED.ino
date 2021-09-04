const int ledPin = 3;      // the pin that the LED is attached to
const int buttonPin = 2;      // the pin that the LED is attached to

int voltage = 0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void circulate() {
  voltage = (voltage + 1) % 100;
}

void loop() {
  int getButton = digitalRead(buttonPin);
  if (getButton == LOW) {
//    Serial.println("Circulating");
    Serial.println(voltage);
    circulate();
    analogWrite(ledPin, voltage);
  }
  delay(30);
  //  byte brightness;
  //
  //  // check if data has been sent from the computer:
  //  if (Serial.available()) {
  //    // read the most recent byte (which will be from 0 to 255):
  //    brightness = Serial.read();
  //    // set the brightness of the LED:
  //    analogWrite(ledPin, brightness);
  //  }

}

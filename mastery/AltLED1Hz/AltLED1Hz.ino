const int ledPin1 = 2;      // the pin that the LED is attached to
const int ledPin2 = 3;      // the pin that the LED is attached to

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void lightSwitch(int pin1, int pin2) {
  digitalWrite(ledPin1, pin1);
  digitalWrite(ledPin1, pin2);

}

void loop() {
  lightSwitch(HIGH, LOW);
  delay(1000);
    lightSwitch(HIGH, LOW);
  delay(1000);

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

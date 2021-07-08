#define BUFFERSIZE 255
#define LEDPIN 13
#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4
#define BUTTON4 5
#define BUTTON5 6
int buttonState1 = digitalRead(BUTTON1);
int buttonState2 = digitalRead(BUTTON1);
int buttonState3 = digitalRead(BUTTON1);
int buttonState4 = digitalRead(BUTTON1);
int buttonState5 = digitalRead(BUTTON1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(BUTTON5, INPUT_PULLUP);
  Serial.println("Setup!");
}

void loop() {
  buttonState1 = digitalRead(BUTTON1);
  buttonState2 = digitalRead(BUTTON2);
  buttonState3 = digitalRead(BUTTON3);
  buttonState4 = digitalRead(BUTTON4);
  buttonState5 = digitalRead(BUTTON5);

  if (buttonState1 == LOW) {
    Serial.write("Testing1!\n");
    delay(2000);
  }
  else if (buttonState2  == LOW) {
    Serial.write("Testing2!\n");
    delay(1000);
  }
  else if (buttonState3 == LOW) {
    Serial.write("Testing3!\n");
    delay(2000);
  }
  else if (buttonState4 == LOW) {
    Serial.write("Testing4!\n");
    delay(2000);
  }
  else if (buttonState5 == LOW) {
    Serial.write("Testing5!\n");
    delay(2000);
  }

}

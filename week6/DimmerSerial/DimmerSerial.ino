#define BUFFERSIZE 255
#define LEDPIN1 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN1, OUTPUT);
}

void loop() {
  char buffer[BUFFERSIZE];
  if (Serial.available()) { //there is a byte here.
    int nbytes = Serial.readBytesUntil('\n', buffer, BUFFERSIZE - 1);
    buffer[nbytes] = 0; //null terminated string
    String message = String(buffer);
    if (message == "status") {
      int d1 = digitalRead(LEDPIN1);
      Serial.println(d1 == HIGH ? "on1" : "off1");
    }
    else if (message) {
      analogWrite(LEDPIN1, message.toInt());
      Serial.println("ok1");
    }
    else {
      Serial.println("bad command");
    }
  }
}

#define BUFFERSIZE 255
#define LEDPIN1 3
#define LEDPIN2 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
}

void loop() {
  char buffer[BUFFERSIZE];
  if (Serial.available()) { //there is a byte here.
    int nbytes = Serial.readBytesUntil('\n', buffer, BUFFERSIZE - 1);
    buffer[nbytes] = 0; //null terminated string
    String message = String(buffer);
    if (message == "status") {
      int d1 = digitalRead(LEDPIN1);
      int d2 = digitalRead(LEDPIN2);
      Serial.println(d1 == HIGH ? "on1" : "off1");
      Serial.println(d2 == HIGH ? "on2" : "off2");
    }
    else if (message == "on1") {
      digitalWrite(LEDPIN1, HIGH);
      Serial.println("ok1");
    }
    else if (message == "off1") {
      digitalWrite(LEDPIN1, LOW);
      Serial.println("ok1");
    }
    else if (message == "on2") {
      digitalWrite(LEDPIN2, HIGH);
      Serial.println("ok2");
    }
    else if (message == "off2") {
      digitalWrite(LEDPIN2, LOW);
      Serial.println("ok2");
    }
    else {
      Serial.println("bad command");
    }
  }
}

#define BUFFERSIZE 255
#define RLEDPIN 4
#define GLEDPIN 3
#define BLEDPIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);
  Serial.println("Setup!");
}

void setLights(int red, int green, int blue) {
  digitalWrite(RLEDPIN, red);
  digitalWrite(GLEDPIN, green);
  digitalWrite(BLEDPIN, blue);
}

void loop() {
  char buffer[BUFFERSIZE];
  if (Serial.available()) { //there is a byte here.
    int nbytes = Serial.readBytesUntil('\n', buffer, BUFFERSIZE - 1);
    buffer[nbytes] = 0; //null terminated string
    String message = String(buffer);
    if (message == "red") {
      setLights(HIGH, LOW, LOW);
      Serial.println("just red");

    }
    else if (message == "green") {
      setLights(LOW, HIGH, LOW);
      Serial.println("just green");

    }
    else if (message == "blue") {
      setLights(LOW, LOW, HIGH);
      Serial.println("just blue");

    }
    else if (message == "ldr") {
      int ldrValue = analogRead(A0)/4;
      Serial.println(ldrValue);
    }
    else {
      Serial.println("bad command");
    }
  }
}

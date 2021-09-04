
#define BUFFERSIZE 255


// let's create a boolean variable to save the direction of our rotation

void setup() {

  // let's just set up a serial connection and test print to the console

  Serial.begin(9600);
}

void loop() {
  char buffer[BUFFERSIZE];
  if (Serial.available()) { //there is a byte here.
    int nbytes = Serial.readBytesUntil('\n', buffer, BUFFERSIZE - 1);
    buffer[nbytes] = 0; //null terminated string
    String message = String(buffer);
    if (message == "PM") {
      int readFromAnalog = analogRead(A0);
      Serial.println(readFromAnalog);
      delay(600);
    }
    else {
      Serial.println("bad command");
    }
  }
}

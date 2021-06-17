#define BUFFERSIZE 255
#define LEDPIN 13
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  char buffer[BUFFERSIZE];
  if(Serial.available()){//there is a byte here.
    int nbytes = Serial.readBytesUntil('\n', buffer, BUFFERSIZE-1);
    buffer[nbytes] = 0; //null terminated string
    String message = String(buffer);
    if(message == "status"){
      int d = digitalRead(LEDPIN);
      Serial.println(d==HIGH?"on":"off");
    }
    else if(message == "on"){
      digitalWrite(LEDPIN, HIGH);
      Serial.println("ok");
    }
    else if(message == "off"){
      digitalWrite(LEDPIN, LOW);
      Serial.println("ok");
    }
    else{
      Serial.println("bad command");
    }
  }
}

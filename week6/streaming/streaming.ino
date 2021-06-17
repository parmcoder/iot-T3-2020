void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int d = analogRead(A0);
  int d2 = analogRead(A1);
  unsigned long t = millis();
  String toSend = String(t) + " " + String(d)+ " " + String(d2);
  Serial.println(toSend);
}

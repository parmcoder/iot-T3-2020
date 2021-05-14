int led = 3;
int brightness = 0;
int fadeAmount = 5;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int pot_in = analogRead(A0);
  analogWrite(led, pot_in/4);
  delay(20);
}

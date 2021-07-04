int ledPin = 3;

int lastError = 0;
bool lastErrorValid = false;
int integral = 0;

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
//   analogWrite(3,0);

}

void loop() {
  int readout = analogRead(A0);
  Serial.println(readout);
  int goal = 600;
  int error = goal - readout;
  int diff = lastErrorValid?error - lastError:0;
  integral += error;
  lastError = error;
  lastErrorValid = true;

  float kp = 1;
  float ki = 0.05;
  float kd = 1;

  float action = kp*error + kd*diff + ki*integral;
  action = min(255, action);
  action = max(0, action);
  analogWrite(ledPin, int(action));
}

int count = 0;
int counted = false;
int sensitivity = 1; //depends to the object

void setup() {
  // put your setup code here, to run once:
  // make a port that detect the coin
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if the input changed
  // then count
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (10.0 / 1023.0);
  // print out the value you read:
  //  Serial.println(sensorValue);
//      Serial.println(voltage);
  if (voltage < sensitivity && !counted) {
    count += 1;
    counted = !counted;
    Serial.print("Total coin is ");
    Serial.println(count);
  } else if ( counted && voltage >= sensitivity) {
    counted = !counted;
  }
  delay(100);
}

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);

}

void lightOn(int x1, int x2, int x3, int x4){
  digitalWrite(5, x1);
  digitalWrite(2, x2);
  digitalWrite(3, x3);
  digitalWrite(4, x4);  
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(A0);
  if(sensorValue < 50) {
    lightOn(LOW, LOW, LOW, LOW);  
  }
  else if(sensorValue < 200) {
    lightOn(HIGH, LOW, LOW, LOW);  
  }
  else if(sensorValue < 500) {
    lightOn(HIGH, HIGH, LOW, LOW);  
  }
  else if(sensorValue < 750) {
    lightOn(HIGH, HIGH, HIGH, LOW);  
  }
  else{
    lightOn(HIGH, HIGH, HIGH, HIGH);  
  }
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
                        // wait for a second
}

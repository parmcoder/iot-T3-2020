/*
   cheapStepper_simple.ino
   ///////////////////////////////////////////
   using CheapStepper Arduino library v.0.2.0
   created by Tyler Henry, 7/2016
   ///////////////////////////////////////////

   this sketch illustrates basic step() functionality of the library:
   the stepper performs a full rotation, pauses 1 second,
   then does a full rotation in the other direction, and so on

   //////////////////////////////////////////////////////
*/

// first, include the library :)
#define BUFFERSIZE 255
#include <CheapStepper.h>


CheapStepper stepper;
// here we declare our stepper using default pins:
// arduino pin <--> pins on ULN2003 board:
// 8 <--> IN1
// 9 <--> IN2
// 10 <--> IN3
// 11 <--> IN4j

// let's create a boolean variable to save the direction of our rotation

boolean moveClockwise = true;
int deg90 = 1024;

void setup() {

  // let's just set up a serial connection and test print to the console

  Serial.begin(9600);
  Serial.println("Ready to start moving!");

}

void moveit(int step) {
  int direction = step > 0; //true of cw false for ccw??
  int absstep = step > 0 ? step : -step;
  for (int i = 0; i < absstep; i++) {
    stepper.step(direction);
  }
}

void loop() {
  char buffer[BUFFERSIZE];
  if (Serial.available()) { //there is a byte here.
    int nbytes = Serial.readBytesUntil('\n', buffer, BUFFERSIZE - 1);
    buffer[nbytes] = 0; //null terminated string
    String message = String(buffer);
    if (message == "CW") {
      moveit(deg90);
      Serial.println("just CW");
      delay(600);

    }
    else if (message == "CCW") {
      moveit(-deg90);
      Serial.println("just CCW");
      delay(600);


    }
    else {
      Serial.println("bad command");
    }
  }
}

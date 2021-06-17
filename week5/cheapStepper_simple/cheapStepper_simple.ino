/*
 * cheapStepper_simple.ino
 * ///////////////////////////////////////////
 * using CheapStepper Arduino library v.0.2.0
 * created by Tyler Henry, 7/2016
 * ///////////////////////////////////////////
 * 
 * this sketch illustrates basic step() functionality of the library:
 * the stepper performs a full rotation, pauses 1 second,
 * then does a full rotation in the other direction, and so on
 * 
 * //////////////////////////////////////////////////////
 */

// first, include the library :)

#include <CheapStepper.h>.0


CheapStepper stepper;
// here we declare our stepper using default pins:
// arduino pin <--> pins on ULN2003 board:
// 8 <--> IN1
// 9 <--> IN2
// 10 <--> IN3
// 11 <--> IN4j

 // let's create a boolean variable to save the direction of our rotation

boolean moveClockwise = true;
int laststateb2 = HIGH;
int laststateb3 = HIGH;

void setup() {
  
  // let's just set up a serial connection and test print to the console
  
  Serial.begin(9600);
  Serial.println("Ready to start moving!");

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
}

void move(int step){
  int direction = step>0; //true of cw false for ccw??
  int absstep = step > 0 ? step : -step;
  for(int i=0; i<absstep; i++){
    stepper.step(direction);
  }
}

void loop() {
  int currentb2 = digitalRead(2);
  int currentb3 = digitalRead(3);
  int deg45 = 512;
  if(laststateb2 == HIGH && currentb2==LOW){
    move(deg45);
  }

  if(laststateb3 == HIGH && currentb3==LOW){
    move(-deg45);
  }

  laststateb2 = currentb2;
  laststateb3 = currentb3;
}

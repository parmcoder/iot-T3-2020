
const int button_pin = 2;
const int duration = 2000;
const int sensitivity = 3; //depends to the object

#include <Arduino.h>

#define TONE_USE_INT
#define TONE_PITCH 440
#include <Pitch.h>

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(8, OUTPUT);
}

// change this to whichever pin you want to use
int buzzer = 8;
int note = NOTE_C7;
bool danger = false;
bool passed = false;
int current_time = millis();
int safe_time =  millis();
void loop() {
  // put your main code here, to run repeatedly:
  // if the input changed
  // then count
  current_time = millis();
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (10.0 / 1023.0);
  // print out the value you read:
  //    Serial.println(sensorValue);
  //        Serial.println(voltage);

  if (voltage < sensitivity && !passed) {
    Serial.println("Someone walked through the sensor");
    passed = true;
  } else if (voltage >= sensitivity  && passed) {
    safe_time =  current_time + duration;
    passed = false;
  }

  if (safe_time > current_time && passed) {
    danger = true;
  }
  if (danger) {
    tone(buzzer, note);
  }
  if (digitalRead(button_pin) == LOW) {
    safe_time =  millis();
    danger = false;
    noTone(buzzer);
  }
  delay(100);
}

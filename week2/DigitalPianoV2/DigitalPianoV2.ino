
const int INPUT_PINS[4] = {2, 3, 4, 5};
const int nPins = 4;
int duration = 500;

#include <Arduino.h>

#define TONE_USE_INT
#define TONE_PITCH 440
#include <Pitch.h>


int melody_keyboard[] = {
  NOTE_C7, NOTE_D7, NOTE_E7, NOTE_G7,
};

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  for ( int i = 0; i < nPins; i++) {
    pinMode(INPUT_PINS[i], INPUT_PULLUP);
  }
  pinMode(8, OUTPUT);
}

// change this to whichever pin you want to use
int buzzer = 8;
int current_note = 0;
bool pressed = false;
int current_time = millis();
int end_time =  millis();
void loop() {
  current_time = millis();
  for ( int i = 0; i < nPins; i++) {
    while (digitalRead(INPUT_PINS[i]) == LOW)
    {
      current_note = i;
      pressed = true;
      end_time = current_time + 500;
    }
  }
  if (end_time > current_time && pressed) {
    tone(buzzer, melody_keyboard[current_note]);
  } else {
    end_time =  millis();
    noTone(buzzer);
          pressed = false;

  }

}

//We always have to include the library
#include "LedControl.h"
#include "LEDScreen.h"
LEDScreen ls = LEDScreen(2, 4, 3);
const int INPUT_PIN = 6;
const int BUZZER_PIN=11;

int last_state = HIGH;
int led_state = 0;

/* we always wait a bit between updates of the display */
unsigned long delaytime = 100;
int lastTick = 0;
int currentScreen = 0;
int screen1[8] = {
  0b00000000,
  0b01100110,
  0b01100110,
  0b00000000,
  0b10000001,
  0b01000010,
  0b00111100,
  0b00000000
};

int screen2[8] = {
  0b00000000,
  0b01100110,
  0b01100110,
  0b00000000,
  0b00111100,
  0b01000010,
  0b10000001,
  0b00000000
};

void setup() {
  pinMode(INPUT_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  ls.writeBuffer(screen1);
}
void led_color(int led_state) {
  if (led_state == 0) {
    ls.writeBuffer(screen2);
  }
  else if (led_state == 1) {
    ls.writeBuffer(screen1);
  }
}
void loop() {
  int data = digitalRead(INPUT_PIN);

  if (last_state == HIGH && data == LOW) { //falling edge
    //Serial.println(led_state);
    delay(50);
    data = digitalRead(INPUT_PIN);
    if (data == LOW) { // fall edge and stays low
      led_state = (led_state + 1) % 2;
      led_color(led_state);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
    }
  }
  ls.display();
}

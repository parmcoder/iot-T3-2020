//We always have to include the library
#include "LedControl.h"
#include "LEDScreen.h"
LEDScreen ls = LEDScreen(2, 4, 3);

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
  smile();
}

void smile() {
  ls.writeBuffer(screen1);
}

void sad() {
  ls.writeBuffer(screen2);
}
void loop() {
  ls.display();
}

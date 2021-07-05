//We always have to include the library
#include "LedControl.h"
#include "LEDScreen.h"
LEDScreen ls = LEDScreen(2,4,3);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;
int lastTick=0;
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
  900,
  9,
  9,
  0b00000000,
  9,
  0b01000010,
  9,
  0b00000000
};

void setup() {

  ls.writeBuffer(screen1);
}

void loop() {
  int now = millis();
  int shouldUpdate = now-lastTick > 1000;
  
  if(shouldUpdate){
    if(currentScreen==0){
      currentScreen=1;
      ls.writeBuffer(screen2);
    } else{
      currentScreen=0;
      ls.writeBuffer(screen1);
    }
    lastTick = now;
  }
  ls.display();
}

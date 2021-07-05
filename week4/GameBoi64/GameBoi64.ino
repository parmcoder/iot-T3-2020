#include "PongGame.h"
#include "LedControl.h"
#include "LEDScreen.h"

//using namespace std;
using namespace hw4;

const int nrow = 8;
const int ncol = 8;

PongGame pongGame(nrow, ncol);
LEDScreen ls = LEDScreen(2, 4, 3);

int* buffer = new int[nrow * ncol];
int* screen = new int[8];

const int P1_LEFT_PIN = 11;
const int P1_RIGHT_PIN = 10;
const int P2_LEFT_PIN = 9;
const int P2_RIGHT_PIN = 8;


/***********CHANGE THESE*********************/

void setup() {
  pongGame.start(millis());
  ls.writeBuffer(screen);
  pinMode(P1_LEFT_PIN, INPUT_PULLUP);
  pinMode(P1_RIGHT_PIN, INPUT_PULLUP);
  pinMode(P2_LEFT_PIN, INPUT_PULLUP);
  pinMode(P2_RIGHT_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    Serial.println(((int)pow(2, i)));

  }

}

void drawScreen(int* buffer) {
  Serial.println("First");

  for (int irow = 0; irow < nrow; irow++) {
    screen[irow] = 0;
    //      Serial.println(buffer[irow]);

    for (int icol = 0; icol < ncol; icol++) {
      if (icol < 7) {
        screen[irow] += buffer[irow * ncol + icol] * ((int)pow(2, 7 - icol) + 1);
        Serial.print(buffer[irow * ncol + icol] * ((int)pow(2, 7 - icol) + 1));


      } else {
        screen[irow] += buffer[irow * ncol + icol] * ((int)pow(2, 7 - icol));
        Serial.print(buffer[irow * ncol + icol] * ((int)pow(2, 7 - icol)));

      }

      //      Serial.print(buffer[irow * ncol + icol]);

    }
    //    Serial.println(screen[irow]);
    Serial.println();

  }
  ls.writeBuffer(screen);
  Serial.println("End");

}

void processInput(unsigned long tick) { //You will need to change this

  int P1_LEFT_EVENT = digitalRead(P1_LEFT_PIN);
  int P1_RIGHT_EVENT = digitalRead(P1_RIGHT_PIN);
  int P2_LEFT_EVENT = digitalRead(P2_LEFT_PIN);
  int P2_RIGHT_EVENT = digitalRead(P2_RIGHT_PIN);

  if (P1_LEFT_EVENT == LOW) {
    pongGame.movePad(Player::PLAYER_ONE, PadDirection::UP);

  }
  if (P1_RIGHT_EVENT == LOW) {
    pongGame.movePad(Player::PLAYER_ONE, PadDirection::DOWN);

  }
  if (P2_LEFT_EVENT == LOW) {
    pongGame.movePad(Player::PLAYER_TWO, PadDirection::UP);

  }
  if (P2_RIGHT_EVENT == LOW) {
    pongGame.movePad(Player::PLAYER_TWO, PadDirection::DOWN);

  }
}

unsigned long dirty_tick = 0;

void loop() {
  const unsigned long tick = millis();
  processInput(tick);
  pongGame.update(tick);

  if (pongGame.isDirty()) {

    pongGame.paint(buffer);
    drawScreen(buffer);
//    dirty_tick = tick + 100;
  }
//  if (dirty_tick <= tick)  ls.display();
  ls.display();
}

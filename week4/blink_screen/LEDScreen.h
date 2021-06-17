#define NROW 8
#include "LedControl.h"
class LEDScreen{
private: 
  int dataIn;
  int clk;
  int cs;
  int buffer[NROW];
  int currentRow;
  LedControl lc;
public:
  LEDScreen(int dataIn, int clk, int cs)
    : lc(dataIn, clk, cs, 1),
    dataIn(dataIn),
    cs(cs),
    clk(clk),
    currentRow(0)
  {
    lc.shutdown(0,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0,8);
    /* and clear the display */
    lc.clearDisplay(0);
    for(int i=0;i<NROW;i++){
      this->buffer[i] = 0;
    }
  }

  void display(){
    lc.setRow(0,currentRow,this->buffer[currentRow]);
    this->currentRow = (this->currentRow + 1)%NROW;
  }

  void writeBuffer(int* data){
    for(int i=0;i<NROW;i++){
      this->buffer[i] = data[i];
    }
  }
};

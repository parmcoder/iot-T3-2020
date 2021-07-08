#include "Quad7Segment.h"

// 0 means on 1 means off
//http://www.nutsvolts.com/magazine/article/using-seven-segment-displays-part-1
const int Quad7Segment::pattern[10] = { 
  //abcdefg
  0b0000001, //0
  0b1001111, //1
  0b0010010, //2
  0b0000110, //3
  0b1001100, //4
  0b0100100, //5
  0b0100000, //6
  0b0001111, //7
  0b0000000, //8
  0b0001100 //9
};

Quad7Segment::Quad7Segment(int ser, int srClk, int rClk, int srClr){
  //implement this
}

void Quad7Segment::setup(){
  //implement this
}

void Quad7Segment::update(){
  //implement this
}

void Quad7Segment::setNumber(int n){
  //implement this
}

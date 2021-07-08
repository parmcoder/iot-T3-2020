#ifndef QUAD7SEGMENT_H
#define QUAD7SEGMENT_H

class Quad7Segment{
  public:
    static const int pattern[10];
    Quad7Segment(int ser, int srClk, int rClk, int srClr);
    void setup();
    void update();
    void setNumber(int n);
   //add other stuff if you need
};

#endif

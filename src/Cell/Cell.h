#ifndef CELL_H
#define CELL_H
#include <Arduino.h>

class Cell {
private:
 byte pin;
 float voltage;
 byte percentage;
 void read();
public:

  void measure();
  void setup(byte pin);
  void setVoltage(float voltage);
  float getVoltage();
};
#endif /* end of include guard: CELL_H */

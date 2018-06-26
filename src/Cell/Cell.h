#ifndef CELL_H
#define CELL_H
#include <Arduino.h>

class Cell {
protected:
 uint8_t pin;
 uint16_t value;
 float voltage;
 uint8_t percentage;
 void read();
public:

  float measurePin();
  void  setup(uint8_t pin);
  void  setVoltage(float voltage);
  float getVoltage();
  void  calcPercentage();

};
#endif /* end of include guard: CELL_H */

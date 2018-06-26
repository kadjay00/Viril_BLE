#ifndef CELLVD_H
#define CELLVD_H
#include "Cell/Cell.h"
#include <Arduino.h>
class CellVD: public Cell
{
private:
  float R1;
  float R2;
  float undividedVoltage;
public:
  using Cell::measurePin;
  using Cell::setup;
  float measurePin();
  void setup(uint8_t pin,float R1, float R2);
};


#endif /* end of include guard: CELLVD_H */

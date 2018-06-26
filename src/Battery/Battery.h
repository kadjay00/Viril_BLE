#include <Arduino.h>
#include <Wire.h>
#include "Cell/Cell.h"
#include "Cell/CellVcc.h"
#include "Cell/CellVD.h"
#include <string>
#include <array>
#include <vector>
#include <list>
#ifndef BATTERY_H
#define BATTERY_H

class Battery
{
  byte pin;
  std::vector<Cell*> cells;


  byte chargePin;
  float voltage;
  uint8_t analogValue;
  uint8_t percentage;
  bool charging;
  void read();
  void calcPercentage();
  void measureCells();
  void checkCharge();

public:

  void setup(std::vector<Cell*> cells, int chargePin);
  float getVoltage();
  uint8_t getPercentage();
  void setPercentage(uint8_t percentage);
  void update();
};

#endif /* end of include guard: BATTERY_H */

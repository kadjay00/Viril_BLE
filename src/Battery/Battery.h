#include <Arduino.h>
#include <Wire.h>
#include "Cell/Cell.h"
#include <array>
#include <vector>
#include <list>
#ifndef BATTERY_H
#define BATTERY_H

class Battery
{
  byte pin;
  std::vector<Cell> cells;
  byte chargePin;
  float voltage;
  int analogValue;
  int percentage;
  bool charging;
  void read();
  void calcPercentage();

  void checkCharge();

public:

  void setup(uint8_t cellPins[], int chargePin);
  float getVoltage();
  int getPercentage();
  void setPercentage(int percentage);
  void update();
};

#endif /* end of include guard: BATTERY_H */

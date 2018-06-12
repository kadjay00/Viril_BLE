#include <Arduino.h>
#ifndef BATTERY_H
#define BATTERY_H

class Battery
{
  byte pin;
  byte chargePin;
  float voltage;
  int analogValue;
  int percentage;
  bool charging;
  void read();
  void calcPercentage();
  void checkCharge();

public:

  void setup(int pin, int chargePin);
  float getVoltage();
  int getPercentage();
  void setPercentage(int percentage);
  void update();
};

#endif /* end of include guard: BATTERY_H */


#ifndef POWER_H
#define POWER_H
#include <Arduino.h>
#include <Battery/Battery.h>
class Power
{
public:

  void init(Battery* batt);
  void update();
  unsigned int getMaxPower();
  unsigned int getSetPower();
  void setSetPower(int power);
private:
   float coilResistance;
   unsigned int maxPower;
   Battery* pBattery;
   void calcMaxPower();
   unsigned int setPower;
};



#endif /* end of include guard: POWER_H */

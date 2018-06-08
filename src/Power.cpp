#include <Arduino.h>
#include <Battery.cpp>
//Class for reading and outputting a power value, set by a potmeter.

class Power
{
public:

  void init(Battery* batt)
  {
    this->pBattery = batt;
  }
  void update()
  {
    this->calcMaxPower();
  }
  unsigned int getMaxPower()
  {
    return this->maxPower;
  }
  unsigned int getSetPower()
  {
    return this->setPower;
  }
private:
   float coilResistance;
   unsigned int maxPower;
   Battery* pBattery;
   void calcMaxPower()
   {
     this->maxPower = sq(this->pBattery->getVoltage())/this->coilResistance;
   }
   unsigned int setPower;

};

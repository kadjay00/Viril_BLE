
#include <Arduino.h>
#include "Power.h"


  void Power::init(Battery* batt)
  {
    this->pBattery = batt;
  }
  void Power::update()
  {
    this->calcMaxPower();
  }
  unsigned int Power::getMaxPower()
  {
    return this->maxPower;
  }
  unsigned int Power::getSetPower()
  {
    return this->setPower;
  }
   void Power::calcMaxPower()
   {
     this->maxPower = sq(this->pBattery->getVoltage())/this->coilResistance;

   }

#ifndef MOSFET_H
#define MOSFET_H

#include "Puff.cpp"
#include "Power/Power.h"
class Mosfet
{
private:
  int pin;
  int pwm;
  Power* pPower;
  Puff puff;

  void calcPwm();
public:
  void init(Power* pow);
  void setup(int pin);
  void start();
  void stop();
  void update();
};


#endif /* end of include guard: MOSFET_H */

#include <Arduino.h>
#include "Power/Power.h"
class Potmeter
{
  byte pin;
  int analog;
  int power;
  void read();
  void calcPower();
  Power* pPower;
public:
  void init(Power* pPower);
  void setup(byte pin);
  void update();

};

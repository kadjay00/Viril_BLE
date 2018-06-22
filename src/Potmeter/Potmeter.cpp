#include "Potmeter.h"

void Potmeter::init(Power* pow)
{
  this->pPower = pow;
}
void Potmeter::setup(byte pin)
{
  pinMode(pin, INPUT);
}
void Potmeter::read()
{
  this->analog = analogRead(this->pin);
}
void Potmeter::calcPower()
{
  this->pPower->getMaxPower();
  this->power = (this->analog / 4096) * (this->pPower->getMaxPower() - this->pPower->getSetPower());
}
void Potmeter::update()
{
  //Read the potmeter
  this->read();
  //Calculate the Power comparing the potmeter to the set power range
  this->calcPower();
  // set the power value in the power class
  this->pPower->setSetPower(this->power);

}
//(1024/4096)*(80-20)+20

#include <Arduino.h>
#include "Cell.h"

void Cell::setup(uint8_t pin)
{
  this->pin = pin;

  pinMode(this->pin, INPUT);

}
float Cell::measurePin()
{
  return 3.75;

}
void Cell::calcPercentage()
{
  //TODO: test interpolate function
  this->percentage = 80; //MOCKUP
  this->percentage = 100+(181.818 * (-193.939+ (-50.5051+ (1843.43 * (-4076.48+138288.0 * (-4.0+this->voltage)) * (-3.7+this->voltage))* (-4.1+this->voltage))* (-3.9+this->voltage))* (-3.65+this->voltage)) *(-4.2+this->voltage);
}
//TODO: Inheritance of real cell vs vcc measured cell vs cell with pull down resistors

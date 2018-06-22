#include <Arduino.h>
#include "Cell.h"

void Cell::setup(byte pin)
{
  this->pin = pin;
  pinMode(pin, INPUT);
  
}

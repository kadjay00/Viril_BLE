#include "CellVD.h"


/*
 * Setup the battery cell with voltage dividor resistors
 * @param pin The analog pin connected to the voltage divider
 * @param R1  The resistor connected to the + of battery
 * @param R2  The resistor connected to the + of battery
 */
void CellVD::setup(uint8_t pin, float R1, float R2)
{
    this->pin = pin;
    this->R1 = R1;
    this->R2 = R2;
    pinMode(this->pin, INPUT);
}
float CellVD::measurePin()
{
  this->value = analogRead(this->pin);
  this->undividedVoltage = (this->value * 3.3) / 4095.0;
  return this->undividedVoltage / (this->R2/(this->R1+this->R2));
}

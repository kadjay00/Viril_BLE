#include <Arduino.h>
class Vape
{
  int mosfetPin;
  int pwm;
  int setPower;
  int maxPower;
  int minSetPower;
  int maxSetPower;
  float coilResistance;

  void calcPwmDc()
  {
    //get battery voltage
    //TODO: Does this work?
    this->pwm = 255*this->setPower/this->maxPower;
  }
  void calcMaxPower(float voltage)
  {

    this->maxPower = sq(voltage)/this->coilResistance;
  }
public:
  void setup(int mosfetPin)
  {
    this->mosfetPin = mosfetPin;
    pinMode(this->mosfetPin, OUTPUT);
    Serial.println("Mosfet setup complete.");
  }




};

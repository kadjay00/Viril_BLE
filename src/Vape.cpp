#include <Arduino.h>
#include <Puff.cpp>
class Vape
{
  int mosfetPin;
  int pwm;
  int setPower;
  int maxPower;
  int minSetPower;
  int maxSetPower;
  float coilResistance;

  Puff puff;

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
  void start()
  {
    Serial.println("Started vaping");
    this->puff.start(50);
    // TODO: Get time
  }
  void stop()
  {
    Serial.println("Stopped vaping");
    this->puff.stop();

  }
};

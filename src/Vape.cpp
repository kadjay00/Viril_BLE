#include <Arduino.h>
#include <Power.cpp>
#include <Puff.cpp>
class Mosfet
{
  int pin;
  int pwm;
  Power* pPower;
  Puff puff;

  void calcPwm()
  {
    this->pwm = (this->pPower->getSetPower()/this->pPower->getMaxPower()) * 255;
  }
public:
  void init(Power* pow)
  {
    this->pPower = pow;
  }
  void setup(int pin)
  {
    this->pin = pin;
    //setup pinmode for mosfet pin
    pinMode(this->pin, OUTPUT);
    //set mosfet to low signal
    digitalWrite(this->pin, LOW);
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
  void update()
  {
    this->calcPwm();
  }
};

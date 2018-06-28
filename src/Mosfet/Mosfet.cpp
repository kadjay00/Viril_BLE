#include "Mosfet.h"

  void Mosfet::calcPwm()
  {
    this->pwm = (this->pPower->getSetPower()/this->pPower->getMaxPower()) * 255;
  }
  void Mosfet::init(Power* pow)
  {

    this->pPower = pow;
  }
  void Mosfet::setup(uint8_t pin)
  {
    this->pin = pin;
    //setup pinmode for mosfet pin
    pinMode(this->pin, OUTPUT);
    //set mosfet to low signal
    digitalWrite(this->pin, LOW);
    //TODO: Setup pwm channel
  }
  void Mosfet::start()
  {
    Serial.println("Started vaping");
    this->puff.start(50);
    //TODO: set pwm value

    // TODO: Get time (in puff class?)

  }
  void Mosfet::stop()
  {
    Serial.println("Stopped vaping");
    this->puff.stop();
  }
  void Mosfet::update()
  {
    this->calcPwm();
  }

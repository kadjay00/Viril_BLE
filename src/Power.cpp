#include <Arduino.h>
//Class for reading and outputting a power value, set by a potmeter.
class Power
{
    const int MAXANALOGVALUE = 4096;
    int pin;
    int minPower;
    int maxPower;
    int setPower;
    int analogValue;
    void setup(int pin)
    {
      this->pin = pin;
      pinMode(this->pin, INPUT);
      Serial.println("Setup Potentiometer complete.");
    }
    void read()
    {
      this->analogValue = analogRead(this->pin);
    }
    void calcSetPower()
    {
      //val = ((percent * (max - min) / 100) + min
      this->setPower = ((this->analogValue/this->MAXANALOGVALUE)* (this->maxPower - this->minPower));
    }
    void setMinPower(int minPower)
    {
      this->minPower = minPower;
    }
    void setMaxPower(int maxPower)
    {
      this->maxPower = maxPower;
    }
    int getSetPower()
    {
      return this->setPower;
    }

    void update()
    {

    }

};

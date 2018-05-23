#include <Arduino.h>
class Puff
{
  unsigned long startTime;
  unsigned long stopTime;
  unsigned long puffTime;
public:
  void start(int setPower)
  {
    Serial.println("New Puff at " + String(setPower) + "W");
    this->startTime = millis();
  }
  void stop()
  {
    this->stopTime = millis();
    this->puffTime = this->stopTime - this->startTime;
    Serial.println("Puff: " + String(this->puffTime) + " millis");

  }

};

#include <Arduino.h>
class Battery
{
  int pin;
  int chargePin;
  float voltage;
  int analogValue;
  int percentage;
  bool charging;
/**
 * Gets the pulled down voltage and converts it to a real voltage
 */
  void read()
  {
    //Get analog voltage
    this->analogValue = analogRead(this->pin);
    //TODO: Convert analog voltage real voltage
    this->voltage = 8.0; //MOCKUP
  }
  /**
   * Calculates the battery percentage using an interpolate function
   */
  void calcPercentage()
  {
    //TODO: implement interpolate function
    this->percentage = 80; //MOCKUP
  }
  /**
   * Checks if a cable is connected to the charge port. So far the hardware doesn't allow for checking if the cable is giving a current.
   */
  void checkCharge()
  {
    this->charging = digitalRead(this->chargePin);
    if (this->charging) {
      // TODO: What to do when charging?
      // Maybe stop polling for button and show charge on display?
    }
  }
public:
  /**
   * Set up the battery pins
   * @param pin       [The pin connected to the battery]
   * @param chargePin [the pin connected to the charge present pin]
   */
  void setup(int pin, int chargePin)
  {
    this->pin = pin;
    this->chargePin = chargePin;
    pinMode(pin, INPUT);
    pinMode(chargePin, INPUT_PULLUP);
    Serial.println("Battery Setup Complete");
  }
  /**
   * Updates the battery state, to be placed inside the main loop.
   */
  void update()
  {
    this->read();
    this->calcPercentage();
    this->checkCharge();
  }
  /**
   * Gets the battery voltage
   * @return Voltage (float)
   */
  float getVoltage()
  {
    return this->voltage;
  }

};

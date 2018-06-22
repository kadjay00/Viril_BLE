#include "Battery.h"

/**
 * Gets the pulled down voltage and converts it to a real voltage
 */
  void Battery::read()
  {
    //Get analog voltage
    this->analogValue = analogRead(this->pin);
    //TODO: Convert analog voltage real voltage (pull down)
    this->voltage = 8.0; //MOCKUP
  }
  /**
   * Calculates the battery percentage using an interpolate function
   */
  void Battery::calcPercentage()
  {
    //TODO: test interpolate function
    this->percentage = 80; //MOCKUP
    this->percentage = 100+(181.818 * (-193.939+ (-50.5051+ (1843.43 * (-4076.48+138288.0 * (-4.0+this->voltage)) * (-3.7+this->voltage))* (-4.1+this->voltage))* (-3.9+this->voltage))* (-3.65+this->voltage)) *(-4.2+this->voltage);
  }
  /**
   * Checks if a cable is connected to the charge port.
   */
  void Battery::checkCharge()
  {
    this->charging = digitalRead(this->chargePin);
    if (this->charging)
    {
      // TODO: What to do when charging?
      // Maybe stop polling for button and show charge on display?
    }
  }
  /**
   * Set up the battery pins
   * @param pin       [The pin connected to the battery]
   * @param chargePin [the pin connected to the charge present pin]
   */
  void Battery::setup(uint8_t cellPins[], int chargePin)
  {
    this->chargePin = chargePin;
    pinMode(chargePin, INPUT_PULLUP);
    // TODO: Create Cell List
    for( unsigned int i = 0; i < sizeof(cellPins); i = i + 1 )
    {
        Cell cell;
        cell.setup(cellPins[i]);
        this->cells.push_back(cell);
    }
    Serial.println("Battery Setup Complete");
  }
  /**
   * Updates the battery state
   */

  /**
   * Gets the battery voltage
   * @return Voltage (float)
   */
  float Battery::getVoltage()
  {
    return this->voltage;
  }
  int Battery::getPercentage()
  {
    return this->percentage;
  }
  void Battery::setPercentage(int percentage)
  {
    this->percentage = percentage;
  }
  void Battery::update()
  {
    this->read();
    this->calcPercentage();
    this->checkCharge();


  }

/*
100+(181.818  (-193.939+(-50.5051+(1843.43\[VeryThinSpace]+(-4076.48+138288. (-4.+VOLT)) (-3.7+VOLT)) (-4.1+VOLT)) (-3.9+VOLT)) (-3.65+VOLT)) (-4.2+VOLT)
 */

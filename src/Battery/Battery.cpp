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
  void Battery::setup(std::vector<Cell*> cells, int chargePin)
  {
    this->chargePin = chargePin;
    pinMode(chargePin, INPUT_PULLUP);
    this->cells = cells;
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
  uint8_t Battery::getPercentage()
  {
    return this->percentage;
  }
  void Battery::setPercentage(uint8_t percentage)
  {
    this->percentage = percentage;
  }
  void Battery::update()
  {
    this->read();
    this->calcPercentage();
    this->checkCharge();
  }
  void Battery::measureCells()
  {

    float tempVoltage = 0;
    for( uint8_t i = 0; i < sizeof(this->cells); i = i + 1 )
    {
        Cell* pCell = this->cells[i];
        pCell->setVoltage(pCell->measurePin() - tempVoltage);
        tempVoltage = pCell->getVoltage();
    }
  }
/*
100+(181.818  (-193.939+(-50.5051+(1843.43\[VeryThinSpace]+(-4076.48+138288. (-4.+VOLT)) (-3.7+VOLT)) (-4.1+VOLT)) (-3.9+VOLT)) (-3.65+VOLT)) (-4.2+VOLT)
 */

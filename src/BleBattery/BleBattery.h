#ifndef BLEBATTERY_H
#define BLEBATTERY_H

#include "Ble/Ble.h"
#include "Battery/Battery.h"
#include <string>
#include <math.h>
#include "Convert/Convert.h"

class BleBattery {

private:
   Battery* pBattery;
   Ble* pBle;



public:
  BLEService *pService;
  BLECharacteristic *pVoltageCharacteristic;
  BLECharacteristic *pPercentageCharacteristic;
  BLECharacteristic *pChargingCharacteristic;
  /**
   * Initializes the pointers
   * @param batt [description]
   */
  void init(Ble* ble, Battery* battery);
  //TODO: Voltage Characteristic
  void setup();
  void update();
};
#endif /* end of include guard: BLEBATTERY_H */

#include "BleBattery/BleBattery.h"
#include <stdlib.h>

  /**
   * Initializes the pointers
   * @param batt [description]
   */

  void BleBattery::init(Ble* ble, Battery* battery)
  {
    this->pBattery = battery;
    this->pBle = ble;
  }
  //TODO: Voltage Characteristic
  void BleBattery::setup()
  {
    this->pService = this->pBle->bleServer->createService(BLEUUID((uint16_t)0x4200));
    this->pVoltageCharacteristic = this->pService->createCharacteristic(
                        BLEUUID((uint16_t)0x4201),
                        BLECharacteristic::PROPERTY_READ    |
                        BLECharacteristic::PROPERTY_INDICATE|
                        BLECharacteristic::PROPERTY_NOTIFY
    );
    this->pVoltageCharacteristic->addDescriptor(new BLE2902());
    //this->pVoltageCharacteristic->setValue(this->);


    this->pPercentageCharacteristic = this->pService->createCharacteristic(
                        BLEUUID((uint16_t)0x4202),
                        BLECharacteristic::PROPERTY_READ    |
                        BLECharacteristic::PROPERTY_INDICATE|
                        BLECharacteristic::PROPERTY_NOTIFY
    );
    this->pPercentageCharacteristic->addDescriptor(new BLE2902());

    this->pChargingCharacteristic = this->pService->createCharacteristic(
                        BLEUUID((uint16_t)0x4203),
                        BLECharacteristic::PROPERTY_READ    |
                        BLECharacteristic::PROPERTY_INDICATE|
                        BLECharacteristic::PROPERTY_NOTIFY
    );
    this->pChargingCharacteristic->addDescriptor(new BLE2902());

    this->pService->start();
  }
  void BleBattery::update()
  {
      //float test = 3.77777;
      //float roundedtest = roundf(test * 100) / 100;
      this->pVoltageCharacteristic->setValue(this->pBattery->test);
      this->pVoltageCharacteristic->notify();
      Serial.println("Value set, notified");

  }

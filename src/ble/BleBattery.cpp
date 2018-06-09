#include <Battery.cpp>
#include <Ble.cpp>
#include <string>
#include <tostring.cpp>
class BleBattery {

private:
   Battery* pBattery;
   Ble* pBle;

   BLEService *pService;
   BLECharacteristic *pVoltageCharacteristic;
   BLECharacteristic *pPercentageCharacteristic;
   BLECharacteristic *pChargingCharacteristic;

public:
  /**
   * Initializes the pointers
   * @param batt [description]
   */
  void init(Battery* batt, Ble *ble)
  {
    this->pBattery = batt;
    this->pBle = ble;
  }
  //TODO: Voltage Characteristic
  void setup()
  {
    this->pService = this->pBle->bleServer->createService(BLEUUID((uint16_t)0x4200));
    this->pVoltageCharacteristic = this->pService->createCharacteristic(
                        BLEUUID((uint16_t)0x4201),
                        BLECharacteristic::PROPERTY_READ    |
                        BLECharacteristic::PROPERTY_INDICATE|
                        BLECharacteristic::PROPERTY_NOTIFY

    );
    this->pVoltageCharacteristic->addDescriptor(new BLE2902());

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
  void update()
  {
    this->pVoltageCharacteristic->setValue(std::to_string(5));
  }

  //TODO: Percentage Characteristic
  //TODO: Charging Characteristic/Service (?)


};

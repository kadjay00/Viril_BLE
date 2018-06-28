#ifndef BLE_H
#define BLE_H

//BLE LIBRARIES
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>

class MyServerCallbacks: public BLEServerCallbacks {

    void onConnect(BLEServer* bleServer);

    void onDisconnect(BLEServer* bleServer);
  public:
    bool deviceConnected;
};
class Ble
{
public:
  BLEServer *bleServer;
  void setup(std::string name);
  void update();
  void finish();
};
#endif /* end of include guard: BLE_H */

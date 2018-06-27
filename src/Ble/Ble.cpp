//BLE LIBRARIES
#include "Ble.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>



    void MyServerCallbacks::onConnect(BLEServer* bleServer) {
      deviceConnected = true;
    };

    void MyServerCallbacks::onDisconnect(BLEServer* bleServer) {
      deviceConnected = false;
    }


  void Ble::setup(std::string name)
  {
    BLEDevice::init(name);
    // Create the BLE Server
    this->bleServer = BLEDevice::createServer();
    this->bleServer->setCallbacks(new MyServerCallbacks());

    Serial.println("Bluetooth Setup Complete.");
  }
  void Ble::update()
  {
    //Serial.println(this->bleServer->getConnectedCount());
  }
  void Ble::finish()
  {
    this->bleServer->getAdvertising()->start();
  }

#include <Arduino.h>
#include <WiFi.h>

//#include <Adafruit_SSD1306.h>
#include <Battery.cpp>
#include <ClickButton.h>

//BLE LIBRARIES
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <Wire.h>

// define port numbers
#define MOSFET 5
#define FIREBUTTON 4
#define BATTERY 10
#define POTMETER 12
#define BATTERY_LOW 7.1

float coilResistance = 0.4;

int minPower;
int maxPower;
int setPower;
int setPowerMode = 0; //mode: 0 for reading Potmeter, 1 for setting power by BLE App

int minPotVal;
int maxPotVal = 4096;

bool deviceConnected = false;

// the LED
const int ledPin = 10;
int ledState = 0;
int analogVoltage;
int batteryVoltage;

unsigned long puffTime = 0;
unsigned long puffStart = 0;

bool vape_hold =false;
bool vape_state = false;
// the Button
const int buttonPin1 = 4;
ClickButton fireButton(FIREBUTTON, LOW, CLICKBTN_PULLUP);

//init the real time clock
// Arbitrary LED function
int LEDfunction = 0;
int lastButtonState;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      Serial.println("Device connected");
    };
    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      Serial.println("Device disconnected");
    }
};

void setup()
{
  Serial.begin(9600);
  delay(1);
  // Setup button timers (all in milliseconds / ms)
  // (These are default if not set, but changeable for convenience)
  fireButton.debounceTime   = 20;   // Debounce timer in ms
  fireButton.multiclickTime = 150;  // Time limit for multi clicks
  fireButton.longClickTime  = 160; // time until "held-down clicks" register
  //Init BLE Device's name
  BLEDevice::init("Viril");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  pServer->getAdvertising()->start();
}


void loop()
{
  //Serial.println(digitalRead(FIREBUTTON));
  lastButtonState = fireButton.clicks;
  fireButton.Update();

  if(fireButton.clicks == 5) true;//lock();

  // slow blink (must hold down button. 1 second long blinks)
  if(fireButton.clicks == -1) true;//startVaping();

  //if(fireButton.clicks == 0 && !digitalRead(FIREBUTTON)) longPressCallback();
  if(digitalRead(FIREBUTTON) && vape_state) true;//stopVaping();
}
void startVaping()
{
    puffStart = millis();
    vape_state = true;
    Serial.println("Started vaping");

}
void stopVaping()
{
  Serial.println("Stopped vaping");
  vape_state = false;
  puffTime = millis() - puffStart;
  Serial.println("Vaped for " + String(puffTime) + " millis.");
  //TODO: Save Puff Time
}

#include <Arduino.h>
#include <WiFi.h>
#include <SimpleTimer.h>


//#include <Adafruit_SSD1306.h>
#include <ble/BleBattery.cpp>
#include <Vape.cpp>

//#include <ble/BleBattery.cpp>

#include <ClickButton.h>
#include <Wire.h>

#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

// define port numbers
#define MOSFET 5
#define FIREBUTTON 4
#define BATTERY 10
#define POTMETER 12
#define BATTERY_LOW 7.1

//bool deviceConnected = false;



bool vape_hold  = false;
bool vape_state = false;
// the Button
const int buttonPin1 = 4;
ClickButton fireButton(FIREBUTTON, LOW, CLICKBTN_PULLUP);
int lastButtonState;

Battery battery;
Vape vape;


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
  battery.setup(4, 5);
  battery.setPercentage(40);
  vape.setup(MOSFET);
  Battery* ptrBattery = &battery;
  Ble ble;
  ble.setup("Viril");
  BleBattery bleBattery;
  bleBattery.init(&battery, &ble);
  Serial.println("Cpu Mhz: " + String(ESP.getCpuFreqMHz()));
  Serial.println("Free Heap: " + String(ESP.getFreeHeap()));
  Serial.println("Cpu Cycle count: " + String(ESP.getCycleCount()));
  Serial.print("Temperature: ");
  Serial.print((temprature_sens_read() - 32) / 1.8);
  Serial.println(" C");
}
void loop()
{

  //Serial.println(digitalRead(FIREBUTTON));
  lastButtonState = fireButton.clicks;
  fireButton.Update();

  if(fireButton.clicks == 5) true;//lock();

  // slow blink (must hold down button. 1 second long blinks)
  if(fireButton.clicks == -1) {vape_state = true; vape.start();}

  //if(fireButton.clicks == 0 && !digitalRead(FIREBUTTON)) longPressCallback();
  if(digitalRead(FIREBUTTON) && vape_state) {vape_state = false; vape.stop();}
}

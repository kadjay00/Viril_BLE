#include <Arduino.h>
#include <WiFi.h>

#include "Cell/Cell.h"
#include "Battery/Battery.h"
#include "Power/Power.h"
#include "Mosfet/Mosfet.h"
#include "Ble/Ble.h"

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

bool vape_hold  = false;
bool vape_state = false;
// the Button
const int buttonPin1 = 4;
ClickButton fireButton(FIREBUTTON, LOW, CLICKBTN_PULLUP);
int lastButtonState;

//declare battery cell pin array
uint8_t cells[] = {1,2,null};

Battery battery;
Mosfet mosfet;
Power power;
Ble ble;


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
  battery.setup(cells, 5);
  battery.setPercentage(40);
  power.init(&battery);
  mosfet.init(&power);
  mosfet.setup(MOSFET);

  Ble ble;
  ble.setup("Viril");

  // BleBattery bleBattery;
  // bleBattery.init(&battery, &ble);
  // bleBattery.setup();
  //

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
  if(fireButton.clicks == -1)
    {vape_state = true; mosfet.start();}

  //if(fireButton.clicks == 0 && !digitalRead(FIREBUTTON)) longPressCallback();
  if(digitalRead(FIREBUTTON) && vape_state)
    {vape_state = false; mosfet.stop();}


}

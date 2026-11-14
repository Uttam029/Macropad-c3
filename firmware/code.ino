/**
 * Custom Bluetooth MacroPad Firmware
 * ESP32-C3 Wireless BLE Keyboard with Rotary Encoder & OLED UI
 *
 * @file code.ino
 */
#include "functions.h"
#include <esp_sleep.h>

RTC_DATA_ATTR unsigned long lastActiveTime; 

void setup() {
  functions::initKeyPad();
  Serial.begin(115200);

  esp_sleep_wakeup_cause_t wakeupReason = esp_sleep_get_wakeup_cause(); 
  if(wakeupReason == ESP_SLEEP_WAKEUP_EXT1) Serial.println("MacroPad: Woke up from sleep!");
  else Serial.println("MacroPad: Initialized.");

  esp_deep_sleep_enable_gpio_wakeup(BIT(D3), ESP_GPIO_WAKEUP_GPIO_LOW);
  lastActiveTime = millis();
}

void loop() {
  if(digitalRead(col_2) == LOW)   functions::checkKeyPad(col_1);
  if(digitalRead(col_1) == LOW)   functions::checkKeyPad(col_2);
  functions::scroll();

  if(isAnythingPressed) {
    lastActiveTime = millis();
    isAnythingPressed = false;
  } 
  if(millis() - lastActiveTime > sleep_timeout) {
    screen::clear();
    esp_deep_sleep_start(); 
  }
}

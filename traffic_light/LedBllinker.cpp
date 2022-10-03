#include <Arduino.h>
#include "LedBlinker.h"

LedBlinker::LedBlinker() {
  this->led = new Led();
  this->delay = 1000;
  this->isDefaultOn = false;
}

LedBlinker::LedBlinker(Led *led, unsigned long delay, bool defaultOn) {
  this->led = led;
  this->delay = delay;
  this->isDefaultOn = defaultOn;
}

void LedBlinker::init() {
  led->init();
  if(isDefaultOn)
    led->on();
  else
    led->off();
}

void LedBlinker::start() {
  if(!amBlinking) {
    amBlinking = true;
    if(isDefaultOn)
      led->on();
    else
      led->off();
    lastToggleTime = millis();
  }
}

void LedBlinker::update() {
  if(amBlinking) {
    unsigned long currTime = millis();
    if(currTime - lastToggleTime >= delay) {
      led->toggle();
      lastToggleTime = currTime;
    }
  }
}

void LedBlinker::pause() {
  amBlinking = false;
}

void LedBlinker::resume() {
  amBlinking = true;
}

void LedBlinker::stop() {
  amBlinking = false;
  led->off();
}

bool LedBlinker::isBlinking() {
  return amBlinking;
}

unsigned long LedBlinker::getDelay(){
  return delay;
}

void LedBlinker::setDelay(unsigned long delay) {
  this->delay = delay;
}

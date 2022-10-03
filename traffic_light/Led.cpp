#include <Arduino.h>
#include "Led.h"

Led::Led() {
  this->pin = LED_BUILTIN;
}

Led::Led(byte pin) {
  this->pin = pin;
}

void Led::init() {
  pinMode(pin, OUTPUT);
}

void Led::init(bool defaultOn) {
  init();
  if(defaultOn)
    on();
  else
    off();
}

void Led::on() {
  byte value = brightness * 255.0 / 100.0;
  analogWrite(pin, value);
  amOn = true;
}

void Led::off() {
  analogWrite(pin, LOW);
  amOn = false;
}

void Led::toggle() {
  if(amOn)
    off();
  else
    on();
}

void Led::setBrightness(byte percentage) {
  brightness = (percentage > 100 ? 100 : percentage);
}

byte Led::getBrightness() {
  return brightness;
}

bool Led::isOn() {
  return amOn;
}
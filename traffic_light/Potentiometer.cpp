#include <Arduino.h>
#include "Potentiometer.h"

Potentiometer::Potentiometer() {
  this->pin = A0;
}

Potentiometer::Potentiometer(byte pin) {
  this->pin = pin;
}

void Potentiometer::init() {
  pinMode(pin, INPUT);
}

int Potentiometer::getValue() {
  return analogRead(pin);
}

byte Potentiometer::getPercentage() {
  return getValue() * 100.0 / 1023.0;
}

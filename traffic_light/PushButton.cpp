#include <Arduino.h>
#include "PushButton.h"

PushButton::PushButton() {
  this->pin = 12;
  this->pullMode = PushButtonPullMode::INTERNAL_PULL_UP;
}

PushButton::PushButton(byte pin, PushButtonPullMode pullMode) {
  this->pin = pin;
  this->pullMode = pullMode;
}

void PushButton::init() {
  if(pullMode == PushButtonPullMode::INTERNAL_PULL_UP)
    pinMode(pin, INPUT_PULLUP);
  else
    pinMode(pin, INPUT);
}

bool PushButton::isPressed() {
  return digitalRead(pin) == (pullMode == PushButtonPullMode::EXTERNAL_PULL_DOWN ? HIGH : LOW);
}

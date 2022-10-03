#include <Arduino.h>
#include "TrafficLight.h"

TrafficLight::TrafficLight() {
  // Do not use this!
}

TrafficLight::TrafficLight(Led *redLed, Led *yellowLed, Led *greenLed, LedBlinker *greenLedBlinker, PushButton *button, Potentiometer *pot) {
  this->redLed = redLed;
  this->yellowLed = yellowLed;
  this->greenLed = greenLed;
  this->greenLedBlinker = greenLedBlinker;
  this->button = button;
  this->pot = pot;
}

void TrafficLight::init() {
  redLed->init();
  yellowLed->init();
  greenLedBlinker->init();
  button->init();
  pot->init();
  allLightsOff();
}

void TrafficLight::setBrightness() {
  byte brightness = pot->getPercentage();
  redLed->setBrightness(brightness);
  yellowLed->setBrightness(brightness);
  greenLed->setBrightness(brightness);
}

void TrafficLight::red() {
  redLed->on();
  yellowLed->off();
  greenLed->off();
}

void TrafficLight::yellow() {
  redLed->off();
  yellowLed->on();
  greenLed->off();
}

void TrafficLight::green() {
  redLed->off();
  yellowLed->off();
  greenLed->on();
}

void TrafficLight::allLightsOff() {
  redLed->off();
  yellowLed->off();
  greenLed->off();
}

void TrafficLight::changeStateTo(States newState) {
  state = newState;
  currentStateStart = millis();
}

bool TrafficLight::isTimeToChange(unsigned long duration) {
  return millis() - currentStateStart >= duration;
}


void TrafficLight::update() {
  setBrightness();
  switch(state) {
    case RED_LIGHT:
      red();
      if(button->isPressed())
        changeStateTo(YELLOW_LIGHT);
      break;

    case YELLOW_LIGHT:
      yellow();
      if(isTimeToChange(yellowDuration))
        changeStateTo(GREEN_LIGHT);
      break;

    case GREEN_LIGHT:
      green();
      if(isTimeToChange(greenDuration)) {
        changeStateTo(BLINKING_GREEN);
        greenLedBlinker->start();
      }
      break;

    case BLINKING_GREEN:
      if(isTimeToChange(blinkingGreenDuration)) {
        greenLedBlinker->stop();
        changeStateTo(RED_LIGHT);
      }
      else
        greenLedBlinker->update();
      break;

    default:
      changeStateTo(RED_LIGHT);
      break;
  }
}


unsigned long TrafficLight::getYellowDuration() {
  return yellowDuration;
}

void TrafficLight::setYellowDuration(unsigned long duration) {
  yellowDuration = duration;
}

unsigned long TrafficLight::getGreenDuration() {
  return greenDuration;
}

void TrafficLight::setGreenDuration(unsigned long duration) {
  greenDuration = duration;
}

unsigned long TrafficLight::getBlinkingGreenDuration() {
  return blinkingGreenDuration; 
}

void TrafficLight::setBlinkingGreenDuration(unsigned long duration) {
  blinkingGreenDuration = duration;
}
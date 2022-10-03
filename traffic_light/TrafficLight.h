#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "Led.h"
#include "LedBlinker.h"
#include "PushButton.h"
#include "Potentiometer.h"

class TrafficLight {
private:
  Led *redLed;
  Led *yellowLed;
  Led *greenLed;
  LedBlinker *greenLedBlinker;
  PushButton *button;
  Potentiometer *pot;

  enum States {
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT,
    BLINKING_GREEN
  } state;

  unsigned long currentStateStart;

  unsigned long yellowDuration = 3000;
  unsigned long greenDuration = 5000;
  unsigned long blinkingGreenDuration = 3000;

  void setBrightness();
  void changeStateTo(States newState);
  bool isTimeToChange(unsigned long duration);

public:
  TrafficLight();
  TrafficLight(Led *redLed, Led *yellowLed, Led *greenLed, LedBlinker *greenLedBlinker, PushButton *button, Potentiometer *pot);

  void init();

  void red();
  void yellow();
  void green();
  void allLightsOff();

  void update();

  unsigned long getYellowDuration();
  void setYellowDuration(unsigned long duration);
  
  unsigned long getGreenDuration();
  void setGreenDuration(unsigned long duration);

  unsigned long getBlinkingGreenDuration();
  void setBlinkingGreenDuration(unsigned long duration);
};

#endif
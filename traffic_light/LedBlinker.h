#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include "Led.h"

class LedBlinker {

private:
  Led *led;
  bool amBlinking;
  bool isDefaultOn;
  unsigned long delay;
  unsigned long lastToggleTime;

public:
  LedBlinker();
  LedBlinker(Led *led, unsigned long delay, bool defaultOn);

  void init();

  void start();
  void update();
  void pause();
  void resume();
  void stop();

  bool isBlinking();

  unsigned long getDelay();
  void setDelay(unsigned long delay);
};

#endif
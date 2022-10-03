#ifndef LED_H
#define LED_H

class Led {
private:
  byte pin;
  byte brightness = 100; // 0-100%
  bool amOn;

public:
  Led();
  Led(byte pin);

  void init();
  void init(bool defaultOn);

  void on();
  void off();
  void toggle();

  void setBrightness(byte percentage);
  byte getBrightness();
  bool isOn();
};

#endif
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer {
private:
  byte pin;

public:
  Potentiometer();
  Potentiometer(byte pin);

  void init();

  int getValue();
  byte getPercentage();
};

#endif
#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

enum PushButtonPullMode {
  INTERNAL_PULL_UP,
  EXTERNAL_PULL_UP,
  EXTERNAL_PULL_DOWN
};

class PushButton {
private:
  byte pin;
  PushButtonPullMode pullMode;

public:

  PushButton();
  PushButton(byte pin, PushButtonPullMode pullMode);

  void init();

  bool isPressed();
};

#endif
#include "Led.h"
#include "LedBlinker.h"
#include "PushButton.h"
#include "Potentiometer.h"
#include "TrafficLight.h"

#define RED_LED_PIN 9
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 11
#define BUTTON_PIN 12
#define POTENTIOMETER_PIN A0

Led *redLed = new Led(RED_LED_PIN);
Led *yellowLed = new Led(YELLOW_LED_PIN);
Led *greenLed = new Led(GREEN_LED_PIN);

LedBlinker *greenLedBlinker = new LedBlinker(greenLed, 500, false);

PushButton *button = new PushButton(BUTTON_PIN, PushButtonPullMode::INTERNAL_PULL_UP);

Potentiometer *pot = new Potentiometer(POTENTIOMETER_PIN);

TrafficLight *trafficLight = new TrafficLight(redLed, yellowLed, greenLed, greenLedBlinker, button, pot);


void setup() {
  trafficLight->init();
}


void loop() {
  trafficLight->update();
}
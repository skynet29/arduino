#include "led.h"

void timer_onInterval(Led* led) {
  led->toggle();
}

Led::Led(int pinNumber) {
  this->pinNumber = pinNumber;
}

void Led::setup() {
  Serial.println("Led::setup");
  pinMode(pinNumber, OUTPUT);
}

void Led::on() {
  digitalWrite(pinNumber, HIGH);
}

void Led::off(bool stopBlink) {
  digitalWrite(pinNumber, LOW);
  if (stopBlink) {
    timer.stop();
  }
}

void Led::blink(long delay_ms) {
  timer.start(delay_ms, timer_onInterval, this);
}


void Led::toggle() {
  if (isOn()) {
    off(false);
  }
  else {
    on();
  }
}

bool Led::isOn() {
  return (digitalRead(pinNumber) == HIGH);
}

bool Led::isBlinking() {
  return timer.isStarted();
}


#include "pushbutton.h"

PushButton::PushButton(int pinNumber) {
  this->pinNumber = pinNumber;
  this->onPress = NULL;
  this->onRelease = NULL;
  this->state = LOW;
}

void PushButton::setOnPress(EventCallback onPress) {
  this->onPress = onPress;
}

void PushButton::setOnRelease(EventCallback onRelease) {
  this->onRelease = onRelease;
}


void PushButton::setup() {
  Serial.println("PushButton::setup");
  
  pinMode(pinNumber, INPUT);
}

void PushButton::loop() {
  if (digitalRead(pinNumber) == HIGH && state == LOW) {
    state = HIGH;
    if (onPress != NULL) {
      onPress(NULL);
    }
  }
  if (digitalRead(pinNumber) == LOW && state == HIGH) {
    state = LOW;
    if (onRelease != NULL) {
      onRelease(NULL);
    }
  }  
}


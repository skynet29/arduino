#include "timer.h"

Timer::Timer() {
  started = false;
}

void Timer::start(long delay_ms, EventCallback onInterval, void* evtArg) {
  this->delay_ms = delay_ms;
  this->onInterval = onInterval;
  this->evtArg = evtArg;
  this->started = true;
  this->timeout = millis() + delay_ms;
  
}

void Timer::stop() {
  started = false;
}

bool Timer::isStarted() {
  return started;
}

void Timer::loop() {
  if (!started) {
    return;
  }

  long now = millis();
  if (now >= timeout) {
    timeout = now + delay_ms;
    if (onInterval != NULL) {
      onInterval(evtArg);
    }
  }
}


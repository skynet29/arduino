#ifndef LED_H
#define LED_H

#include "timer.h"

class Led : public Device {
public:  
  Led(int pinNumber);

  void setup();

  void on();
  void off(bool stopBlink = true);
  void toggle();
  void blink(long delay_ms);
  
  bool isOn();
  bool isBlinking();
  
private:
  int pinNumber;
  Timer timer;
};

#endif

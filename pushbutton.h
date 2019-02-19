#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "device.h"

class PushButton : public Device {
public:
  PushButton(int pinNumber);

  void setup();
  void loop();

  void setOnPress(EventCallback onPress);
  void setOnRelease(EventCallback onRelease);
private:
  EventCallback onPress;
  EventCallback onRelease;
  int pinNumber;
  int state;  
};

#endif

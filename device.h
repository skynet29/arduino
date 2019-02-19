#ifndef DEVICE_H
#define DEVICE_H

#include "Arduino.h"

typedef void (*EventCallback)(void*);

class Device {
public:
  Device();
  virtual void loop() {}
  virtual void setup() {}
private:
  Device* next;    
  
  friend class DeviceManager;
};

class DeviceManager {
public:
  static void loop();  
  static void setup();  
};

#endif

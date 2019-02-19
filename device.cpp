#include "device.h"


static Device* first = NULL;

Device::Device() {
  next = first;
  first = this;
}

void DeviceManager::loop() {
  for(Device* p = first; p != NULL; p = p->next) {
    p->loop();
  }
}

void DeviceManager::setup() {
  for(Device* p = first; p != NULL; p = p->next) {
    p->setup();
  }
}
 


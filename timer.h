#ifndef TIMER_H
#define TIMER_H

#include "device.h"

class Timer : public Device {
public:
  Timer();
  void start(long delay_ms, EventCallback onInterval, void* evtArg = NULL);
  void stop();
  bool isStarted();

  void loop();
private:
   EventCallback onInterval;
   void* evtArg;   
   bool started;
   long timeout;
   long delay_ms;
};

#endif


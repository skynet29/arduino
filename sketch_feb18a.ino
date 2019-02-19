#include "pushbutton.h"
#include "led.h"

PushButton push1(2);
Led led1(13);



void push1_onPress() {
  Serial.println("onPress");
  if (led1.isBlinking()) {
    led1.off();
  }
  else {
    led1.blink(1000);    
  }
}

void push1_onRelease() {
  Serial.println("onRelease");
  //led1.off();
}


void setup() {
   Serial.begin(9600);
  // put your setup code here, to run once:
  DeviceManager::setup();

  push1.setOnPress(push1_onPress);
  push1.setOnRelease(push1_onRelease);

}

void loop() {
  // put your main code here, to run repeatedly:
  DeviceManager::loop();

}

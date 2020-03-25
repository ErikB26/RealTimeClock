#include  <Wire.h> 

void setup() {
  lcdSetup();
  rtcSetup();  
}

void loop() {
  lcdPrint(rtcGetDate(), rtcGetTime());
}

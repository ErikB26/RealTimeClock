#include  <Wire.h> 

const int INTERVAL = 6000;
unsigned long timer = 0;
boolean showDate = false;

void setup() {
  lcdSetup();
  rtcSetup();  
}

void loop() {
  if (timerIsPassed(timer, INTERVAL)) {
    timer = timeReset();
    lcdClear();
    showDate = !showDate;
  }
  
  lcdPrint((showDate) ? rtcGetDate() : rtcGetWeekday(), rtcGetTime());
}

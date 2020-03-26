boolean timerIsPassed(unsigned long timer, int interval) {
  if (millis() - timer >= interval) {
    return true;
  } else {
    return false;
  }
}

unsigned long timeReset() {
  return millis();
}

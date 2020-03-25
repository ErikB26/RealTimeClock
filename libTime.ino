boolean timerIsPassed(unsigned long timer, unsigned long interval) {
  if (millis() - timer >= interval) {
    return true;
  } else {
    return false;
  }
}

unsigned long timeReset() {
  return millis();
}

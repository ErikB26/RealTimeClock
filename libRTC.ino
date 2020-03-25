#include "RTClib.h"

RTC_DS1307 rtc;

const String DAY[7] = {"Zondag", "Maandag", "Dinsdag", "Woensdag", "Donderdag", "Vrijdag", "Zaterdag"};

unsigned long timer = 0;
const int INTERVAL = 6000;

int showDate = false;

/**
 * If the RTC is not running, set the current date and time so it will start counting.
 */
void rtcSetup() {
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

/**
 * Return either the current weekday or the current date.
 * 
 * @return String
 */
String rtcGetDate() {
  if (timerIsPassed(timer, INTERVAL)) {
    timer = timeReset();
    lcd.clear();
    showDate = !showDate;
  }

  if (showDate) {
    return getDate();
  } else {
    return getWeekday();
  }
}

/**
 * Get the current time from the RTC.
 * 
 * @return String
 */
String rtcGetTime() {
  DateTime now = rtc.now();

  String hourFormatted = (int(now.hour()) < 10) ? "0" + String(now.hour()) : String(now.hour());
  String minuteFormatted = (int(now.minute()) < 10) ? "0" + String(now.minute()) : String(now.minute());
  String secondFormatted = (int(now.second()) < 10) ? "0" + String(now.second()) : String(now.second());

  return hourFormatted + ":" + minuteFormatted + ":" + secondFormatted;
}

/**
 * Get the current weekday.
 * 
 * @return String
 */
String getWeekday() {
  DateTime now = rtc.now();
  return DAY[now.dayOfTheWeek()];
}

/**
 * Get the current date from the RTC.
 * 
 * @return String
 */
String getDate() {
  DateTime now = rtc.now();
  String day = (int(now.day()) < 10) ? "0" + String(now.day()) : String(now.day());;
  String month = (int(now.month()) < 10) ? "0" + String(now.month()) : String(now.month());
  String year = String(now.year());
  return day + "-" + month + "-" + year;
}

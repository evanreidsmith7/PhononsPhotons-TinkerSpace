#include <Arduino.h>
#include "alert_manager.h"
bool alarmIsMuted = false;

void toggleAlarm()
{
  alarmIsMuted = !alarmIsMuted;
  Serial.println(alarmIsMuted ? "Alarm On" : "Alarm Off");
}
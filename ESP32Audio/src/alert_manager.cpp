#include <Arduino.h>
#include "alert_manager.h"
volatile bool alarmIsMuted = true;
int minInputFreq = 15000;  // Minimum input frequency
int maxInputFreq = 120000; // Maximum input frequency
int minBuzzerFreq = 300;   // Minimum frequency the buzzer can handle
int maxBuzzerFreq = 6700;  // Maximum frequency the buzzer can handle
int alarmFreq = 0;
int alarmTime = 0;

void toggleAlarm()
{
   alarmIsMuted = !alarmIsMuted;
   Serial.println(alarmIsMuted ? "Alarm Off" : "Alarm On");
}
void setTone(int freq, int magnitude)
{
   Serial.println("in set tone");
   alarmIsMuted = false;
   alarmFreq = freq;
   alarmTime = magnitude;
   // implement freq and mag mapping
   Serial.println("out set tone");
}

void playToneTask()
{
   if (!alarmIsMuted)
   {
      Serial.print("Playing: ");
      // Play the tone on the buzzer
      if (alarmFreq >= minBuzzerFreq && alarmFreq <= maxBuzzerFreq)
      {
         tone(BUZZER_PIN, alarmFreq, alarmTime);
         noTone(BUZZER_PIN);
      }
   }
}
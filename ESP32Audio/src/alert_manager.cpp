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
   Serial.println(alarmIsMuted ? "Alarm On" : "Alarm Off");
}
void setTone(int freq, int magnitude)
{
   Serial.print("in set tone");
   alarmIsMuted = false;
   alarmFreq = freq;
   alarmTime = magnitude;
   // implement freq and mag mapping
   Serial.print("out set tone");
}

void playToneTask(void *parameter)
{
   while (true)
   {
      if (!alarmIsMuted)
      {
         Serial.print("Playing: ");
         // Play the tone on the buzzer
         if (alarmFreq >= minBuzzerFreq && alarmFreq <= maxBuzzerFreq)
         {
            Serial.print("Playing frequency: ");
            Serial.print(alarmFreq);
            Serial.print(" Hz, Magnitude: ");
            Serial.print(alarmTime);
            Serial.println(" ms");
            tone(BUZZER_PIN, alarmFreq);
            delay(alarmTime);
            noTone(BUZZER_PIN);
         }
         vTaskDelay(1); // Delay for 1 tick
      }
   }
}
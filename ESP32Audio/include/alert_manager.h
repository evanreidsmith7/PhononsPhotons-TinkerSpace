#pragma once
#define BUZZER_PIN 14

extern volatile bool alarmIsMuted;
extern int minInputFreq;   // Minimum input frequency
extern int maxInputFreq;  // Maximum input frequency
extern int minBuzzerFreq;    // Minimum frequency the buzzer can handle
extern int maxBuzzerFreq;   // Maximum frequency the buzzer can handle
extern int alarmFreq;
extern int alarmTime;
void toggleAlarmOff();
void toggleAlarmOn();
void setTone(int freq, int magnitude);
void playToneTask();
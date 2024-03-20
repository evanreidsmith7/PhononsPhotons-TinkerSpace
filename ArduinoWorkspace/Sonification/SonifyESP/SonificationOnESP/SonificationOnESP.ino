#include <HardwareSerial.h>
int buzzerPin = 14; // Pin connected to the buzzer
int switchPin = 4;  // Pin connected to the button
int minInputFreq = 17000; // Minimum input frequency
int maxInputFreq = 30000; // Maximum input frequency
int minBuzzerFreq = 300; // Minimum frequency the buzzer can handle
int maxBuzzerFreq = 1500; // Maximum frequency the buzzer can handle

#define ESPport Serial2 // Use Serial2 for ESP32-WROOM, adjust based on your ESP32-WROOM's UART pins

bool alarmActive = false;  // Flag to track if the alarm is active

//TODO: esp32 alarm and sonification of frequencies
//TODO: strength of signal
//set esp port, replace serial with esp32 to get freq from esp32
void setup() 
{
  Serial.begin(115200);
  //ESPport.begin(115200);
  //Serial1.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLDOWN);  // Set button pin as input with internal pull-up resistor
  while(Serial.available()) {Serial.read();}  //clear the serial buffer
  //while(ESPport.available()) {ESPport.read();} 
  //while(Serial1.available()) {Serial1.read();}  //clear the serial buffer for esp recieve
}
int freq = 0;
void loop() {

  // Check if the button is pressed to stop the alarm
  if (digitalRead(buzzerPin) == HIGH && alarmActive) {
    noTone(buzzerPin);  // Stop the buzzer
    alarmActive = false;  // Reset the alarm flag
  }

  //if (ESPport.available() > 0)
  if (Serial.available() > 0)
  {
    // Read the incoming message
   // int freq = ESPport.parseInt();
    int freq = Serial.parseInt();
    // the frequency that contained the highest magnitude in the fft data transfered
    // downscaling to an audible range is done with map
    //also making sure frequencies under and over a certain range don't function
    
      // Scale the frequency proportionately
      if (freq >= minInputFreq && freq <= maxInputFreq) {
        freq = map(freq, minInputFreq, maxInputFreq, minBuzzerFreq, maxBuzzerFreq);

        //Play the tone on the buzzer
        if (freq >= minBuzzerFreq && freq <= maxBuzzerFreq) {

        // Set the alarm flag
        alarmActive = true;

          // Play the tone on the buzzer three times
          for (int i = 0; i < 3; i++) {
            tone(buzzerPin, freq);
            delay(1000); // Adjust the delay to the frequency
            noTone(buzzerPin); // Stop the tone
            delay(1000); // Wait half of the frequency duration before playing the next tone

        while(Serial.available()) {Serial.read();}  //clear the serial buffer

        }
      }
    }
  }
}

// include magnitude of signal
// voice silences after detection event

/* 
  tone();
  Signal Input/Output
  A software digital square wave tone generation library.
  This is a Wiring Framework (Arduino) library to produce square-wave tones on an arbitrary pin. You can make multiple instances of the Tone object, to create tones on different pins. 
*/
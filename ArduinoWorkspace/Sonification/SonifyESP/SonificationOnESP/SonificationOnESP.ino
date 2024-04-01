#include <HardwareSerial.h>

int buzzerPin = 14;         // Pin connected to the buzzer
int minInputFreq = 15000;   // Minimum input frequency
int maxInputFreq = 120000;  // Maximum input frequency
int minBuzzerFreq = 300;    // Minimum frequency the buzzer can handle
int maxBuzzerFreq = 6700;   // Maximum frequency the buzzer can handle

#define ESPport Serial2    // Use Serial2 for ESP32-WROOM, adjust based on your ESP32-WROOM's UART pins

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);

  while (Serial.available()) { 
    Serial.read();  // Clear the serial buffer
  }
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the incoming message

    if (input == "mute") {
      noTone(buzzerPin); // Stop playing the tone
      Serial.println("MUTE received. Buzzer muted.");
    } else {
      // Parse frequency and magnitude values from the input string
      int delimiterIndex = input.indexOf(',');
      if (delimiterIndex != -1 && delimiterIndex < input.length() - 1) {
        String freqString = input.substring(0, delimiterIndex);
        String magnitudeString = input.substring(delimiterIndex + 1);

        int freq = freqString.toInt(); // Convert the frequency string to integer
        int magnitude = magnitudeString.toInt(); // Convert the magnitude string to integer

        // Check if the frequency and magnitude are within valid ranges
        if (freq >= minInputFreq && freq <= maxInputFreq && magnitude >= 0) {
          freq = map(freq, minInputFreq, maxInputFreq, minBuzzerFreq, maxBuzzerFreq);

          // Map frequency for display
          int displayFreq = map(freq, minBuzzerFreq, maxBuzzerFreq, minInputFreq, maxInputFreq);

          // Calculate delay based on magnitude of signal
          int delayTime = map(magnitude, 0, 150, 1000, 100); // Assuming magnitude ranges from 0 to 200 dB

          // Play the tone on the buzzer
          if (freq >= minBuzzerFreq && freq <= maxBuzzerFreq) {
            Serial.print("Playing frequency: ");
            Serial.print(displayFreq);
            Serial.print(" Hz is ");
            Serial.print(freq);
            Serial.print(" Hz, Magnitude: ");
            Serial.print(magnitude);
            Serial.println(" dB");
            
            // Use a while loop to continuously play the tone
            boolean stopTone = false;
            while (!stopTone) {
              tone(buzzerPin, freq);
              delay(delayTime); // Adjust the delay based on signal magnitude
              noTone(buzzerPin);
              delay(delayTime); 
              // Check if there's any incoming message
              if (Serial.available() > 0) {
                String incoming = Serial.readStringUntil('\n');
                if (incoming == "mute") {
                  stopTone = true; // Set stopTone to true to exit the while loop
                  noTone(buzzerPin); // Stop playing the tone
                  Serial.println("MUTE received. Buzzer muted.");
                }
              }
            }
          }
        }
      }
    }
  }
}


int buzzerPin = 14; // Pin connected to the buzzer
int minInputFreq = 17000; // Minimum input frequency
int maxInputFreq = 27000; // Maximum input frequency
int minBuzzerFreq = 200; // Minimum frequency the buzzer can handle
int maxBuzzerFreq = 1200; // Maximum frequency the buzzer can handle

//TODO: adapt this for esp32
void setup() 
{
  Serial.begin(115200);
  //Serial1.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  while(Serial.available()) {Serial.read();}  //clear the serial buffer
  //while(Serial1.available()) {Serial1.read();}  //clear the serial buffer for esp recieve
}
int freq = 0;
void loop() 
{
  if (Serial.available() > 0)
  {
    // Read the incoming message
    int freq = Serial.parseInt();
    // the frequency that contained the highest magnitude in the fft data is downscaled by 
    // i forget the downscale then sent over uart and recieved above^
    
      // Scale the frequency proportionately
      if (freq >= minInputFreq && freq <= maxInputFreq) {
        freq = map(freq, minInputFreq, maxInputFreq, minBuzzerFreq, maxBuzzerFreq);

        //Play the tone on the buzzer
        if (freq >= minBuzzerFreq && freq <= maxBuzzerFreq) {

          // Play the tone on the buzzer three times
          for (int i = 0; i < 3; i++) {
            tone(buzzerPin, freq);
            delay(freq); // Adjust the delay to the frequency
            noTone(buzzerPin); // Stop the tone
            delay(freq / 2); // Wait half of the frequency duration before playing the next tone

        while(Serial.available()) {Serial.read();}  //clear the serial buffer

        }
      }
    }
  }
}

  
/* OG
  if (Serial1.available() > 0)
  {
    // Read the incoming message
    int freq = Serial1.parseInt();
    // the frequency that contained the highest magnitude in the fft data is downscaled by 
    // i forget the downscale then sent over uart and recieved above^
    
    //Play the tone on the buzzer
    tone(buzzerPin, freq);
    delay(1000); // You can adjust the duration of the tone
    noTone(buzzerPin); // Stop the tone

    while(Serial1.available()) {Serial1.read();}  //clear the serial buffer
  }
*/
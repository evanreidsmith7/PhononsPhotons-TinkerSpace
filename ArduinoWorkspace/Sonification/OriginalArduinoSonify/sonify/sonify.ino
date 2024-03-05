int buzzerPin = 9; // Pin connected to the buzzer

void setup() 
{
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  while(Serial.available()) {Serial.read();}  //clear the serial buffer
  while(Serial1.available()) {Serial1.read();}  //clear the serial buffer
}
int freq = 0;
void loop() 
{
  if (Serial1.available() > 0)
  {
    // Read the incoming message
    int freq = Serial1.parseInt();
    Serial.println(freq);
    //Play the tone on the buzzer
    tone(buzzerPin, freq);
    delay(1000); // You can adjust the duration of the tone
    noTone(buzzerPin); // Stop the tone

    while(Serial1.available()) {Serial1.read();}  //clear the serial buffer
  }
}

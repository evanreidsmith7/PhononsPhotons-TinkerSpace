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
    //Play the tone on the buzzer
    //tone(buzzerPin, 15000);
    delay(500); // You can adjust the duration of the tone
    noTone(buzzerPin); // Stop the tone
    delay(1000);

}

#include <Arduino.h>

// put function declarations here:
void sendSerial2();
void recieveSerial2();

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, World!");
  //Serial2.begin(115200, SERIAL_8N1); // RX, TX
  Serial2.begin(115200); // RX, TX
  while (Serial.available() > 0){Serial.read();}
  while (Serial2.available() > 0){Serial2.read();}
}

void loop() 
{
  if (Serial2.available()) 
  {
    String receivedMsg = Serial2.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(receivedMsg);
  }
}

void sendSerial2()
{
  Serial2.print("Hi from ESP32\n");
  Serial.println("Message sent");
  Serial.println("\n\n\n");
}
void recieveSerial2()
{
  while (Serial2.available() <= 0)
  {
    if (Serial2.available() > 0)
    {
      Serial.println("Data available");
      String input = Serial2.readStringUntil('\r');
      input.trim();
      Serial.println(input);
      Serial.println("\n\n\n\n\n\n");
      while (Serial2.available() > 0){Serial2.read();}
      

    }
  }
}
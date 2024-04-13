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
    receivedMsg.trim();
    Serial.print("Received: ");
    Serial.println(receivedMsg);
    // tests
    if (receivedMsg == "toggle")
    {
      Serial.println("receivedMsg == toggle");
    }
    else if (receivedMsg == "tAlarm")
    {
      Serial.println("receivedMsg == tAlarm");
    }
    else if (receivedMsg == "alarm")
    {
      Serial.println("receivedMsg == alarm");
    }
    else
    {
      Serial.println("input not recognized");
    }
  }
}
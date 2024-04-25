#include <Arduino.h>
#include "websocket_client.h"
#include "i2s_manager.h"
#include "alert_manager.h"

const char *ssid = "schmittttty";
const char *password = "12345678";

const char *websocket_server_host = "192.168.137.1"; // powershell: ipconfig, see wireless lan adapter wifi IPv4 Address. . . . . . . . . . . : 10.218.151.104
const uint16_t websocket_server_port = 8888;         // <WEBSOCKET_SERVER_PORT>

void setup()
{
  Serial.begin(115200);
  // TODO: ADD SERIAL2 and test with another mcu
  Serial2.begin(115200); // RX, TX
  connectWiFi(ssid, password);
  connectWSServer(websocket_server_host, websocket_server_port);
  xTaskCreatePinnedToCore(micTask, "micTask", 10000, NULL, 1, NULL, 1);

  // clear the serial buffer
  while (Serial.available())
  {
    Serial.read();
  }
  while (Serial2.available())
  {
    Serial2.read();
  }
}

void loop()
{
  if (Serial2.available() > 0)
  {
    String input = Serial2.readStringUntil('\n');
    input.trim();
    Serial.println(input);

    if (input.startsWith("vMute") && (!isMuted)) // if not muted, need to mute, else, its already muted
    {
      toggleMuteOn();
    }
    else if (input.startsWith("vUnMute") && (isMuted)) // if muted, need to unmute, else, its already unmuted
    {
      toggleMuteOff();
    }
    else if (input.startsWith("!alarm") && (!alarmIsMuted))
    {
      toggleAlarmOff();
    }
    else if (input.startsWith("alarm"))
    { // get freq and magnitude from mesage: "<freq>, <magnitude>"
      String data = input.substring(input.indexOf(':') + 1);
      data.trim(); // Now data should be "20000, 4"

      // Split the string by comma to isolate frequency and magnitude
      int commaIndex = data.indexOf(',');
      if (commaIndex != -1)
      {
        String freqString = data.substring(0, commaIndex);
        String magnitudeString = data.substring(commaIndex + 1);
        freqString.trim();
        magnitudeString.trim();

        int freq = freqString.toInt();
        int magnitude = magnitudeString.toInt();

        Serial.print("freq, mag recieved = ");
        Serial.print(freq);
        Serial.print(", ");
        Serial.println(magnitude);

        setTone(freq, magnitude);
      }
    }
    else
    {
      Serial.println("input not recognized");
    }
  }
  playToneTask();
  checkVoiceMute();
}
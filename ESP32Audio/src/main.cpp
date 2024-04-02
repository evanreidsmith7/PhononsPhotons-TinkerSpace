#include <Arduino.h>
#include "websocket_client.h"
#include "i2s_manager.h"
#include "alert_manager.h"

const char *ssid = "schmittttty";
const char *password = "12345678";

const char *websocket_server_host = "10.218.151.104"; // see wireless lan adapter wifi IPv4 Address. . . . . . . . . . . : 10.218.151.104
const uint16_t websocket_server_port = 8888;          // <WEBSOCKET_SERVER_PORT>

void setup()
{
  Serial.begin(115200);
  //TODO: ADD SERIAL2 and test with another mcu
  Serial2.begin(115200, SERIAL_8N1); // RX, TX
  connectWiFi(ssid, password);
  connectWSServer(websocket_server_host, websocket_server_port);
  xTaskCreatePinnedToCore(micTask, "micTask", 10000, NULL, 1, NULL, 1);
  
  // clear the serial buffer
  while (Serial.available())
  {
    Serial.read();
  }
}

void loop()
{
  if (Serial2.available() > 0)
  {
    String input = Serial2.readStringUntil('\n');
    input.trim();
    Serial.println(input);

    // TODO: ADD SONIFY FUNCTIONALITY
    if (input == "toggle")
    {
      toggleMute();
    }
    else if (input == "tAlarm")
    {
      toggleAlarm();
    }
    else if (input == "alarm")
    {//get freq and magnitude from mesage: "<freq>, <magnitude>"
      String toneInput = Serial.readStringUntil('\n');
      toneInput.trim();
      int delimiterIndex = toneInput.indexOf(',');
      if (delimiterIndex != -1 && delimiterIndex < toneInput.length() - 1)
      {
        String freqString = toneInput.substring(0, delimiterIndex);
        String magnitudeString = toneInput.substring(delimiterIndex + 1);

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
//end of function input
  while (Serial.available()){Serial.read();}
  while (Serial2.available()){Serial2.read();}
  playToneTask();

  if (isMuted)
  {
    i2s_zero_dma_buffer(I2S_NUM_0);
  }
}
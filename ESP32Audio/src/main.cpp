#include <Arduino.h>
#include "websocket_client.h"
#include "i2s_manager.h"

void readSerialToggleMute();

const char *ssid = "schmittttty";
const char *password = "12345678";

const char *websocket_server_host = "10.218.151.104"; // see wireless lan adapter wifi IPv4 Address. . . . . . . . . . . : 10.218.151.104
const uint16_t websocket_server_port = 8888;          // <WEBSOCKET_SERVER_PORT>
bool isMuted = false;

void setup()
{
  Serial.begin(115200);
  connectWiFi(ssid, password);
  connectWSServer(websocket_server_host, websocket_server_port);
  xTaskCreatePinnedToCore(micTask, "micTask", 10000, NULL, 1, NULL, 1);

  //clear the serial buffer
  while (Serial.available()){Serial.read();}
}

void loop()
{
  readSerialToggleMute();
  if (isMuted)
  {
    i2s_zero_dma_buffer(I2S_NUM_0);
  }
}

void readSerialToggleMute()
{
  if (Serial.available() > 0)
  {
    String input = Serial.readStringUntil('\n');
    input.trim();
    Serial.println(input);
    while (Serial.available()){Serial.read();}

    if (input == "toggle")
    {
      isMuted = !isMuted;
      Serial.println(isMuted ? "Muted" : "Unmuted");
    }
    else
    {
      Serial.println("input not recognized");
    }
  }
}
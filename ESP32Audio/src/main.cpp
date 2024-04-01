#include <Arduino.h>
#include "websocket_client.h"
#include "i2s_manager.h"

const char *ssid = "schmittttty";
const char *password = "12345678";

const char *websocket_server_host = "10.218.151.104"; // see wireless lan adapter wifi IPv4 Address. . . . . . . . . . . : 10.218.151.104
const uint16_t websocket_server_port = 8888;          // <WEBSOCKET_SERVER_PORT>

void setup()
{
  Serial.begin(115200);
  connectWiFi(ssid, password);
  connectWSServer(websocket_server_host, websocket_server_port);
  xTaskCreatePinnedToCore(micTask, "micTask", 10000, NULL, 1, NULL, 1);
}

void loop()
{
  // TODO: add code for handling other tasks
}
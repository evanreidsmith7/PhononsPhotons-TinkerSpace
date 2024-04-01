#pragma once
#include <ArduinoWebsockets.h>
#include <WiFi.h>

using namespace websockets;
void connectWSServer(const char* websocket_server_host, uint16_t websocket_server_port);
void onEventsCallback(WebsocketsEvent event, String data);
void connectWiFi(const char* ssid, const char* password);
extern WebsocketsClient client;
extern bool isWebSocketConnected;
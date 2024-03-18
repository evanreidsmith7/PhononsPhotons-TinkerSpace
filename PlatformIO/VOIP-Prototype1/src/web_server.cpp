#include <Arduino.h>
#include "web_server.h"
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "schmittttty";
const char* password = "12345678";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setupWebServer() 
{
   // Connect to Wi-Fi
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED)
   {
      delay(1000);
      Serial.println("Connecting to WiFi...");
   }
   Serial.println("Connected to WiFi");

   // Route for root / web page
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) 
   {
      request->send(200, "text/html", "<!DOCTYPE html><html><head><title>Communication</title></head><body><h1>Communication</h1></body></html>");
   });
   // Start server
   server.begin();
}
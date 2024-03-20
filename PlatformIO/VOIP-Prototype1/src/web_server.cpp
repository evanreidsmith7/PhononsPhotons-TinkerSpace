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
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/html", R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>Communication</title>
    <script>
        document.addEventListener('DOMContentLoaded', function() {
            const playBtn = document.createElement('button');
            playBtn.textContent = 'Play Sine Wave';
            document.body.appendChild(playBtn);

            playBtn.addEventListener('click', function() {
                const audioCtx = new (window.AudioContext || window.webkitAudioContext)();
                const oscillator = audioCtx.createOscillator();
                oscillator.type = 'sine';
                oscillator.frequency.setValueAtTime(440, audioCtx.currentTime); // 440 Hz for A4
                oscillator.connect(audioCtx.destination);
                oscillator.start();
                oscillator.stop(audioCtx.currentTime + 2); // Play for 2 seconds
            });
        });
    </script>
</head>
<body>
    <h1>Communication</h1>
</body>
</html>
        )rawliteral");
    });
   // Start server
   server.begin();
}